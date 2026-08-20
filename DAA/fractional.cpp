#include <stdio.h>

struct Item {
    int profit;
    int weight;
    float ratio;
};

// Function to sort items by profit/weight ratio in descending order
void sortItems(struct Item items[], int n) {
    int i, j;
    struct Item temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(items[j].ratio < items[j + 1].ratio) {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;
    float totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input profit and weight
    for(int i = 0; i < n; i++) {
        printf("\nEnter profit and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("\nEnter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items
    sortItems(items, n);

    printf("\nItems selected:\n");

    for(int i = 0; i < n; i++) {
        if(capacity == 0)
            break;

        if(items[i].weight <= capacity) {
            // Take whole item
            printf("Take 100%% of item (Profit=%d, Weight=%d)\n",
                   items[i].profit, items[i].weight);

            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        }
        else {
            // Take fraction of item
            float fraction = (float)capacity / items[i].weight;

            printf("Take %.2f%% of item (Profit=%d, Weight=%d)\n",
                   fraction * 100, items[i].profit, items[i].weight);

            totalProfit += items[i].profit * fraction;
            capacity = 0;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}