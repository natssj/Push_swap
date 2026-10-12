*Este proyecto ha sido creado como parte del currículo de 42 por nde-dieg y marbecer.*

# push_swap

Ordena una pila de enteros usando **otra pila auxiliar** y el menor número posible de operaciones.

---

## Descripción

**push_swap** es un proyecto del currículo de 42 de algoritmia. Se dispone de dos pilas, `a` y `b`:

- `a` contiene los números recibidos como argumentos (sin duplicados).
- `b` empieza vacía.

El objetivo es ordenar `a` de menor a mayor (el menor número arriba) usando **solo** un conjunto limitado de operaciones, y que el programa imprima la lista de operaciones que lo consigue, **una por línea**. Importa tanto ordenar bien como hacerlo con **pocos movimientos**.

### Operaciones permitidas

| Operación | Efecto |
|---|---|
| `sa` / `sb` / `ss` | Intercambia los dos primeros elementos de `a` / `b` / ambas |
| `pa` | Mueve el primer elemento de `b` al tope de `a` |
| `pb` | Mueve el primer elemento de `a` al tope de `b` |
| `ra` / `rb` / `rr` | Rota hacia arriba: el primero pasa a ser el último |
| `rra` / `rrb` / `rrr` | Rota hacia abajo: el último pasa a ser el primero |

### Características

- **Cuatro estrategias** de ordenación: Simple, Medium, Complex y Adaptive.
- **Estrategia adaptativa** que elige el algoritmo según el *desorden* de la entrada.
- **Modo `--bench`**: muestra por `stderr` el desorden, la estrategia usada, el total de operaciones y el desglose por tipo.
- **Validación completa** de la entrada: no numéricos, duplicados y desbordamiento de `int` producen `Error`.
- **Sin variables globales** y sin fugas de memoria (comprobado con `valgrind`).
- Implementado con **listas doblemente enlazadas** y la `libft` propia (incluye `ft_printf`).

---

## Instrucciones

### Compilación

```bash
make          # compila libft y push_swap
make clean    # elimina los .o
make fclean   # elimina los .o, libft.a y el ejecutable
make re       # recompila desde cero
```

Se compila con `cc -Wall -Wextra -Werror`.

### Ejecución

```bash
./push_swap [estrategia] [--bench] <números...>
```

**Estrategias** (como máximo una; si no se indica ninguna se usa `--adaptive`):

| Flag | Estrategia | Complejidad |
|---|---|---|
| `--simple` | Ordenación por inserción | O(n²) |
| `--medium` | Ordenación por bloques (chunks) | O(n√n) |
| `--complex` | Radix sort | O(n log n) |
| `--adaptive` | Elige según el desorden (por defecto) | O(n) / O(n√n) / O(n log n) |

**Otras opciones:**

| Flag | Efecto |
|---|---|
| `--bench` | Muestra por `stderr` un resumen del rendimiento. No altera la salida de operaciones. |

### Ejemplos

```bash
./push_swap 3 2 1
./push_swap --complex 5 2 4 1 3
./push_swap --simple --bench 10 9 8 7 6 5 4 3 2 1
```

### Gestión de errores

Ante cualquier entrada inválida, el programa escribe `Error` seguido de un salto de línea en la **salida de error** (`stderr`) y termina con código 1. Se considera inválido:

- Argumentos que no son enteros (`abc`, `1a`, `--`).
- Números fuera del rango de `int` (por ejemplo `2147483648`).
- Números duplicados.
- Más de una estrategia indicada a la vez (`--simple --medium`).

Si no se pasan argumentos, o solo hay números ya ordenados (o un único número), el programa no imprime nada.

### Ejemplo de `--bench`

```text
$ ./push_swap --bench 5 2 4 1 3 > /dev/null
[bench] Disorder: 70.00%
[bench] Estrategia: Complex / O(n log n)
[bench] Operations total: 25
[bench] sa=0 sb=0 ss=0 pa=10 pb=10 ra=5 rb=0 rr=0 rra=0 rrb=0 rrr=0
```

### Comprobar el resultado

Con el verificador proporcionado por el subject:

```bash
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG        # debe imprimir OK
./push_swap $ARG | wc -l                       # número de operaciones
```

---

## Algoritmos y justificación

### Representación de los datos

Cada pila es una **lista doblemente enlazada** con punteros `top` y `bot` y un contador `size`. Esta elección permite que `pa`, `pb`, `ra` y `rra` cuesten **O(1)**: con una lista simple, `rra` tendría que recorrer toda la lista para localizar el penúltimo nodo.

Cada nodo guarda su `value` y un `index`: la posición que ocuparía el valor una vez ordenado (0 para el menor, `n-1` para el mayor). Todos los algoritmos trabajan con el `index`, de modo que los valores concretos (negativos, enormes...) dejan de importar y el problema se reduce a ordenar una permutación de `0..n-1`.

### Métrica de desorden

Antes de mover nada se calcula el **desorden** de la entrada:

```
desorden = pares mal ordenados / pares totales
```

Un par `(i, j)` con `i` antes que `j` está mal ordenado si `valor[i] > valor[j]`. El resultado está en `[0, 1]`: `0` es una pila ya ordenada y `1` es una pila completamente al revés. Se calcula en O(n²), pero solo una vez y antes de operar.

### Simple: inserción, O(n²)

1. Se pasan todos los elementos de `a` a `b` con `pb`, eligiendo cada vez dónde insertar para que `b` quede **ordenada de mayor a menor**. Para ello se busca la posición correcta y se rota `b` con `rb` o `rrb` (el sentido más corto).
2. Se rota `b` hasta tener el máximo arriba y se devuelve todo a `a` con `pa`.

**Por qué esta opción:** es el algoritmo más fácil de razonar y de verificar, y cumple la clase O(n²) que pide el subject. Tiene además una propiedad útil: si la entrada ya está casi ordenada, apenas hay que rotar, y el coste baja a un valor cercano a lineal (en nuestras pruebas, unas **2n** operaciones para 100 números con pocos pares intercambiados). Esa propiedad es la que aprovecha la estrategia adaptativa.

### Medium: bloques (chunks), O(n√n)

1. Se divide el rango de índices en bloques de tamaño `√n`. El bloque de un elemento es `index / √n`.
2. Se procesan los bloques por orden creciente. En cada uno se busca el elemento de ese bloque más cercano al tope de `a` (por arriba con `ra` o por abajo con `rra`) y se manda a `b` con `pb`, insertándolo en su sitio para que `b` quede ordenada de mayor a menor.
3. Al terminar, se rota `b` hasta tener el máximo arriba y se devuelve todo a `a`.

**Por qué esta opción:** al limitar cada fase a un bloque de `√n` elementos, las rotaciones necesarias para insertar en `b` se mantienen pequeñas, y el coste total es del orden de `n` elementos × `√n` movimientos = O(n√n). Es mucho mejor que la inserción pura con tamaños medianos (100 números) y es conceptualmente cercano al algoritmo simple, lo que lo hace fácil de depurar.

### Complex: radix sort binario, O(n log n)

Se ordena **bit a bit**, empezando por el menos significativo del `index`. Para cada bit:

1. Se recorren todos los elementos de `a`. Si su bit es `0` se manda a `b` (`pb`); si es `1` se deja en `a` rotándolo (`ra`).
2. Se devuelve todo `b` a `a` con `pa`.

Tras procesar todos los bits (⌈log₂ n⌉ pasadas), la pila queda ordenada. Funciona porque cada pasada es **estable**: los elementos con el mismo bit conservan su orden relativo.

**Por qué esta opción:** no compara números entre sí, solo mira bits, así que el número de operaciones es **fijo para cada `n`** (no depende del orden inicial) y crece como `n · log n`. Es sencillo de implementar y muy robusto. Se usa el `index` en lugar del valor para que funcione con cualquier entero, incluidos negativos.

### Adaptive: elegir según el desorden

No es un algoritmo nuevo, sino un **selector** que usa la métrica de desorden:

| Desorden | Estrategia elegida | Complejidad |
|---|---|---|
| `< 0.2` | Simple | O(n) en entradas casi ordenadas |
| `≥ 0.2` y `< 0.5` | Medium | O(n√n) |
| `≥ 0.5` | Complex | O(n log n) |

**Justificación de los umbrales:** si la lista está casi ordenada, el algoritmo de inserción apenas tiene trabajo y no compensa usar otro más pesado. Si el desorden es medio, los bloques ofrecen un buen equilibrio. Cuando el desorden es alto, el coste fijo y predecible del radix es la mejor garantía para tamaños grandes. Con `--bench` se muestra la estrategia **realmente ejecutada**.

### Resultados medidos

Operaciones con entradas aleatorias (sin duplicados):

| Estrategia | 100 números | 500 números |
|---|---|---|
| Medium | ≈ 850 | ≈ 8400 |
| Complex | 1084 | 6784 |
| Objetivo del subject: mínimo | < 2000 | < 12000 |
| Objetivo del subject: bueno | < 1500 | < 8000 |

Con 100 números gana Medium; con 500 gana Complex, como cabe esperar al crecer `n`: O(n log n) se impone sobre O(n√n). Ambos superan el nivel "bueno" en 100 números y Complex lo supera también en 500.

---

## Estructura del proyecto

```text
push_swap/
├── Makefile
├── README.md
├── main.c
├── includes/
│   └── push_swap.h
├── libft/                      # libft propia con ft_printf
└── srcs/
    ├── parsing/                # flags, validación y construcción de la pila
    ├── stack/                  # operaciones sobre nodos y listas
    ├── operations/             # sa sb ss pa pb ra rb rr rra rrb rrr
    ├── algorithms/
    │   ├── simple/             # inserción
    │   ├── medium/             # bloques (chunks)
    │   ├── complex/            # radix sort
    │   └── adaptive/           # selector por desorden
    └── benchmark/              # cálculo del desorden y modo --bench
```

### Decisiones técnicas

- **Funciones permitidas:** `read`, `write`, `malloc`, `free`, `exit` y las de la `libft`/`ft_printf` propias. Todo lo que se imprime en `stderr` usa `ft_putstr_fd` y `ft_putnbr_fd`.
- **Sin variables globales:** los contadores de operaciones viajan en una estructura (`t_op_count`) pasada por puntero.
- **Operaciones "silenciosas" y "con impresión":** `sa`, `ra`, `rra`... existen en versión que solo mueve (reutilizable por `ss`, `rr`, `rrr`) y en versión `_print` que además imprime y cuenta, para no duplicar la lógica.
- **Gestión de memoria:** quien reserva memoria la libera; los errores terminan siempre a través de una única función que libera ambas pilas.
- **Rendimiento del parseo:** se valida cada argumento, se comprueban duplicados una sola vez sobre el conjunto completo y solo después se construye la pila.

---

## Recursos

### Referencias clásicas
- Subject de 42 *push_swap* y verificador (`checker`) proporcionado.
- Páginas del manual de Linux: `man 2 write`, `man 3 malloc`, `man 3 exit`.
- [mapena-z en GitHub](https://github.com/mapena-z)

### Uso de la IA

Se ha utilizado **Claude (Anthropic)** como herramienta de apoyo al aprendizaje y a la revisión, no para generar el proyecto de forma automática. En concreto:

- **Explicación de conceptos:** punteros y listas doblemente enlazadas, complejidad algorítmica, funcionamiento del radix sort y de la estrategia por bloques, `stdout` frente a `stderr`, y la estructura de un Makefile.
- **Guía en el diseño del parseo:** orden de validaciones y convención de valores de retorno, que luego escribimos nosotros.
- **Revisión de código:** detección de errores en operaciones, parseo y Makefile, y comprobación de que las funciones cumplen la norma de 42.
- **Redacción y apoyo en pruebas:** preparación de este README y de comandos de prueba con el `checker`.

Todo el código fue entendido, probado y revisado por los autores antes de incluirse en el proyecto.