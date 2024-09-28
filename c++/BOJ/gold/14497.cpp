// BOJ 14497 주난의 난(難) (G4)
//
#include <iostream>
#include <queue>
using namespace std;

int n, m, strtx, strty, dstx, dsty, visited[304][304];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
char a[304][304];

int main() {
    queue<pair<int, int>> q;

    cin >> n >> m;
    cin >> strtx >> strty >> dstx >> dsty;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    int turn = 1;
    
    while(1) {
        fill(&visited[0][0], &visited[0][0] + 304*304, 0);
        q.push({strty, strtx});
        visited[strty][strtx] = 1;

        while(q.size()) {
            int y = q.front().first, x = q.front().second; q.pop();
            if(y == dsty && x == dstx) { cout << turn - 1<< '\n'; return 0; }

            for(int i=0; i<4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(ny<0 || nx<0 || ny>=n || nx>=m || visited[ny][nx]) continue;

                visited[ny][nx] = visited[y][x] + 1;

                if(a[ny][nx] == '0') q.push({ny, nx});
                else {
                    a[ny][nx] = '0';
                }
            }
        }

        turn++;
    }


    return 0;
}
