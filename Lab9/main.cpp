#include <iostream>
#include <vector>

#include "tree.h"
#include "tokenizer.h"
using namespace std;

int main(){

redo:
    word_list.init();
    char choice;
    cout << "Words Loaded!" << endl;
    cout << " Ascending, descending or search (a/d/s)?: " ;
    cin >> choice;

    if (choice == 'a')
        word_list.tokens.getAllAscending();
    else if (choice == 'd')
        word_list.tokens.getAllDescending();
    else if (choice == 's') {
        string worrd;
        cout <<"\n Type in word: ";
        cin >> worrd;
        Token defaul;
        BinaryTree<Token>::Node* tempNod;
        tempNod = word_list.tokens.search(true, worrd, defaul);

        if (tempNod == NULL)
            cout << "WORD NOT FOUND! " << endl;
        else 
            cout << tempNod->data;
    }

    else {
        cout << "TRY AGAIN!!" << endl;
        goto redo;
    }

}
