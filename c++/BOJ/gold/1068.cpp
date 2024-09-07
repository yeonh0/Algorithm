// BOJ 1068 트리 (G5)
//
#include <bits/stdc++.h>
using namespace std;
vector<int> v[50];

int n, tmp, cnt, root;

void dfs1(int node) {
    if(node == tmp) return;
    if (v[node].empty()) {
        cnt++;
        return;
    }
    for (int num : v[node]) {
        dfs1(num);
    }
    if(v[node].size() == 1 && v[node][0] == tmp) {
        cnt++;
    }
}

int dfs2(int here) {
    int ret = 0, child = 0;
    for(int there : v[here]) {
        if(there == tmp) continue;
        ret += dfs2(there);
        child++;
    }
    if(child == 0) return 1;
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == -1) root = i;
        else v[tmp].push_back(i);
    }

    cin >> tmp;
    if(tmp == root) cout << 0;
    else {
        dfs1(root);
        cout << cnt;
    }

    return 0;
}