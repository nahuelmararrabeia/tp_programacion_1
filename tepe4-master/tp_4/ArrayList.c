#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#define AL_INITIAL_VALUE  10

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void) // (1) TESTEADO
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList=(ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            //pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            //pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            //pList->subList=al_subList;
            //pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            //pList->sort = al_sort;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}

int al_add(ArrayList* pList,void* pElement)
{
    void* pAux;
    pAux=(void*)malloc(sizeof(void));
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

int al_len(ArrayList* pList) //(4) TESTEADO!
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

int al_contains(ArrayList* pList, void* pElement) //(6) TESTEADO
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

/*
Inserta un elemento en el ArrayList, en el índice especificado. Verificando que tanto el puntero
pList como pElement sean distintos de NULL y que index sea positivo e inferior al tamaño del
array. Si la verificación falla la función retorna (-1) y si tiene éxito (0).
*/

int al_set(ArrayList* pList, int index,void* pElement) //(7)
{
    int retorno;
    if(pList!=NULL&&pElement!=NULL)
    {
        if(index>0 && index <= pList->size)
        {
            pList->pElements[index]=pElement;
            retorno=0;

        }else{

            retorno= -1;
        }
    }else{
        retorno= -1;
    }

    return retorno;
}

/*   Elimina un elemento del ArrayList, en el índice especificado. Verificando que el puntero pList
sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
falla la función retorna (-1) y si tiene éxito (0).
*/
int al_remove(ArrayList* pList,int index) //(8) TESTEADO!
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

int al_clear(ArrayList* pList) // (9) TESTEADO!
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

/*
int al_push(ArrayList* pList, int index, void* pElement) // (11)
{
    int retorno,j;
    void** auxPointer;
    auxPointer=(void**)malloc(sizeof(void*)*pList->size);
    if(pList==NULL || pElement=NULL)
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
        free(auxPointer);

    return retorno;
}
*/

int al_indexOf(ArrayList* pList, void* element) // (12) TESTEADO!
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



int al_isEmpty(ArrayList* pList) // (13)  TESTEADO!
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


void* al_get(ArrayList* pList , int index) // (5) TESTEADO!
{
    void* auxPointer;
    auxPointer=(void*)malloc(sizeof(void));

    if(pList==NULL)
    {
        auxPointer= NULL;

    }else{
        if(index<0 || index >= pList->size)
        {
            auxPointer= NULL;

        }else{

            auxPointer=pList->pElements[index];

        }
    }
    return auxPointer;
}

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
            al_remove(pList, index);
        }
    }
    return auxPointer;
}


int al_deleteArrayList(ArrayList* pList) // (3) TESTEADO!
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





