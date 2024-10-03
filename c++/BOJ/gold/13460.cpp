// BOJ 13460 구슬 탈출 2 (G1)
//
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

struct INFO {
    int ry, rx, by, bx, count;
};

int visited[14][14][14][14] = {0, };
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
char a[14][14];
INFO start;

int bfs() {
    queue<INFO> q;
    int ret = -1;

    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;

    while(q.size()) {
        INFO cur = q.front(); q.pop();
        if(cur.count > 10) break;
        if(a[cur.ry][cur.rx] == 'O' && a[cur.by][cur.bx] != 'O') {
            ret = cur.count;
            break;
        }

        for(int dir=0; dir<4; dir++) {
            int nry = cur.ry, nrx = cur.rx, nby = cur.by, nbx = cur.bx;
            while(true) {
                if(a[nry][nrx] != '#' && a[nry][nrx] != 'O') {
                    nry += dy[dir], nrx += dx[dir];
                }
                else {
                    if(a[nry][nrx] == '#') {
                        nry -= dy[dir], nrx -= dx[dir];
                    }
                    break;
                }
            }
            while(true) {
                if(a[nby][nbx] != '#' && a[nby][nbx] != 'O') {
                    nby += dy[dir], nbx += dx[dir];
                }
                else {
                    if(a[nby][nbx] == '#') {
                        nby -= dy[dir], nbx -= dx[dir];
                    }
                    break;
                }
            }

            if(nby == nry && nbx == nrx) {
                if(a[nby][nbx] != 'O') {
                    int r_dist = abs(nry-cur.ry) + abs(nrx-cur.rx);
                    int b_dist = abs(nby-cur.by) + abs(nbx-cur.bx);
                    if(r_dist < b_dist) {
                        nby -= dy[dir], nbx -= dx[dir];
                    }
                    else {
                        nry -= dy[dir], nrx -= dx[dir];
                    }
                }
            }

            if(!visited[nry][nrx][nby][nbx]) {
                visited[nry][nrx][nby][nbx] = 1;
                INFO next;
                next.ry = nry, next.rx = nrx, next.by = nby, next.bx = nbx;
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }

    return ret;
}

int main() {
    int n, m;
    string s;

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<m; j++) {
            a[i][j] = s[j];
            if(a[i][j] == 'R') { start.ry = i, start.rx = j; }
            if(a[i][j] == 'B') { start.by = i, start.bx = j; }
        }
    }
    start.count = 0;

    int ret = bfs();
    printf("%d", ret);

    return 0;
}