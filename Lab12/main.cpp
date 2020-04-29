#include <iostream>
#include <array>
#include <vector> 
#include <cstdio>
#include <ctime>
#include <time.h> 
#include<string.h> 




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


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void CountingSort(int a[], int s) {
    int i, j, k;
    int index = 0;
    int min, max;

    min = max = a[0];
    for (i = 1; i < s; i++) {
        min = (a[i] < min) ? a[i] : min;
        max = (a[i] > max) ? a[i] : max;
    }

    k = max - min + 1;
    int* B = new int[k];
    for (i = 0; i < k; i++) B[i] = 0;

    for (i = 0; i < s; i++) B[a[i] - min]++;
    for (i = min; i <= max; i++)
        for (j = 0; j < B[i - min]; j++) a[index++] = i;

    delete[] B;
}


int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void RadixcountSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        RadixcountSort(arr, n, exp);
}

void outputArray(int a[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    srand(time(NULL));

    char ch;
    int size;

    cout << "Enter size of the array! " << endl;
    cout << "a: 10" << endl;
    cout << "b: 100" << endl;
    cout << "c: 500" << endl;
    cout << "d: 5000" << endl;
    cout << "e: 25000" << endl;
    cout << "f: 100000" << endl;

    cin >> ch;

    switch (ch) {
    case 'a':
        cout << "Size 10: " << endl;
        size = 10;
        break;

    case 'b':
        cout << "Size 100: " << endl;
        size = 100;
        break;

    case 'c':
        cout << "Size 500: " << endl;
        size = 500;
        break;

    case 'd':
        cout << "Size 5000: " << endl;
        size = 5000;
        break;

    case 'e':
        cout << "Size 25000: " << endl;
        size = 25000;
        break;


    case 'f':
        cout << "Size 100000: " << endl;
        size = 100000;
        break;
    }


    int a[size];
    for (int i = 0; i < size; i++) { 
        a[i] = rand() % (2 * size);
    }

    int s = sizeof(a) / sizeof(a[0]);







    double durationBubble;
    clock_t startBubble;

    startBubble = clock();

    cout << "\n";
    cout << "Bubble sort: " << endl;
    bubbleSort(a, s);
    durationBubble = (clock() - startBubble) / (double)CLOCKS_PER_SEC;

    cout << "Time for Bubble Sort: " << durationBubble << '\n';



    double durationInsertion;
    clock_t startInsertion;

    startInsertion = clock();

    cout << "\n";
    cout << "Insertion Sort: " << endl;
    insertionSort(a, s);
    

    durationInsertion = (clock() - startInsertion) / (double)CLOCKS_PER_SEC;

    cout << "Time for Insertion Sort: " << durationInsertion << '\n';



    double durationMerge;
    clock_t startMerge;

    startMerge = clock();

    cout << "\n";
    cout << "Merge Sort: " << endl;
    mergeSort(a, 0, s - 1);
    

    durationMerge = (clock() - startMerge) / (double)CLOCKS_PER_SEC;

    cout << "Time for Merge Sort: " << durationMerge << '\n';



    double durationQuick;
    clock_t startQuick;

    startQuick = clock();

    cout << "\n";
    cout << "Quick Sort: " << endl;
    quickSort(a, 0, s - 1);
    

    durationQuick = (clock() - startQuick) / (double)CLOCKS_PER_SEC;

    cout << "Time for quick Sort: " << durationQuick << '\n';



    double durationCounting;
    clock_t startCounting;

    startCounting = clock();

    cout << "\n";
    cout << "Counting Sort: " << endl;
    CountingSort(a, s);
    

    durationCounting = (clock() - startCounting) / (double)CLOCKS_PER_SEC;

    cout << "Time for Counting Sort: " << durationCounting << '\n';



    double durationRadix;
    clock_t startRadix;

    startRadix = clock();

    cout << "\n";
    cout << "Radix Sort: " << endl;
    radixsort(a, s);
    

    durationRadix = (clock() - startRadix) / (double)CLOCKS_PER_SEC;

    cout << "Time for Radix Sort: " << durationRadix << '\n';





}

