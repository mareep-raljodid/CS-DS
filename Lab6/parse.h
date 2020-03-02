/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include <queue>
#include <stack>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <string>


//#include "stack.h"


using namespace std;

void parse (vector<string> wordArr) {

    int wordLen;
    vector<string> revW; // our queue simulatiuon

    for (unsigned i = 0; i < wordArr.size(); i++) {
        stack<char*> revWord;//(wordArr[i].length()); //our stack simulation

        for(int j = 0; j < wordArr[i].length(); j++)
            revWord.push(&wordArr[i][0] + j * sizeof(char));

        string rev;
        for (int j = 0; j < wordArr[i].length(); j++){
            char* s = revWord.top();
            revWord.pop();
            rev = rev + *s;
        }
        revW.push_back(rev);
        
    } 
    for (int ll = 0; ll < revW.size(); ll++){
        cout << revW[ll];
        if (ll == revW.size() -1)
            cout << "."<<endl;
        else
            cout << " ";
    }
}

