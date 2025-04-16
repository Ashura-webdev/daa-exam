#include <stdio.h>

void merge(int a[], int l, int m, int r) {
    int i = l, j = m+1, k = 0, b[100];
    while(i <= m && j <= r)
        b[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    while(i <= m) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(i = l, k = 0; i <= r; i++, k++)
        a[i] = b[k];
}

void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int m = (l + r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[100], n, k, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    mergeSort(a, 0, n - 1);
    if(k >= 1 && k <= n)
        printf("The %d-th smallest element is: %d\n", k, a[k - 1]);
    else
        printf("Invalid value of k\n");

    return 0;
}
