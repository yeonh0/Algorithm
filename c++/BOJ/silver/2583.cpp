// BOJ 2583 영역 구하기 (S1)
//
#include <bits/stdc++.h>
using namespace std;

int m, n, k, y, x, a[101][101];
bool v[101][101];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
vector<int> d;

void rectangle(int ldx, int ldy, int rux, int ruy) {
    for(int j=ldy; j<ruy; j++) {
        for(int i=ldx; i<rux; i++) {
            a[j][i] = 1;
        }
    }
}

int dfs(int y, int x) {
    int area = 1;
    v[y][x] = 1;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if(ny<0 || nx<0 || ny>=m || nx>=n) continue;
        if(a[ny][nx] == 0 && v[ny][nx] == 0) {
            area += dfs(ny, nx);
        }
    }
    return area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n >> k;
    while(k--) {
        // 왼쪽 아래 꼭짓점 (x, y) 오른쪽 위 꼭짓점 (x, y). 전체: (0, 0) ~ (n, m)
        int ldx, ldy, rux, ruy;
        cin >> ldx >> ldy >> rux >> ruy;
        rectangle(ldx, ldy, rux, ruy);
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(a[i][j] == 0 && v[i][j] == 0) {
                d.push_back(dfs(i, j));
            }
        }
    }
    sort(d.begin(), d.end());
    cout << d.size() << '\n';
    for(int num:d) cout << num << " ";

    return 0;
}