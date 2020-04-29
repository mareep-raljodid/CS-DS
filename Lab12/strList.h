#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <time.h>
#include<string.h>
#include <iomanip>
#include <stdlib.h>

#include "list.h"
#define NL 5

using namespace std;

typedef struct Student {
    string fn, ln; 
    unsigned mn;

    void disp() {
        cout << "First Name:   " << fn.c_str() << endl;
        cout << "Last Name:    " << ln.c_str() << endl;
        cout << "M-Number:     M" << mn << endl;
        cout << "    ------    " << endl;
    }
} STUDENT_TYPE;


string randomName(int length) {

  char consonents[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
  char vowels[] = {'a','e','i','o','u','y'};

  string name = "";

  int random = rand() % 2;
  int count = 0;

  for(int i = 0; i < length; i++) {

    if(random < 2 && count < 2) {
      name = name + consonents[rand() % 19];
      count++;
    }
    else {
      name = name + vowels[rand() % 5];
      count = 0;
    }

    random = rand() % 2;

  }

  return name;

}

vector<STUDENT_TYPE> init (){

    vector<STUDENT_TYPE> random;
    for (int i = 0; i < 50; i++){
        STUDENT_TYPE *rando = new STUDENT_TYPE;
        rando->fn = randomName(NL);
        rando->ln = randomName(NL);
        rando->mn = rand() % 1000000 + 10000000;
        random.push_back(*rando);
    }
    return random;
}

int partition(List<STUDENT_TYPE> &arr, int low, int high)
{
    string pivot = arr.seeAt(high)->fn;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr.seeAt(j)->fn < pivot)
        {
            i++;
            arr.swap(arr.seeAt(i), arr.seeAt(j));
        }
    }
    arr.swap(arr.seeAt(i + 1), arr.seeAt(high));
    return (i + 1);
}

void quickSort(List<STUDENT_TYPE> &arr, int low, int high) {
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

size_t getMax(List<STUDENT_TYPE> &arr, int n){
    size_t max = arr.seeAt(0)->ln.size();
    for (int i = 1; i < n; i++){
        if (arr.seeAt(i)->ln.size()>max)
            max = arr.seeAt(i)->ln.size();
    }
    return max;
}

vector<STUDENT_TYPE*> countSort(List<STUDENT_TYPE> &arr, int size, size_t k){

    string *b = NULL; int *c = NULL;
    b = new string[size];
    c = new int[257];

    for (int i = 0; i <257; i++)
        c[i] = 0;
     
    for (int j = 0; j <size; j++)
        c[k < arr.seeAt(j)->ln.size() ? (int)(unsigned char)arr.seeAt(j)->ln[k] + 1 : 0]++;

    for (int f = 1; f <257; f++){
        c[f] += c[f - 1];
    }

    for (int r = size - 1; r >= 0; r--){
        b[c[k < arr.seeAt(r)->ln.size() ? (int)(unsigned char)arr.seeAt(r)->ln[k] + 1 : 0] - 1] = arr.seeAt(r)->ln;
        c[k < arr.seeAt(r)->ln.size() ? (int)(unsigned char)arr.seeAt(r)->ln[k] + 1 : 0]--;
    }
    vector<STUDENT_TYPE*> ret;
    for (int l = 0; l < size; l++){
        STUDENT_TYPE* temp = arr.getNode(b[l]);
        ret.push_back(temp);
    }

    return ret;
}


vector<STUDENT_TYPE*> radixSort(List<STUDENT_TYPE> b, int r){
    vector<STUDENT_TYPE*> ret;
    size_t max = getMax(b, r);
    for (size_t digit = max; digit > 0; digit--){
        ret = countSort(b, r, digit - 1);
    }
    return ret;
}


void StringList() {
    List<STUDENT_TYPE> students;
    
    vector<STUDENT_TYPE> random = init();

    cout << "50 Random Names Generated" << endl;

    for (unsigned i = 0; i < 50; i++)
        students.insert(&random[i], true);
    
    cout << "Press 1 for sort by M-number(Bubble sort)\n";
    cout << "      2 for sort by First Name (Quick sort)\n";
    cout << "      3 for sort by Last Name (Radix sort)" << endl;

    char ch;
    cout << "\nYour choice: ";
    cin >> ch;
    cout << endl;

    if (ch == '1') {
        int i, j;
        int s = 50;
        for (i = 0; i < s - 1; i++)
            for (j = 0; j < s - i - 1; j++){
                STUDENT_TYPE* temp1 = students.seeAt(j);
                STUDENT_TYPE* temp2 = students.seeAt(j+1);
               
                if (temp1->mn > temp2->mn)
                    students.swap(temp1, temp2);
            }

        cout << "SORTED LIST: " << endl;
        students.display();
    }

    else if(ch == '2') {
        quickSort(students, 0, 49);
        cout << "SORTED LIST: " << endl;
        students.display();
    }

    else if (ch == '3') {
        cout << "SORTED LIST: " << endl;
        vector<STUDENT_TYPE*> s = radixSort(students, 50);
        for (unsigned i = s.size() - 50; i< s.size(); i++)
            s[i]->disp();
    }

    else cout << "Wrong choice, try again!" << endl;

}

