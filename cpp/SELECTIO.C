#include<stdio.h>
#include<malloc.h>

int a[20];

void selection_sort(int n) {
    int imin, i, j, temp;
    for (i = 0; i < n; i++) {
        imin = i;
        for (j = i + 1; j < n; j++) {
            if (a[imin] > a[j]) {
                imin = j;
            }
        }
        temp = a[i];
        a[i] = a[imin];
        a[imin] = temp;
    }
    printf("Successfully sorted using selection sort Algorithm\n");
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter %dth element: ", i);
        scanf("%d", &a[i]);
    }

    selection_sort(n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}
