#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int c_start, c_end;
int a[101];
int sum=0;

int main() {
    cin >> A >> B >> C;
    for(int i=0; i<3; i++) {
        cin >> c_start >> c_end;
        for(int j=c_start; j<c_end; j++)
            a[j]++;
    }

    for(int i=0; i<101; i++) {
        if(a[i] == 1) sum += A;
        else if(a[i] == 2) sum += B * 2;
        else if(a[i] == 3) sum += C * 3;
    }

    cout << sum << endl;
    return 0;
}