// BOJ 4179 불! (G3)
//
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int r, c, x, y, jx, jy, ret, firecheck[1004][1004], jcheck[1004][1004];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
char a[1004][1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue<pair<int, int>> q;
    fill(&firecheck[0][0], &firecheck[0][0]+1004*1004, INF);
    
    cin >> r >> c;

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'J') {
                jy = i; jx = j;
            }
            else if(a[i][j] == 'F') {
                q.push({i, j});
                firecheck[i][j] = 1;
            }
        }
    }

    // Fire
    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(ny<0||nx<0||ny>=r||nx>=c||firecheck[ny][nx]!=INF||a[ny][nx]=='#') continue;
            firecheck[ny][nx] = firecheck[y][x] + 1;
            q.push({ny, nx});
        }
    }

    // J
    q.push({jy, jx});
    jcheck[jy][jx] = 1;
    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        if(y==0||y==r-1||x==0||x==c-1) {
            ret = jcheck[y][x];
            break;
        }

        for(int i=0; i<4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(ny<0||nx<0||ny>=r||nx>=c||jcheck[ny][nx]||a[ny][nx]=='#') continue;
            if(jcheck[y][x] + 1 >= firecheck[ny][nx]) continue;
            jcheck[ny][nx] = jcheck[y][x] + 1;
            q.push({ny, nx});
            
        }
    }

    if(ret) cout << ret;
    else cout << "IMPOSSIBLE ";

    return 0;
}