#include <stdio.h>

void main()
{
    int a[100]; // Increased size to handle larger input safely
    int i, j, l;
    int key;

    printf("Enter length of the array: ");
    scanf("%d", &l);
    printf("Enter the elements in the array:\n");
    for(i = 0; i < l; i++) {
        scanf("%d", &a[i]);
    }

    // Insertion sort
    for(j = 1; j < l; j++) {
        key = a[j];
        i = j - 1;
        while(i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }

    printf("Sorted array is: ");
    for(i = 0; i < l; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
