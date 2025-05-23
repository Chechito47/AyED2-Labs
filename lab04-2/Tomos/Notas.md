## Instalar
- Primero correr `python3 --version` y ver que sea 3.12
- Luego correr `sudo apt install python3.12-venv`
- Luego `python3.12 -m venv myenv`
- Luego `./myenv/bin/pip install tomos`
- Por ultimo `./myenv/bin/tomos --version` para verificar que este bien. Debe devolver **Tomos version 0.1.6**

# setup.ayed

## ¿Que hace?
Crea una lista enlazada de nodos con longitud dada por *"LINKED_LIST_LENGTH"*.  
Cada nodo tiene un campo **data** y un puntero al siguiente nodo **next**.  
Al **data** de cada nodo les asigna el su **numero de nodo - 1** multiplicado por 10. O sea lo lleva a las decenas.  
Termina con el **data** del ultimo nodo = 0 y su **next** = NULL

Seria algo asi:  
i = 5 (i es quien dicta la cantidad de nodos)  
[ data=40 ] → [ data=30 ] → [ data=20 ] → [ data=10 ] → [ data=0 ] -> NULL

## ¿Que valores tienen los elementos de la lista?
Con valores supongo que se refiere al campo **data**.  
El valor del data estara determinado por la cantidad de nodos inciales ***("LINKED_LIST_LENGTH"* - 1) x 10** para cada posicion

## Ejecucion
- Me situo en la ubicacion del **setup.ayed** y corro `export LINKED_LIST_LENGTH=3`
- Luego corro `./myenv/bin/tomos setup.ayed --save-state=setup.st --movie=setup.mp4`

## ¿Que sucede en el video?
Hagamos la traza de ejecucion como el video:  
Primeor se declaran las varibles, el tipo nodo y el tipo lista.  
Luego se vemos que habra un total de 3 nodos porque "LINKED_LIST_LENGTH" tiene tamaño 3  
Luego pedimos memoria para un nodo **my_list**. Ahora suponemos que my_list esta en la posicion de memoria **H00000**. Entonces como my_list es de tipo puntero a **nodo** vemos que apunta a un campo **data** y otro **next**  
Luego hacemos que **a_node** apunte guarde el valor de my_list *(Como es puntero va a guardar la posicion de memoria)* por lo tanto ahora a_node apunta al mismo campo data y next que my_list (Notar que esos valores no los conocemos)  
Luego decrementamos i = i -1 => i=2  
Ahora como i > 0 entramos al while  
Dentro del while lo primero que hace es hacer que el campo **data** valga i*10 => data=20  
Ahora pedimos memoria para hacer otro nodo pero como pedimos `alloc(a_node->next)` no solo pedimos memoria si no que tambien hacemos que el campo next apunte al nuevo nodo para el que pedimos memoria (lo hace la operacion alloc)  
Luego hacemos que **a_node** apunte al nuevo nodo que creamos. Como hacemos `a_node := a_node->next` ahora a_node apunta al nuevo nodo recien creado  
Luego decrementamos i y se repite mientras i > 0  

Durante estas ejecuciones vemos que [ data=20 ] -> [ data=10 ] -> [ data=0 ] -> NULL  

Ese data=0 es debido a que luego del while hacemos `a_node.data := 0` por lo tanto el ultimo nodo vale 0  
Luego hacemos `a_node.next := null` haciendo que no apunte a ningun otro nodo porque es el ultimo  
Y por ultimo hacemos `a_node := null` haciendo que este tampoco a nadie y terminamos  


# append.ayed
## ¿Que hace?
Agrega un nodo al final de una lista enlazada la cual debe ser cargada

## ¿Como lo hace?
Volvemos a apuntar al primer nodo, recorremos hasta llegar al ultimo y ahi pedimos memoria para crear uno nuevo y le ponemos los valores que queremos

## ¿Implementacion?
Con `a_node := my_list` hacemos que apunte al primer nodo de la lista  
Luego con el while avanzamos hasta llegar al ultimo nodo  
Con `alloc(a_node->next)` reservamos la memoria para el nuevo nodo y hacemos que el ultimo nodo ya no apunte a null si no al nodo que creamos  
Lo siguiente es `a_node->next->data := 88`. Como le pasamos una lista enlazada (lo cual se hace con el setup.ayed) el ultimo nodo tiene data=0 y next=null. Por eso si hacemos esta linea tenemos no podemos acceder con a_node->data ya que este apunta a ese ultimo nodo y no al nuevo que creamos **(el que apunta al nuevo nodo es el next del nodo, no el a_node->next)**. Por lo tanto con esto hacemos que su valor sea 88  
Por ultimo con `a_node->next->next := null` hacemos que este nuevo nodo apunte a null.  


# tail.ayed
## ¿Que hace?
Elimina el primer nodo de una lista enlazada cargada

## ¿Como lo hace?
Nos posicionamos en el primer nodo y hacemos el puntero que apunta al primer nodo de la lista lo haga ahora al segundo nodo, luego liberamos la memoria de este primer nodo.

## ¿Implementacion?
Con `a_node := my_list` hago que mi puntero con el que me muevo apunte al primer nodo de la lista  
Luego con `my_list := my_list->next` hago que ahora el primer nodo de la lista sea el segundo  
El `free(a_node)` libera la memoria (o sea la del primer nodo)  
Con `a_node := null` evitamos referencias colgantes


# insert_at.ayed
## ¿Que hace?
Dada una posicion y un valor, introduce un nodo nuevo con esos datos en la lista enlazada dada. Si la posicion es negativa o mayor a N no hace nada. Si es N es append, si es 0 es preppend

## ¿Como lo hace?
Declara enteros para la nueva informacion y la posicion, punteros para recorrer hasta la posicion nueva y otro para introducir los valores del nodo nuevo. Nos salteamos hasta llegar a la posicion en la que queremos introducir el nuevo nodo.  
Al llegar a esa posicion pedimos memoria para un nodo e indicamos que el data es el que habiamos declarado y el next es el siguiente que correspondia cuando hicimos el corte para agregar este nuevo nodo. Si no habia elementos antes tambien hacemos que sea el primero de la lista.  
Por ultimo hacemos que los punteros sean null para evitar referencias colgantes

# remove_first_data.ayed
## ¿Que hace?
Busca y elimina la primera aparacion de un nodo cuyo campo data coincida con el valor dado en **to_remove**.

## ¿Como lo hace?
Primero declaramos algunas variables, entre ellas **to_remove** donde tenemos valor del entero que queremos borrar, un puntero **a_node** con el que recorremos la lista y un puntero auxiliar **aux** para guardar el nodo anterior de a_node.  
Iteramos hasta llegar al final (sin encontrar el to_remove) o hasta que lo encontramos. En cada iteracion guardamos en aux el nodo anterior a a_node para que al encontrar el to_remove apunte al nodo anterior al que queremos borrar.  
Luego simplemente vemos si efectivamente el bucle termino porque encontramos el nodo a borrar, si lo hizo salteamos el nodo a_node, liberamos la memoria del nodo liberado y lo declaramos NULL  
Por ejemplo, tenemos esta lista:  
[10] → [20] → [30] → [40] → null y queremos eliminar el data=30. Esto resulta:  
[10] → [20] --------> [40] → null  
                free([30])

# remove_not_found.ayed
## ¿Que hace?
