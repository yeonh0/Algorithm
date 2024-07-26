#include "bits/stdc++.h"

using namespace std;

int fact(int a) {
    if (a == 1 || a == 0)
        return 1;
    return a * fact(a-1);
}

// [1, 1, 2, 3, 5, 8, 13, 21, ..]
int fibo(int a) {
    if (a == 0 || a == 1)
        return a;
    return fibo(a-1) + fibo(a-2);
}

int main() {
    int num;
    cin >> num;
    cout << "Factorial(" << num << ") = " << fact(num) << endl;

    cin >> num;
    cout << "Fibonacci(" << num << ") = " << fibo(num) << endl;
}