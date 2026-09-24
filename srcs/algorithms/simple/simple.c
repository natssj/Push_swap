// insertion
// ejemplo
// El algoritmo consiste en ordenar los dos primeros elementos de la matriz, luego se inserta el tercer elemento en la posición correcta con respecto a los dos primeros, a continuación se inserta el cuarto elemento en la posición correcta con respecto a los tres primeros elementos ya ordenados y así sucesivamente hasta llegar al ultimo elemento de la matriz.

// Explicación
// Ejemplos
// void ordenamientoSeleccion(Tlista lista){

//   Tlista actual, siguiente;   int t;
//   actual = lista; int minimo;
//   Tlista min=lista;
  
//   while(actual->sgte!=NULL){
//      minimo=actual->valor;
//      min=actual;
//      siguiente=actual->sgte;
     
//      while(siguiente!=NULL){
        
//         if(siguiente->valor < minimo){
//         minimo = siguiente->valor;
//         min = siguiente;
//         }
        
//         siguiente=siguiente->sgte;      
//      }
     
//      t= actual->valor;
//      actual->valor=min->valor;
//      min->valor=t;
     
//      actual=actual->sgte;
     
//   }