#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
/** \brief Coloca el iterador en el primer nodo
 *
 *  \param this LinkedList* Puntero a la lista
 */
static void ll_startIterator(LinkedList* this)
{
    if(this != NULL)
    {
        this->pIteratorNode = this->pFirstNode;
    }
}
/** \brief  Toma el siguiente elemento de la lista utilizando el nodo declarado estaticamente
 *          Y coloca el nodo en el siguiente indice de la lista
 *  \param this LinkedList* Puntero a la lista
 *  \return void*   Retorna (NULL) en el caso de no conseguir un nuevo elemento o si el siguiente elemento es NULL
 *                  Y retorna el puntero al elemento si existe.
 */
static void* ll_getNext(LinkedList* this)
{
    void* returnAux = NULL;
    if(this->pIteratorNode != NULL)
    {
        returnAux = this->pIteratorNode->pElement;
        this->pIteratorNode = this->pIteratorNode->pNextNode;
    }
    return returnAux;
}
static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);
/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}
/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    if(this != NULL && !ll_isEmpty(this) && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;
        for(i=0;i<nodeIndex;i++)
        {
            pNode = pNode->pNextNode;
        }
    }
    return pNode;
}
/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}
/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode = malloc(sizeof(Node));
    Node* auxNodeAnterior = NULL;
    Node* auxNodeSiguiente = NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        if(nodeIndex == 0)
        {
            pNewNode->pNextNode = this->pFirstNode;
            this->pFirstNode = pNewNode;
        }
        else if(nodeIndex > 0 && nodeIndex <= ll_len(this))
        {
            auxNodeAnterior = getNode(this, nodeIndex-1);
            auxNodeSiguiente = auxNodeAnterior->pNextNode;
            auxNodeAnterior->pNextNode = pNewNode;
            pNewNode->pNextNode = auxNodeSiguiente;
        }
        this->size += 1;
        pNewNode->pElement = pElement;
        returnAux = 0;
    }
    return returnAux;
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}
/** \brief Elimina un nodo y enlaza el anterior con el siguient
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se eliminara el nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int removeNode(LinkedList* this, int nodeIndex)
{
    int returnAux = -1;
    Node* pDeleteNode = NULL;
    Node* auxNodeAnterior = NULL;
    Node* auxNodeSiguiente = NULL;
    if(this != NULL && !ll_isEmpty(this) && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pDeleteNode = getNode(this, nodeIndex);
        if(nodeIndex == 0)
        {
            this->pFirstNode = pDeleteNode->pNextNode;
            free(pDeleteNode);
        }
        else if(nodeIndex > 0 && nodeIndex <= ll_len(this))
        {
            auxNodeAnterior = getNode(this, nodeIndex-1);
            auxNodeSiguiente = auxNodeAnterior->pNextNode->pNextNode;
            auxNodeAnterior->pNextNode = auxNodeSiguiente;
            free(pDeleteNode);
        }
        this->size -= 1;
        returnAux = 0;
    }
    return returnAux;
}
/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    return addNode(this, ll_len(this), pElement);
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode = NULL;
    if(this != NULL && !ll_isEmpty(this) && index >= 0 && index < ll_len(this))
    {
        auxNode = getNode(this, index);
        returnAux = auxNode->pElement;
    }
    return returnAux;
}
/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode;
    if(this != NULL && !ll_isEmpty(this) && index >= 0 && index < ll_len(this))
    {
        auxNode = getNode(this, index);
        auxNode->pElement = pElement;
        returnAux = 0;
    }
    return returnAux;
}
/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    return removeNode(this,index);
}
/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    if(this != NULL && !ll_isEmpty(this))
    {
        for(i=ll_len(this)-1; i>=0; i--)
        {
            removeNode(this,i);
        }
        returnAux = 0;
    }
    return returnAux;
}
/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }
    return returnAux;
}
/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* auxElement = NULL;
    int i;
    if(this != NULL && !ll_isEmpty(this))
    {
        ll_startIterator(this);
        for(i = 0; i < ll_len(this); i++)
        {
            auxElement = ll_getNext(this);
            if(auxElement == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}
/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 1;
        if(ll_len(this) > 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}
/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}
/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && !ll_isEmpty(this) && index >= 0 && index < ll_len(this))
    {
        returnAux = ll_get(this,index);
        removeNode(this,index);
    }
    return returnAux;
}
/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
        if(ll_indexOf(this, pElement) != -1)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* auxElement = NULL;
    int i;
    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        ll_startIterator(this);
        for(i=0; i<ll_len(this2); i++)
        {
            auxElement = ll_getNext(this);
            if(!ll_contains(this,auxElement))
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}
/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* auxElement = NULL;
    int i;
    if(this != NULL && from >= 0 && to > from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        ll_startIterator(this);
        for(i=from; i<to; i++)
        {
            auxElement = ll_getNext(this);
            ll_add(cloneArray,auxElement);
        }
    }
    return cloneArray;
}
/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this,0,ll_len(this));
}
/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o el puntero a la funcion es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int i;
    int flagSwap;
    Node* auxNode;
    if(this != NULL && ll_len(this) > 0 && (order == 1 || order == 0) && pFunc != NULL)
    {
        do
        {
            auxNode = getNode(this, 0);
            flagSwap = 0;
            for(i=0; i<ll_len(this)-1; i++)
            {
                if( (order == 0 && auxNode->pElement != NULL && auxNode->pNextNode->pElement != NULL &&
                    (*pFunc)(auxNode->pElement, auxNode->pNextNode->pElement) == -1) ||

                    (order == 1 && auxNode->pElement != NULL && auxNode->pNextNode->pElement != NULL &&
                    (*pFunc)(auxNode->pElement, auxNode->pNextNode->pElement) == 1))
                {
                    flagSwap = 1;
                    ll_swapElement(this, auxNode);
                }
                auxNode = auxNode->pNextNode;
            }
        }
        while(flagSwap==1);
        returnAux = 0;
    }
    return returnAux;
}
/** \brief Intercambia los elementos de dos nodos consecutivos
 * \param pList LinkedList* Puntero a la lista
 * \param pNodeAnterior Es el primer nodo que se va a intercambiar, el segundo lo obtenemos de su pNextNode
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o alguno de los nodos es NULL
                                ( 0) Si ok
 */
int ll_swapElement(LinkedList* this, Node* pNodeAnterior)
{
    int returnAux = -1;
    Node* pNodeSiguiente = pNodeAnterior->pNextNode;
    void* auxElement = NULL;
    if(this != NULL && pNodeAnterior != NULL && pNodeSiguiente != NULL)
    {
        auxElement = pNodeAnterior->pElement;
        pNodeAnterior->pElement = pNodeSiguiente->pElement;
        pNodeSiguiente->pElement = auxElement;
        returnAux = 0;
    }
    return returnAux;
}
/** \brief Filtra los elementos de una LinkedList y guarda en una nueva los que cumplen con el criterio indicado
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio que devuelve un 1 si se debe guardar en la nueva lista
 *                                                                     0 si no cumple con el criterio
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o el puntero a la funcion es NULL
                                ( 0) Si ok
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* pElement))
{
    void* auxElement = NULL;
    LinkedList* returnAux = NULL;
    int i;
    if(this != NULL && ll_len(this) > 0 && pFunc != NULL)
    {
        returnAux = ll_newLinkedList();
        ll_startIterator(this);
        for(i=0; i<ll_len(this); i++)
        {
            auxElement = ll_getNext(this);
            if((*pFunc)(auxElement) == 1)
            {
                ll_add(returnAux, auxElement);
            }
        }
    }
    return returnAux;
}
/** \brief Realiza una funcion con cada elemento dentro de un rango(from-to)
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio que devuelve un 0 si se realizo de manera correcta
 * \param from int indice del elemento desde donde se realiza la funcion(incluido)
 * \param to int indice del elemento hasta donde se realiza la funcion(no incluido)
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL, el puntero a la funcion es NULL o
 *                                  el from y el to no estan dentro del rango de la lista
 *                      (1) Si se produce un error al utilizar la funcion.
                                ( 0) Si ok
 */
/*int ll_map(LinkedList* this, int (*pFunc)(void* pElement),int from, int to)
{
    int returnAux = -1;
    void* auxElement = NULL;
    Node* auxNode = NULL;
    int i;
    if(this != NULL && ll_len(this) > 0 && pFunc != NULL && from >= 0 && to > from && to <= ll_len(this))
    {
        returnAux = 0;
        auxNode = getNode(this, from);
        this->pIteratorNode = auxNode;
        for(i=from; i<to; i++)
        {
            auxElement = ll_getNext(this);
            if((*pFunc)(auxElement) != 0)
            {
                returnAux = 1;
                break;
            }
        }
    }
    return returnAux;
}*/
int ll_map(LinkedList * this,  int (*pFunc)(void*))
{
    int returnAux = -1;
    int i;
    void * element1;
    if(this != NULL && pFunc != NULL)
    {
        for ( i= 0; i < ll_len(this); i++)
        {
            element1 = ll_get(this,i);
            if(pFunc(element1)== 0)
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


LinkedList* ll_filterConDosPrametro(LinkedList* this, int (*pFunc)(void* pElement, int pElement2))
{
    void* auxElement = NULL;
    LinkedList* returnAux = NULL;
    int i;
    int bufferIdProducto;
    if(this != NULL && ll_len(this) > 0 && pFunc != NULL)
    {
        returnAux = ll_newLinkedList();
        ll_startIterator(this);
        utn_getEntero(&bufferIdProducto, 10, "\nIngrese id de producto: \n", "Id incorrecto", 3);
        for(i=0; i<ll_len(this); i++)
        {
            auxElement = ll_getNext(this);
            if((*pFunc)(auxElement,bufferIdProducto ) == 1)
            {
                ll_add(returnAux, auxElement);
            }
        }
    }
    return returnAux;
}
