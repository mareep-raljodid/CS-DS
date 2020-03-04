#ifndef LIST
#define LIST

class Node{
	T value;
    node *next;
};
template <class T>
class List{
private:
    node *head;
    T* data[25];
public:
    List<T>();
    void addItem(T t);
    T removeItem();
    bool isFull();
    bool isEmpty();
    void makeEmpty();
    
    class ListIsFull{};
    class ItemDoesntExist{};
}; 
#endif