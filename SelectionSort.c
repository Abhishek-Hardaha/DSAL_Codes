// Experiment 2.2 SelectionSort @Abhishek Hardaha
#include<stdio.h>
#define MAXSIZE 100

void SelectionSort(int[], int, int);
void swap(int*, int*);
void swapArth(int*, int*);

int Arr[MAXSIZE], size, order;

int main(){
    printf("Selection Sort - ");
    printf("Enter the no of elements: (Max size %d) -> ", MAXSIZE);

    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        printf("Enter Element %d -> ", i+1);
        scanf("%d", &Arr[i]);
    }
    printf("Ascending or Descending (1/2) -> ");
    scanf("%d", &order);

    SelectionSort(Arr, size, order);
    return 0;
}

// Selection Sort Function
void SelectionSort(int Arr[], int n, int order){
    int i, j, minIndex;

    if (order != 2) {
        if (order != 1) {
            printf("Invalid Order selected, Sorting in Ascending Order\n");
        }
        // Ascending Order
        for(i = 0; i < n-1; i++){
            minIndex = i;
            for(j = i+1; j < n; j++){
                if(Arr[j] < Arr[minIndex])
                    minIndex = j;
            }
            if(minIndex != i)
                swap(&Arr[i], &Arr[minIndex]);
        }
    }
    if (order == 2){
        printf("Sorting in Descending Order\n");
        // Descending Order
        for(i = 0; i < n-1; i++){
            minIndex = i;
            for(j = i+1; j < n; j++){
                if(Arr[j] > Arr[minIndex])
                    minIndex = j;
            }
            if(minIndex != i)
                swapArth(&Arr[i], &Arr[minIndex]);
        }
    }

    printf("\n List after sorting -> \n");
    for(int f = 0; f < n; f++){
        printf(" %d ", Arr[f]);
    }
    printf("\n");
}

// Swap using temp variable
void swap(int* num1, int* num2){
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

// Swap using arithmetic operations
void swapArth(int* num1, int* num2){
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

// (Unused) Swap using bitwise XOR
void swapBit(int* num1, int* num2){
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}
