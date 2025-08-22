//Experiment MergeSort @Abhishek Hardaha
#include<stdio.h>
#define MAXSIZE 100

int arr[MAXSIZE], size;
void mergeSort(int[],int,int);
void merge(int[],int,int,int);
int main(){\

    printf("Enter the no of elements: (Max size %d) -> ",MAXSIZE);
    scanf("%d",&size);
    printf("Enter %d Elements -> ", size);
    for(int i = 0; i< size; i++){
        scanf("%d",&arr[i]);
    }
    printf("\n List Entered is -> \n");
    for(int f = 0; f< size; f++){
        printf(" %d ", arr[f]);}
    mergeSort(arr, 0, size - 1);
    printf("\n Sorted array: \n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    while (i < n1) {
        arr[k++] = leftArr[i++];
    }
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}