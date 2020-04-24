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

void mergeArray(int a[], int b, int c, int d){ 
    int i, j, k; 
    int n1 = c - b + 1; 
    int n2 =  d - c; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = a[b + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[c + 1+ j]; 
  
    i = 0;  
    j = 0; 
    k = b; 
    while (i < n1 && j < n2){ 
        if (L[i] <= R[j]){ 
            a[k] = L[i]; 
            i++; 
        } 
        else{ 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1){ 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2){ 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int a[], int left, int right){ 
    if (left < right){ 
        int b = left+(right-left)/2; 
        mergeSort(a, left, b); 
        mergeSort(a, b+1, right); 
  
        mergeArray(a, left, b, right); 
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
    cout << "\n";
    cout << "Merge Sort: " << endl;
    mergeSort(a, 0, s-1);
    outputArray(a,s);
    return 0;  
}