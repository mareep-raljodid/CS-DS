/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include <bits/stdc++.h>
#include <queue>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <string>


#include "stack.h"


using namespace std;

void parse (vector<string> wordArr) {

    int wordLen;
    vector<char *> wordAddr;
    vector<string> revW;

    for (unsigned i = 0; i < wordArr.size(); i++) {
        Stack<const char> revWord(wordArr[i].length());

        const char* arr = wordArr[i].c_str();
        for(int j = 0; j < wordArr[i].length(); j++)
            revWord.push(&arr[j]);

        string rev;
        for (int j = 0; j < wordArr[i].length(); j++){
            char* s = (char*)revWord.pop();
            rev = rev + *s;
        }
        cout << rev;
        
    } 
    /*for (int ll = 0; ll < revW.size(); ll++){
        cout << revW[ll];
        if (ll == revW.size() -1)
            cout << "."<<endl;
        else
            cout << " ";
    }*/
}

