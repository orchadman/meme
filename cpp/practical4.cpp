#include <stdio.h>

#define MAX_SIZE 100

int searchElement(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; }

int main() {
    int size, searchKey;

    printf("Enter the size of the array (max 100): ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[MAX_SIZE];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &searchKey);

    int result = searchElement(arr, size, searchKey);
    if (result != -1) {
        printf("Element %d found at index %d.\n", searchKey, result);
    } else {
        printf("Element %d not found in the array.\n", searchKey);
    }

    return 0;
}
