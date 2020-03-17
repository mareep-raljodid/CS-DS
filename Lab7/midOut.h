#ifndef LIM
#define LIM

#include "list.h"

template <class T>
class ListMOut : public List<T> {

public:

    virtual void addItem(T t) {

        if(!List<T>::isFull())
            for(int i = 0; i < 12; i++){
                if (List<T>::data[12 + i] == NULL){
                    List<T>::data[12 + i] = &t;
                    break;
                }

                else if(List<T>::data[12 - i] == NULL){
                    List<T>::data[12 - i] = &t;
                    break;
                }
            }

        else
            throw ListIsFull();
    }
    
    class ListIsFull{};
    class ItemDoesntExist{};
};

#endif
