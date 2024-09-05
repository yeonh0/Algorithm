// BOJ 14502 연구소 (G4)
//
#include <bits/stdc++.h>
using namespace std;

int n, m, ret, a[10][10], v[10][10];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> virus, wall;

void dfs(int y, int x) {
    for(int i=0; i<4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx<0||ny<0||nx>=m||ny>=n||a[ny][nx]==1||v[ny][nx]==1) continue;
        if(a[ny][nx] == 0) {
            v[ny][nx]=1;
            dfs(ny, nx);
        }
    }
}

int solve() {
    int ret = 0;
    fill(&v[0][0], &v[0][0]+10*10, 0);

    for(int i=0; i<virus.size(); i++) {
        v[virus[i].first][virus[i].second] = 1;
        dfs(virus[i].first, virus[i].second);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!v[i][j] && !a[i][j]) ret++;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) virus.push_back({i, j});
            if(a[i][j] == 0) wall.push_back({i, j});
        }
    }

    for(int i=0; i<wall.size(); i++) {
        for(int j=i+1; j<wall.size(); j++) {
            for(int k=j+1; k<wall.size(); k++) {
                a[wall[i].first][wall[i].second] = 1;
                a[wall[j].first][wall[j].second] = 1;
                a[wall[k].first][wall[k].second] = 1;
                ret = max(ret, solve());
                a[wall[i].first][wall[i].second] = 0;
                a[wall[j].first][wall[j].second] = 0;
                a[wall[k].first][wall[k].second] = 0;
            }
        }
    }

    cout << ret;

    return 0;
}