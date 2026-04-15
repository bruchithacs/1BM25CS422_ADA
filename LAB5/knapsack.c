#include <stdio.h>


struct Item {
    int value;
    int weight;
    float ratio;
};


void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}


void sortItems(struct Item arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j].ratio < arr[j + 1].ratio) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

float fractionalKnapsack(int capacity, struct Item arr[], int n) {
    float totalValue = 0.0;

    for(int i = 0; i < n; i++) {
        if(capacity >= arr[i].weight) {

            totalValue += arr[i].value;
            capacity -= arr[i].weight;
        } else {

            totalValue += arr[i].ratio * capacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter value and weight of each item:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].value, &arr[i].weight);
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);


    sortItems(arr, n);

    float maxValue = fractionalKnapsack(capacity, arr, n);

    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}
