/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <string>

#include "stack.h"
#include "queue.h"

using namespace std;

void parse (vector<string> wordArr) {

    int wordLen;
    Queue<string> revW(wordLen); // our queue simulatiuon

    for (unsigned i = 0; i < wordArr.size(); i++) {
        Stack<char*> revWord(wordLen);//(wordArr[i].length()); //our stack simulation

        for(int j = 0; j < wordArr[i].length(); j++)
            revWord.push(&wordArr[i][0] + j * sizeof(char));

        string rev;
        for (int j = 0; j < wordArr[i].length(); j++){
            char* s = revWord.Top();
            revWord.pop();
            rev = rev + *s;
        }
        revW.Enqueue(rev);
        
    } 
    for (int ll = 0; ll < revW.length(); ll++){
        cout << revW.viewItems(ll);
        if (ll == revW.length() -1)
            cout << "."<<endl;
        else
            cout << " ";
    }
}

