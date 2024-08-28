// BOJ 2178 미로 탐색 (S1)
// BFS
#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, ix, iy;
int a[104][104], v[104][104];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

int BFS() {
    queue<pair<int, int>> q;
    v[0][0] = 1;
    q.push({0, 0});

    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        for(int i=0; i<4; i++) {
            ix = x + dx[i], iy = y + dy[i];
            if(iy<0 || iy>=N || ix<0 || ix>=M || a[iy][ix] == 0) continue;
            if(v[iy][ix]) continue;
            v[iy][ix] = v[y][x] + 1;
            q.push({iy, ix});
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) scanf("%1d", &a[i][j]);
    }

    BFS();
    cout << v[N-1][M-1];

    return 0;
}