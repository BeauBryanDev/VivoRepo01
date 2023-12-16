#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int start, int end);
void JustMerge(int arr[], int b1, int mid, int b2);

int main(void) {

    int n;
    printf("Wellcome to Merge_Sort_Algorithm.\n");
    printf("Please, Type n as the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Please, Enter all the Elements on your New Array below\n");
    
    for (int i = 0; i < n; i++) {
        printf("type position ( %d ) as: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("This Sorted Array :\n\n[ ");

    for (int i = 0; i < n; i++) {
        printf(" %d ,", arr[i]);
    }
    printf("]\n'It is Sorted Now'\n");
    printf("V¿Cheeers\n");

    return 0;
}

void mergeSort(int arr[], int start, int end) {
    int mid;

    if (start < end) {
        mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        JustMerge(arr, start, mid, end);
    }
}

void JustMerge(int arr[], int b1, int mid, int b2) {
    int nleft = (mid - b1 + 1);
    int nright = (b2 - mid);

    int left_arr[nleft];
    int right_arr[nright];

    for (int i = 0; i < nleft; i++) {

        left_arr[i] = arr[b1 + i];
    }

    for (int j = 0; j < nright; j++) {

        right_arr[j] = arr[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int p;

    for (p = b1; p <= b2; p++) {

        if (i < nleft && (j >= nright || left_arr[i] <= right_arr[j])) {
            arr[p] = left_arr[i++];
        } else {
            arr[p] = right_arr[j++];
        }
    }
}
