#include <iostream>
using namespace std;

int main() {
    int start, stop;

    cout << "Enter starting value for X: ";
    cin >> start;

    cout << "Enter stopping value for X: ";
    cin >> stop;

    int sum = 0;
    for (int X = start; X <= stop; X++) {
        sum += X * X;
    }

    cout << "Sum of X^2: " << sum << endl;

    return 0;
}
