// BOJ 14499 주사위 굴리기 (G4)
//
#include <iostream>
using namespace std;

int n, m, x, y, k;
int map[24][24], cmd[1004];
int dy[4] = { 0, 0, -1, 1 }, dx[4] = { 1, -1, 0, 0 };
int dice[6] = { 0, 0, 0, 0, 0, 0 };

void roll(int dir) {
	if (dir == 0) {
		int tmp = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = dice[0];
		dice[0] = tmp;
	}
	else if (dir == 1) {
		int tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = tmp;
	}
	else if (dir == 2) {
		int tmp = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[0];
		dice[0] = tmp;
	}
	else if (dir == 3) {
		int tmp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = tmp;
	}
}

int main() {
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}

	for (int i = 0; i < k; i++) {
		cin >> cmd[i];
		cmd[i]--;
	}

	// 지도=0: 바닥면이 칸에 복사 , 지도!=0: 칸이 바닥에 복사, 칸=0
	// 지도 밖 이동 명령은 무시, 출력도 X
	int time = -1;
	while (time<k-1) {
		time++;
		y += dy[cmd[time]], x += dx[cmd[time]];
		if (y < 0 || x < 0 || y >= n || x >= m) {
			y -= dy[cmd[time]], x -= dx[cmd[time]];
			continue;
		}
		roll(cmd[time]);

		if (map[y][x] == 0) {
			map[y][x] = dice[5];
		}
		else {
			dice[5] = map[y][x];
			map[y][x] = 0;
		}
		cout << dice[0] << '\n';
	}

	return 0;
}