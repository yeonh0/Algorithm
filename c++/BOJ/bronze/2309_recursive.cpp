#include <bits/stdc++.h>
using namespace std;

int a[9];
int n=9, r=7;

void print() {
    for(auto i:a) cout << i << " ";
    cout << '\n';
}

void solve() {
    int sum = 0;
    for(int i=0; i<7; i++) sum += a[i];

    if(sum == 100) {
        sort(a, a+7);
        for(int i=0; i<7; i++) cout << a[i] << endl;
        exit(1);
    }
}

void makepermute(int n, int r, int depth) {
    if(depth == r) {
        solve();
        return;
    }

    for(int i=depth; i<n; i++) {
        swap(a[i], a[depth]);
        makepermute(9, 7, depth+1);
        swap(a[i], a[depth]);
    }
}

int main() {
    for(int i=0; i<9; i++) cin >> a[i];
    makepermute(n, r, 0);

    return 0;
}