// BOJ 2589 보물섬 (G5)
//
#include <bits/stdc++.h>
using namespace std;

int m, n, result = 0, visited[54][54];
char a[54][54];
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

int bfs(int paramy, int paramx) {
    int x, y, nx, ny, ret = 0;
    visited[paramy][paramx] = 1;
    q.push({ paramy, paramx });

    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            if (a[ny][nx] == 'L') {
                ret = visited[ny][nx];
                q.push({ ny, nx });
            }
        }
    }

    return ret-1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'L') {
                fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
                result = max(result, bfs(i, j));
            }
        }
    }

    cout << result;

    return 0;
}