#include <bits/stdc++.h>
using namespace std;

int n, tmp, cnt, mx;
vector<int> v;

// 최대 값이 얼마냐?
void go(int idx, int sum) {
    if(mx == 10) return;    // 백트래킹 : 경우의 수 가지 치기
    if(idx == n) {
        mx = max(mx, sum%11);
        cnt++;
        return;
    }
 
    go(idx+1, sum+v[idx]);
    go(idx+1, sum);
}

// 해당하는 경우가 몇 가지냐?
int go1(int idx, int sum) {
    if(idx == n) {
        if(sum > 10) return 1;
        else return 0;
    }

    return go1(idx+1, sum+v[idx]) + go1(idx+1, sum);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    go(0, 0);
    cout << cnt << '\n';
    cout << mx;

    return 0;
}