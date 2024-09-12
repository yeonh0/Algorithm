// BOJ 6234 인구 이동 (G4)
//
#include <bits/stdc++.h>
using namespace std;

int n, l, r, cnt = 0, a[54][54], visited[54][54];
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };

int bfs(int py, int px) {
    int x, y, nx, ny, _sum = a[py][px];
    vector<pair<int, int>> v;
    queue<pair<int, int>> q;
    visited[py][px] = 1;
    q.push({py, px});

    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
            if (l <= abs(a[ny][nx] - a[y][x]) && abs(a[ny][nx] - a[y][x]) <= r) {
                _sum += a[ny][nx];
                visited[ny][nx] = 1;
                q.push({ ny, nx });
                v.push_back({ ny, nx });
            }
        }
    }
    if (!v.size()) return 0;
    v.push_back({ py, px });
    _sum = _sum / v.size();
    for (pair<int, int> it : v) {
        a[it.first][it.second] = _sum;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    while (true) {
        int move = 0;
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    move += bfs(i, j);
                }
            }
        }

        if (!move) break;
        cnt++;
    }

    cout << cnt;

    return 0;
}