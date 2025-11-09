#include <bits/stdc++.h>
using namespace std;

// Structure to represent an item
struct Item {
    double weight;
    double value;
};

// Comparison function to sort items by value/weight ratio in descending order
bool compare(Item a, Item b) {
    double r1 = a.value / a.weight;
    double r2 = b.value / b.weight;
    return r1 > r2;
}

// Function to perform Fractional Knapsack using Greedy Method
double fractionalKnapsack(vector<Item> &items, double capacity) {
    // Step 1: Sort items by value-to-weight ratio (descending)
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0; // Total profit

    // Step 2: Iterate through items
    for (auto &item : items) {
        if (capacity <= 0.0)
            break;

        if (item.weight <= capacity) {
            // Take the whole item
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            // Take fractional part of the item
            totalValue += item.value * (capacity / item.weight);
            capacity = 0.0;
        }
    }

    return totalValue;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    // Step 3: Input weights and values
    for (int i = 0; i < n; i++) {
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> items[i].weight;
        cout << "Enter value of item " << i + 1 << ": ";
        cin >> items[i].value;
    }

    double capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Step 4: Compute maximum profit
    double maxProfit = fractionalKnapsack(items, capacity);

    cout << fixed << setprecision(2);
    cout << "\nMaximum Profit in Knapsack: " << maxProfit << endl;

    return 0;
}
