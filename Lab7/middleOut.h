#ifndef LM
#define LM

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

template <class T>
class ListInsertOrdered : public List<T> {

public:

    virtual void addItem(T t, int pos) {

        pos -= 1;

        if(!List<T>::isFull()){
           
            int nul_index;

            for (int i = 0; i < 25; i++)

                if (List<T>::data[i] == NULL){

                    nul_index = i;
                    break;
                }
            
            if (nul_index == pos)

                List<T>::data[pos] = t;

            else if (nul_index > pos){

                for (int i = nul_index; i < pos; i--)

                    List<T>::data[i] = List<T>::data[i - 1]; 

                List<T>::data[pos] = t;
            }

            else {

                for (int i = pos; i < nul_index; i++)

                    List<T>::data[i] = List<T>::data[i + 1];

                List<T>::data[pos] = t;
            }
                    
        }
            
        else
            throw ListIsFull();
    }

    virtual void removeItem(int pos){

        pos -= 1;

        if ((pos < 25) && (pos > -1) && (List<T>::data[pos] != NULL))

            List<T>::data[pos] = NULL;

        else

            throw ItemDoesntExist();
    }

    class ListIsFull{};
    class ItemDoesntExist{};
};

#endif

