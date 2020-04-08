#ifndef TKN
#define TKN
#include <iostream>
#include "tree.h"
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <map>

#define FileNotFound "-------"

using namespace std;

struct Token {

    public:
    string word;
    unsigned wordCount;
};

class wordList {

    public:
        Token defaul;
        
        BinaryTree<Token> tokens;
        BinaryTree<Token>::Node* tempNode;

        void init(){

            fstream data;
            data.open("sample.txt", ios::in);

            if (data.fail()) throw FileNotFound;

            string word;
            while (data >> word){
                Token* temp = new Token;

                if(tokens.search(true, word, defaul) == NULL){
                    temp->word = word;
                    temp->wordCount = 1;
                    tokens.insert(*temp);
                }

                else {
                    tempNode = tokens.search(true, word, defaul);
                    tempNode->data.wordCount ++;
                }
            }

            data.close();

            /*FIXME | Was using this instead because maps would be easier
                    | but design wise, this assignment was stupid
                    |

            map<string, int> list;
            Token temp;
            for (map<string, int>::iterator i = list.begin(); i != list.end(); ++i) {
                temp.word = i->first;
                temp.wordCount = i->second;
                tokens.push_back(temp); index++;
            }

            for (int o =0; o < getSize(); o++)
                cout << tokens[o].word << " | | " << tokens[o].wordCount << endl;
            */

	    }
}word_list;

bool operator < (Token const &t1, Token const &t2) { return (t1.wordCount < t2.wordCount) && (t1.word == t2.word); }
bool operator > (Token const &t1, Token const &t2) { return (t1.wordCount >= t2.wordCount) && (t1.word == t2.word); }
bool operator == (Token const &t1, Token const &t2) { return (t1.wordCount == t2.wordCount) && (t1.word == t2.word); }

ostream & operator << (ostream &out, const Token &t)
{
    out << "Word: ";
    out << t.word;
    out << " | Repeats: ";
    out << t.wordCount << endl;
    return out;
}
#endif
