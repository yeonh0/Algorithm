// BOJ 2828 사과 담기 게임 (S5)
//
#include <bits/stdc++.h>
using namespace std;

int n, m, j, bas, ret, a[21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    cin >> j;
    for(int i=0; i<j; i++) {
        cin >> a[i];
    }

    bas = 1;
    for(int i=0; i<j; i++) {
        // 이동 X
        if(bas <= a[i] && a[i] <= bas+m-1) {
            continue;
        }

        // 왼쪽으로 이동
        if(bas > a[i]) {
            ret += bas - a[i];
            bas = a[i];
        }

        // 오른쪽으로 이동
        else {
            ret += a[i] - (bas+m-1);
            bas += a[i] - (bas+m-1);
        }
    }

    cout << ret;

    return 0;
}