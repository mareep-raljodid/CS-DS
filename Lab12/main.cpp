#include <iostream>
#include <array>
#include <vector> 
#include <cstdio>
#include <ctime>
#include<string.h> 
#define RANGE 100



using namespace std;

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int a[], int s) {
    int i, j;
    for (i = 0; i < s - 1; i++)

        for (j = 0; j < s - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
}

void insertionSort(int a[], int s) {
    int i, k, j;
    for (i = 1; i < s; i++) {
        k = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = k;
    }
}

void mergeArray(int a[], int b, int c, int d) {
    int i, j, k;
    int n1 = c - b + 1;
    int n2 = d - c;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[b + i];
    for (j = 0; j < n2; j++)
        R[j] = a[c + 1 + j];

    i = 0;
    j = 0;
    k = b;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int b = left + (right - left) / 2;
        mergeSort(a, left, b);
        mergeSort(a, b + 1, right);

        mergeArray(a, left, b, right);
    }
}

void countingSort(int a[]){

    char out[sizeof(a)];

    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));


    for (i = 0; a[i]; ++i)
        ++count[a[i]];


    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];


    for (i = 0; a[i]; ++i){
        out[count[a[i]] - 1] = a[i];
        --count[a[i]];
    }

    for (i = 0; a[i]; ++i)
        a[i] = out[i];
}

int getMax(int a[], int n){
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}

void countSort(int a[], int n, int ex){
    int output[n];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(a[i] / ex) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--){
        output[count[(a[i] / ex) % 10] - 1] = a[i];
        count[(a[i] / ex) % 10]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}


void radixsort(int a[], int n){
    int m = getMax(a, n);

    for (int ex = 1; m / ex > 0; ex *= 10)
        countSort(a, n, ex);
}

int part (int a[], int low, int high){  
    int p = a[high];  
    int i = (low - 1);  
  
    for (int j = low; j <= high - 1; j++){   
        if (a[j] < p){  
            i++; 
            swap(&a[i], &a[j]);  
        }  
    }  
    swap(&a[i + 1], &a[high]);  
    return (i + 1);  
} 

void quickSort(int a[], int low, int high){  
    if (low < high){  
        int index = part(a, low, high);  
        quickSort(a, low, index - 1);  
        quickSort(a, index + 1, high);  
    }  
}
  
void outputArray(int a[], int size){  
    int i;  
    for (i = 0; i < size; i++)  
        cout << a[i] << " ";  
    cout << endl;  
}  

int main() {
    //10 100 500 5000 25000 100000

    for (int i; i < 10; i++) {


    }

    for (int i; i < 100; i++) {


    }

    for (int i; i < 500; i++) {


    }

    for (int i; i < 5000; i++) {


    }

    for (int i; i < 25000; i++) {


    }

    for (int i; i < 100000; i++) {


    }

    int a[] = { 64, 34, 25, 12, 22, 11, 90 };




    int s = sizeof(a) / sizeof(a[0]);


    cout << "Bubble sort: " << endl;
    bubbleSort(a, s);
    outputArray(a, s);

    cout << "\n";
    cout << "Insertion Sort: " << endl;
    insertionSort(a, s);
    outputArray(a, s);

    cout << "\n";
    cout << "Merge Sort: " << endl;
    mergeSort(a, 0, s - 1);
    outputArray(a, s);

    cout << "\n";
    cout << "Quick Sort: " << endl;
    quickSort(a, 0, s - 1);
    outputArray(a, s);

    cout << "\n";
    cout << "Counting Sort: " << endl;
    countingSort(a);
    outputArray(a, s);

    cout << "\n";
    cout << "Radix Sort: " << endl;
    radixsort(a, s);
    outputArray(a, s);


    return 0;
}