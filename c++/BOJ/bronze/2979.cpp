#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int car_in, car_out;
int sum = 0;
int a[101];

int main() {
    cin >> A >> B >> C;
    for(int i=0; i<3; i++) {
        cin >> car_in >> car_out;
        for(int j=car_in; j<car_out; j++) a[j]++;
    }

    for(int i=1; i<100; i++) {
        if(a[i] == 1) sum += A;
        else if(a[i] == 2) sum += B*2;
        else if(a[i] == 3) sum += C*3;
    }

    cout << sum;

    return 0;
}