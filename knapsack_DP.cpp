#include <bits/stdc++.h>
using namespace std;

// Recursive function to solve 0/1 Knapsack problem
int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    // Base case: no items left or capacity is 0
    if (n < 0 || W <= 0)
        return 0;

    // If weight of the nth item is greater than capacity, skip it
    if (wt[n] > W)
        return knapsack(W, wt, val, n - 1);

    // Otherwise, choose the maximum of:
    // 1. Including the nth item
    // 2. Excluding the nth item
    else
        return max(
            val[n] + knapsack(W - wt[n], wt, val, n - 1),
            knapsack(W, wt, val, n - 1)
        );
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    // Input item weights and values
    for (int i = 0; i < n; i++) {
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> wt[i];
        cout << "Enter value of item " << i + 1 << ": ";
        cin >> val[i];
    }

    int W;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    // Call recursive function
    int result = knapsack(W, wt, val, n - 1);

    cout << "\nMaximum value in Knapsack: " << result << endl;

    return 0;
}
