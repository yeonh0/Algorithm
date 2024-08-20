#include <bits/stdc++.h>
using namespace std;

int a[100004], b, c, psum[100004], n, m;

int main() {
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }

    // 1. 단순 합 : O(N*M) => Max(O) = 100억
    for(int i=1; i<=m; i++) {
        cin >> b >> c;
        int sum = 0;
        for(int j=b; j<=c; j++) {
            sum += a[j];
        }
        cout << sum << endl;;
    }

    // 2. 누적 합
    for(int i=1; i<=m; i++) {
        cin >> b >> c;
        cout << psum[c] - psum[b-1] << endl;
    }

    return 0;
}