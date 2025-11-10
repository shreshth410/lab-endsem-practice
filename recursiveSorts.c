#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n){
    if (n == 1) return;

    for (int i = 0; i < n; i++){
        if (arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    bubbleSort(arr, n-1);
}

void selectionSort(int arr[], int n, int index){
    if (index == n) return;

    int minind = index;

    for (int i = index; i < n; i++){
        if (arr[i] < arr[minind]){
            minind = i;
        }
    }

    int temp = arr[index];
    arr[index] = arr[minind];
    arr[minind] = temp;

    selectionSort(arr, n, index+1);
}

void insertionSort(int arr[], int n){
    if (n == 1) return;

    insertionSort(arr, n-1);

    int last = arr[n-1];
    int j = n-2;

    while (j >= 0 && arr[j] > last){
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = last;
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
}

int main(){
    int arr[] = {5, 4, 3, 2, 1, 0};

    int n  = sizeof(arr)/sizeof(arr[0]);

    int arrB[6];
    int arrS[6];
    int arrI[6];

    for (int i = 0; i < n; i++){
        arrB[i] = arr[i];
        arrS[i] = arr[i];
        arrI[i] = arr[i];
    }

    bubbleSort(arrB, n);
    printArray(arrB, n);
    printf("\n");

    selectionSort(arrS, n, 0);
    printArray(arrS, n);
    printf("\n");

    insertionSort(arrI, n);
    printArray(arrI, n);
    printf("\n");
}