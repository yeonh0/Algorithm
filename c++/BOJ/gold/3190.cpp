// BOJ 3190 뱀 (G4)
//
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, k, l;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1 , 0};
int map[104][104], snake_y[10004], snake_x[10004];
char cmd[10004];

int main() {
    cin >> n;
    cin >> k;
    for(int i=0; i<k; i++) {
        int y, x;
        scanf("%d %d", &y, &x);
        map[y-1][x-1] = 1;
    }

    cin >> l;
    for(int i=0; i<l; i++) {
        int time; char c;
        scanf("%d %c", &time, &c);
        cmd[time] = c;
    }

    int time = 0, dir = 0;
    int head_y = 0, head_x = 0, tail_node = time;
    map[0][0] = -1, snake_y[time] = head_y, snake_x[time] = head_x;

    while(true) {
        time++;
        head_y += dy[dir], head_x += dx[dir];
        snake_y[time] = head_y, snake_x[time] = head_x;
        if(head_y<0||head_x<0||head_y>=n||head_x>=n||map[head_y][head_x]==-1) break;
        
        if(map[head_y][head_x] == 0) {
            int tail_y = snake_y[tail_node], tail_x = snake_x[tail_node];
            map[tail_y][tail_x] = 0;
            tail_node++;
        }
        map[head_y][head_x] = -1;

        if(cmd[time] == 'D') dir = (dir + 1) % 4;
        else if(cmd[time] == 'L') dir = (dir + 3) % 4;
    }

    cout << time << '\n';

    return 0;
}