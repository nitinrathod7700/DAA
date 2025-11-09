#include <iostream>
using namespace std;

int stepCount = 0; // global variable to count steps

int fibonacci(int n) {
    stepCount++; // counting function call as one step
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    stepCount = 0;
    int result = fibonacci(n);

    cout << "Fibonacci(" << n << ") = " << result << endl;
    cout << "Total steps (recursive): " << stepCount << endl;

    return 0;
}
