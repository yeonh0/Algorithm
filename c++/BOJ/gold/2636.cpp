// BOJ 2636 치즈 (G4)
//
#include <bits/stdc++.h>
using namespace std;

int n, m, trial, ret, a[104][104], v[104][104];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

vector<pair<int, int>> cheese = {};

void dfs(int y, int x) {
    v[y][x] = 1;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx<0||ny<0||nx>=m||ny>=n||v[ny][nx]!=0) continue;
        if(a[ny][nx] == 1) {
            v[ny][nx] = 1;
            cheese.push_back({ny, nx});
        }
        else if(a[ny][nx] == 0) dfs(ny, nx);
    }
}


int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    while(true) {
        fill(&v[0][0], &v[0][0]+104*104, 0);
        cheese = {};
        dfs(0, 0);
        if(cheese.size() == 0) break;
        ret = cheese.size();
        for(auto it:cheese) {
            a[it.first][it.second] = 0;
        }
        trial++;
    }

    cout << trial << '\n';
    cout << ret;

    return 0;
}

