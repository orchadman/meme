#include <stdio.h>

int main() {
    int a[100];
    int i, size, num, position;

    printf("Enter size of the array:");
    scanf("%d", &size);

    printf("Enter elements in array:");
    for (i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to insert:");
    scanf("%d", &num);

    printf("Enter element position:");
    scanf("%d", &position);

    for (i = size; i >= position; i--) {
        a[i] = a[i - 1];
    }

    a[position - 1] = num;
    size++;

    printf("Array element after insertion:");
    for (i = 0; i < size; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}
