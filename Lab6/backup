/*
 *
 *
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

vector<string> parse (vector<string> wordArr) {

    //string *word;
    int wordLen;
    //char temp;
    //char *tem;
    //char *p;
    //char *s;

    vector<void *> wordAddr;
    vector<string> revW;
    for (unsigned i = 0; i < wordArr.size(); i++) {
        
        wordLen = wordArr[i].length();
        Stack<char> *revWord = new Stack<char>(wordLen);
        cout << "rdgvrdbrdb----------" ;
       /* char c_word[wordLen + 1]; 
        strcpy(c_word, wordArr[i].c_str());
        c_word[wordLen] = '\0';
        cout << &c_word << endl;*/
        for (int j =0; j < wordLen; j++){
            cout << wordArr[i] << "<<<<<< IMP |||>>>" << &wordArr[i] + i * sizeof(char)<< endl;
            //*p = c_word[0];
            //s = p + i * sizeof(char);
            //wordAddr.push_back(&wordArr[i][0] + j * sizeof(char));
        }
        //for (int i = 0; i < wordLen; i++)
          //  revWord->push((char*)wordAddr[i]);
        
        string reversedWord;        
        for(int k = 0; k < revWord->length(); k++){
            //char *tem = (revWord->pop());
            //reversedWord[k]= *tem;
        }
        revW.push_back(reversedWord);
        revWord->makeEmpty();
        delete revWord;
    }

    for (int ll = 0; ll < revW.size(); ll++){
        cout << revW[ll];
        if (ll == revW.size() -1)
            cout << "."<<endl;
        else
            cout << " ";
    }
}

