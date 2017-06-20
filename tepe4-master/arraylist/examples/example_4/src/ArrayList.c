#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList,void* pElement)
{
    void* pAux;
    if(pList!=NULL&&pElement!=NULL)
    {
        pList->pElements[pList->size]=pElement;
        pList->size++;
    }else{
        return -1;
    }
    if(pList->size>=pList->reservedSize)
    {

        pList->reservedSize+=10;
        pAux = (void*)realloc(pAux,sizeof(void*)*pList->reservedSize);
        if(pAux==NULL)
        {
            printf("No hay espacio en memoria");
            return -1;
        }else{
            pList->pElements=pAux;
        }
    }
    return 0;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList) // (3)
{
    int retorno;
    if(pList==NULL)
    {
        retorno=-1;
    }else{
        retorno=0;
    }
    free(pList);
    return retorno;

}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pList)
{
    int retorno;
    if(pList==NULL)
    {
        retorno= -1;
    }else{
        retorno=pList->size;
    }
    return retorno;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */

void* al_get(ArrayList* pList , int index) // (5)
{
    return -1;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement) //(6)
{
    int flag=0,i;
    if(pList!=NULL&&pElement!=NULL)
    {
        for(i=0; i< pList->size;i++)
        {
            if(pList->pElements[i]== pElement)
            {
                flag= 1;
                break;
            }
        }
    }else{
        flag= -1;
    }
    return flag;
}

/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement) //(7)
{
    int retorno=0;
    if(pList!=NULL && pElement!=NULL)
    {
        if(index>0 && index <= pList->size)
        {
            pList->pElements[index]=pElement;
            retorno;

        }else{

            retorno= -1;
        }
    }else{
        retorno= -1;
    }

    return retorno;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index) //(8)
{
    int retorno;
    if(pList==NULL)
    {
        retorno= -1;
    }else{

        if(index<0 || index > pList->size)
        {
            retorno= -1;

        }else{
            free(pList->pElements[index]);
            pList->size--;
            pList->reservedSize--;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList) // (9)
{
    int retorno=0;
    if(pList==NULL)
    {
        retorno= -1;
    }else{
        free(pList->pElements);
        pList->size=0;
    }

    return retorno;
}


/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement) // (11)
{
    int retorno,j, i;
    void** auxPointer;
    auxPointer=(void**)malloc(sizeof(void*)*pList->size);
    if(pList==NULL || pElement==NULL)
    {
        retorno= -1;

    }else{
        if(index<0 || index >= pList->size)
        {
           retorno= -1;

        }else{
            for(i=0; i<pList->size; i++)
            {
                if(i >=index)
                {
                    j=i+1;
                    auxPointer[j]=pList->pElements[i];
                }
                auxPointer[i]=pList->pElements[i];
            }
            auxPointer[index]=pElement;
            pList->pElements=auxPointer;

            retorno=0;
        }
    }
        free(auxPointer);

    return retorno;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* element)
{
    int i,retorno, flag=0;
    if(pList!=NULL&&element!=NULL)
    {
        for(i=0;i<pList->size;i++)
        {
            if(pList->pElements[i]==element)
            {
                flag=1;
                retorno=i;
                break;
            }
        }
        if(flag==0)
            retorno=-1;

    }else{
        retorno= -1;
    }
    return retorno;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList) // (13)
{
    int retorno;
    if(pList!=NULL)
    {
        if(pList->size==0)
        {
            retorno=1;
        }else{
            retorno=0;
        }

    }else{
        retorno= -1;
    }

    return retorno;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList , int index) // (14)
{
    void* auxPointer;
    ArrayList auxAl;

    if(pList==NULL)
    {
        auxPointer= NULL;

    }else{
        if(index<0 || index >= pList->size)
        {
            auxPointer= NULL;

        }else{

            auxPointer=pList->pElements[index];
            free(pList->pElements[index]);
            pList->size--;
            pList->reservedSize--;
        }
    }
    return auxPointer;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* returnAux = NULL;

    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;

    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;

    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}
