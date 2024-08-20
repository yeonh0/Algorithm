#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, myarr[104][104];
bool visited[104][104];
int dy[] = {-1, 0, 1, 0}; int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x] = 1;

    for(int i=0; i<4; i++){
        int ny = y + dy[i]; int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(!visited[ny][nx] && myarr[ny][nx]) dfs(ny, nx);
    }
}

int main() {
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> myarr[i][j];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && myarr[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}