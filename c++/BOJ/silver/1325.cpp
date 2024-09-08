// BOJ 1325 효율적인 해킹 (S1)
//
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, mx, visited[10004], dp[10004];
vector<int> v[10004];

int dfs(int here) {
    visited[here] = 1;
    int ret = 1;

    for(int there : v[here]) {
        if(visited[there]) continue;
        ret += dfs(there);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    while(m--) {
        cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i=1; i<=n; i++) {
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        mx = max(dp[i], mx);
    }

    for(int i=1; i<=n; i++) if(dp[i] == mx) cout << i << " ";

    return 0;
}