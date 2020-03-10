#ifndef LIST
#define LIST

template <class T>
class List{
    
public:

    T* data[10];
    int comparisonCount;
    int moveCount;

    List<T>();
    virtual void addItem(T);
    virtual void removeItem(int pos);
    bool isFull();
    bool isEmpty();
    void makeEmpty();

    void showFinalCounts();
    
    class ListIsFull{};
    class ItemDoesntExist{};
}; 
#include "list.tpp"
#include "middleOut.h"
#endif
