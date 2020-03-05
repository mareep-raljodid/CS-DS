#ifndef LIST
#define LIST

template <class T>
class List{
private:
    T* data[25];
public:
    List<T>();
    void addItem(T);
    void removeItem(int pos);
    bool isFull();
    bool isEmpty();
    void makeEmpty();
    
    class ListIsFull{};
    class ItemDoesntExist{};
}; 
#include "list.tpp"
#endif