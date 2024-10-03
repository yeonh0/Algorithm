// BOJ 12100 2048 (Easy) (G1)
//
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, ret = 0;
struct BOARD {
    int map[24][24];

    void rotate() {
        int tmp[24][24];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                tmp[i][j] = map[n-j-1][i];
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                map[i][j] =  tmp[i][j];
            }
        }

        return;
    }

    int get_max() {
        int maxvalue = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                maxvalue = max(maxvalue, map[i][j]);
            }
        }

        return maxvalue;
    }

    void up() {
        int tmp[24][24];

        for(int x=0; x<n; x++) {
            int flag = 0, target = -1;
            for(int y=0; y<n; y++) {
                if(map[y][x] == 0) continue;

                if(flag == 1 && map[y][x] == tmp[target][x]) {
                    tmp[target][x] *= 2;
                    flag = 0;
                }
                else {
                    tmp[++target][x] = map[y][x];
                    flag = 1;
                }
            }
            for(++target; target<n; target++) {
                tmp[target][x] = 0;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                map[i][j] = tmp[i][j];
            }
        }

        return;
    }
};

void dfs(BOARD cur, int cnt) {
    if(cnt == 5) {
        ret = max(ret, cur.get_max());
        return;
    }

    for(int i=0; i<4; i++) {
        BOARD next = cur;
        next.up();
        dfs(next, cnt+1);
        cur.rotate();
    }

    return;
}

int main() {
    BOARD board;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board.map[i][j];
        }
    }

    dfs(board, 0);
    cout << ret << '\n';

    return 0;
}