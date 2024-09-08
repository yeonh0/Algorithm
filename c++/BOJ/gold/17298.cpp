// BOJ 17298 오큰수 (G4)
// 짝짓기 -> 스택
#include <bits/stdc++.h>
using namespace std;

int n, mx, a[1000004], ans[1000004];
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    memset(ans, -1, sizeof(ans));

    for(int i=0; i<n; i++) {
        cin >> a[i];

        while(!stk.empty() && a[stk.top()] < a[i]) {
            ans[stk.top()] = a[i];
            stk.pop();
        }
    
        stk.push(i);
    }

    for(int i=0; i<n; i++) cout << ans[i] << " ";

    return 0;
}