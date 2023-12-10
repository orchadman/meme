#include <stdio.h>
#include <stdlib.h>

int *arr;
int SIZE = 10;

void merge(int beg, int mid, int end) {
    int i = beg, j = mid + 1, index = beg, temp[10], K;

    while ((i <= mid) && (j <= end)) {
	if (arr[i] < arr[j]) {
	    temp[index] = arr[i];
	    i++;
	} else {
	    temp[index] = arr[j];
	    j++;
	}
	index++;
    }

    if (i > mid) {
	while (j <= end) {
	    temp[index] = arr[j];
	    j++;
	    index++;
	}
    } else {
	while (i <= mid) {
	    temp[index] = arr[i];
	    i++;
	    index++;
	}
    }

    for (K = beg; K < index; K++) {
	arr[K] = temp[K];
    }
}

void mergeSort(int beg, int end) {
    int mid;
    if (beg < end) {
	mid = (beg + end) / 2;
	mergeSort(beg, mid);
	mergeSort(mid + 1, end);
	merge(beg, mid, end);
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
	printf("Enter %dth element: ", i);
	scanf("%d", &arr[i]);
    }

    mergeSort(0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
	printf("%d\n", arr[i]);
    }

    free(arr); // Don't forget to free the allocated memory

    return 0;
}
