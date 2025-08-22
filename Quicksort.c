//Experiment QuickSort @Abhishek Hardaha
#include<stdio.h>
#define MAXSIZE 100

int arr[MAXSIZE], size;
void quickSort(int[], int, int);
int partition(int[], int, int);

int main() {
    printf("Enter the no of elements: (Max size %d) -> ", MAXSIZE);
    scanf("%d", &size);
    printf("Enter %d Elements -> ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n List Entered is -> \n");
    for (int f = 0; f < size; f++) {
        printf(" %d ", arr[f]);
    }
    quickSort(arr, 0, size - 1);
    printf("\n Sorted array: \n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Using last element as pivot
    int i = low - 1; // Index of smaller element
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i+1] and pivot (arr[high])
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
