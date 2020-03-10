#ifndef LM
#define LM

#include "list.h"

template <class T>
class ListMOut : public List<T> {

public:

    int moveCount1;

    virtual void addItem(T t) {

        if(!ListMOut<T>::isFull()){
            for(int i = 0; i < 5; i++){

                if (ListMOut<T>::data[5 + i] == NULL){
                    ListMOut<T>::data[5 + i] = &t;
                    moveCount1++;
                    break;
                }

                else if(ListMOut<T>::data[5 - i] == NULL){
                    ListMOut<T>::data[5 - i] = &t;
                    moveCount1++;
                    break;
                }
            }
        }
        else{
            throw ListIsFull();
        }
    }
    
    class ListIsFull{};
    class ItemDoesntExist{};

    void showFinalCounts(){
        cout << "COUNTS FOR 2ND CLASS VERSION:" << endl;
        cout << "Final move count: " << moveCount1 << endl;
        cout << "___________________________________________"  << endl;
    }
}; 

template <class T>
class ListInsertOrdered : public List<T> {

public:
    int moveCount2 = 0;
    int comparisonCount2 = 0;

    bool isFull(){
    for(int i = 0; i < 10; i ++){
        if(List<T>::data[i] == NULL){
            return false;
        }
    }
    return true;
    }

    virtual void addItem(T t, int pos) {

        pos -= 1;

        if(!isFull()){
           
            int nul_index;

            for (int i = 0; i < 10; i++){
                if (List<T>::data[i] == NULL){

                    nul_index = i;
                    break;
                }
            }
            if (nul_index == pos){
                comparisonCount2++;
                moveCount2++;
                List<T>::data[pos] = &t;
            }
            else if (nul_index > pos){

                for (int i = nul_index; i < pos; i--){
                    moveCount2++;
                    List<T>::data[i] = List<T>::data[i - 1]; 
                }
                List<T>::data[pos] = &t;
            }

            else {
                for (int i = pos; i < nul_index; i++){
                    comparisonCount2++;
                    List<T>::data[i] = List<T>::data[i + 1];
                }
                List<T>::data[pos] = &t;
            }
                    
        }
            
        else{
            throw ListIsFull();
        }
    }

    virtual void removeItem(int pos){

        pos -= 1;

        if ((pos < 10) && (pos > -1) && (List<T>::data[pos] != NULL)){
            comparisonCount2++;
            ListInsertOrdered<T>::data[pos] = NULL;
        }
        else{
            throw ItemDoesntExist();
        } 
    }

    class ListIsFull{};
    class ItemDoesntExist{};

    void showFinalThirdCounts(){
        cout << "COUNTS FOR 3RD CLASS VERSION:" << endl;
        cout << "Final move count: " << moveCount2 << endl;
        cout << "Final comparison count: " << comparisonCount2 << endl;
        cout << "___________________________________________"  << endl;
    }
};

#endif

