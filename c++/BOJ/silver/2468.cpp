// BOJ 2468 안전 영역 (S1)
//
#include <bits/stdc++.h>
using namespace std;

int n, cnt, max_cnt, a[101][101], b[101][101];
bool v[101][101];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
    v[y][x] = 1;

    for(int i=0; i<4; i++) {
        int ny = y + dy[i]; int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || b[ny][nx] == 0) continue;
        if(!v[ny][nx]) dfs(ny, nx); 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    for(int k=0; k<101; k++) {
        cnt = 0;
        fill(&b[0][0], &b[0][0] + 101 * 101, 0);
        fill(&v[0][0], &v[0][0] + 101 * 101, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(a[i][j] > k) b[i][j] = 1;
                else b[i][j] = 0;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(b[i][j] == 1 && v[i][j] == 0) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        if(cnt > max_cnt) max_cnt = cnt;
    }
    cout << max_cnt;

    return 0;
}