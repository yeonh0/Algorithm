// BOJ 3197 백조의 호수 (P5)
// 
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int max_rc = 1504;

int r, c, x, y, swanx, swany, v_water[max_rc][max_rc], v_swan[max_rc][max_rc];
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
char a[max_rc][max_rc];
queue<pair<int, int>> waterq, water_tempq, swanq, swan_tempq;

bool move_swan() {
	while (swanq.size()) {
		tie(y, x) = swanq.front(); swanq.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || v_swan[ny][nx]) continue;
			v_swan[ny][nx] = 1;

			if (a[ny][nx] == 'L') return true;
			if (a[ny][nx] == 'X') swan_tempq.push({ ny, nx });
			if (a[ny][nx] == '.') swanq.push({ ny, nx });
		}
	}

	return false;
}

void melt_water() {
	while (waterq.size()) {
		tie(y, x) = waterq.front(); waterq.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || v_water[ny][nx]) continue;
			v_water[ny][nx] = 1;

			if (a[ny][nx] == '.') waterq.push({ ny, nx });
			if (a[ny][nx] == 'X') {
				water_tempq.push({ ny, nx });
				a[ny][nx] = '.';
			}
		}
	}

	return;
}

void clearQ(queue<pair<int, int>>& q) {
	queue<pair<int, int>> empty;
	swap(q, empty);

	return;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'L') { swany = i; swanx = j; }
			if (a[i][j] == '.' || a[i][j] == 'L') {
				waterq.push({ i, j });
				v_water[i][j] = 1;
			}
		}
	}

	swanq.push({ swany, swanx });
	v_swan[swany][swanx] = 1;


	int turn = 0;
	while (true) {
		if (move_swan()) break;

		melt_water();
		waterq = water_tempq;
		swanq = swan_tempq;
		clearQ(water_tempq); clearQ(swan_tempq);
		turn++;
	}

	cout << turn << '\n';

	return 0;
}