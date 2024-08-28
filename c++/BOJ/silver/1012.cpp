// BOJ 1012 유기농 배추 (S2)
// DFS
#include <bits/stdc++.h>
using namespace std;

int t, m, n, k, x, y, cnt, a[51][51];
bool v[51][51];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
    v[y][x] = 1;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(nx<0 || ny<0 || nx>=m || ny>=n || a[ny][nx] == 0) continue;
        if(!v[ny][nx]) dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> m >> n >> k;
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&v[0][0], &v[0][0] + 51 * 51, 0);
        cnt = 0;

        while(k--) {
            cin >> x >> y;
            a[y][x] = 1;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(a[i][j] == 1 && v[i][j] == 0) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }


    return 0;
}