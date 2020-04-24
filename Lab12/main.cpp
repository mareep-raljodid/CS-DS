#include <iostream>

using namespace std; 
  
void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  
  
void bubbleSort(int a[], int s){  
    int i, j;  
    for (i = 0; i < s-1; i++)      
      
    for (j = 0; j < s-i-1; j++)  
        if (a[j] > a[j+1])  
            swap(&a[j], &a[j+1]);  
}  

void insertionSort(int a[], int s){  
    int i, k, j;  
    for (i = 1; i < s; i++){  
        k = a[i];  
        j = i - 1;  
  
        while (j >= 0 && a[j] > k){  
            a[j + 1] = a[j];  
            j = j - 1;  
        }  
        a[j + 1] = k;  
    }  
} 
  
void outputArray(int a[], int size){  
    int i;  
    for (i = 0; i < size; i++)  
        cout << a[i] << " ";  
    cout << endl;  
}  
  
int main(){  
    int a[] = {64, 34, 25, 12, 22, 11, 90};  
    int s = sizeof(a)/sizeof(a[0]); 
    cout << "Bubble sort: " << endl;
    bubbleSort(a,s);   
    outputArray(a,s); 
    cout << "\n";
    cout << "Insertion Sort: " << endl;
    insertionSort(a,s);
    outputArray(a,s);
    return 0;  
}