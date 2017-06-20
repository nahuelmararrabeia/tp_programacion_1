typedef struct {
    int size;
    void** pElements;
    int reservedSize;


    int (*add)();
    int (*len)();
    int (*contains)();
    int (*set)();
    int (*remove)();
    int (*clear)();
    int (*push)();
    int (*indexOf)();
    int (*isEmpty)();
    void* (*get)();
    void* (*pop)();
    int (*containsAll)();
    int (*sort)();
    struct ArrayList* (* clone)();
    struct ArrayList* (*subList)();
    int (*deleteArrayList)();
}ArrayList;

ArrayList* al_newArrayList(void);
int al_add(ArrayList* pList,void* pElement);
int al_len(ArrayList* pList);
int al_contains(ArrayList* pList, void* pElement);
int al_set(ArrayList* pList, int index,void* pElement);
int al_remove(ArrayList* pList,int index);
int al_clear(ArrayList* pList);
int al_push(ArrayList* pList, int index, void* pElement);
int al_indexOf(ArrayList* pList, void* element);
int al_push(ArrayList* pList, int index, void* pElement);
int al_push(ArrayList* pList, int index, void* pElement);
int al_indexOf(ArrayList* pList, void* element);
int al_isEmpty(ArrayList* pList);
void* al_get(ArrayList* pList , int index);
void* al_pop(ArrayList* pList , int index);
int al_deleteArrayList(ArrayList* pList);


