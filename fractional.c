#include <stdio.h>

struct Item {
    int w, v;
};

void sort(struct Item a[], int n) {
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if((float)a[j].v/a[j].w > (float)a[i].v/a[i].w) {
                struct Item t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}

int main() {
    struct Item a[100];
    int n, i, W;
    float total = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and value of each item:\n");
    for(i = 0; i < n; i++)
        scanf("%d%d", &a[i].w, &a[i].v);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    sort(a, n);

    for(i = 0; i < n && W > 0; i++) {
        if(a[i].w <= W) {
            total += a[i].v;
            W -= a[i].w;
        } else {
            total += (float)a[i].v * W / a[i].w;
            break;
        }
    }

    printf("Maximum value: %.2f\n", total);
    return 0;
}
