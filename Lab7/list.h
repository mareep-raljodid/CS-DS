#ifndef LIST
#define LIST

template <class T>
class List{
    
public:

    T* data[25];

    List<T>();
    virtual void addItem(T);
    virtual void removeItem(int pos);
    bool isFull();
    bool isEmpty();
    void makeEmpty();
    
    class ListIsFull{};
    class ItemDoesntExist{};
}; 
#include "list.tpp"
#include "middleOut.h"
#endif
