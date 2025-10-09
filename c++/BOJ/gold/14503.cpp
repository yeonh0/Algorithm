// BOJ 14503 로봇 청소기 (G5)
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, robot_y, robot_x, dir, map[54][54], visited[54][54];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int sum) {
	bool flag = false;

	// 주변 4칸 조사
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
		if (!map[ny][nx]) {
			flag = true;
			break;
		}
	}

	// 청소되지 않은 빈 칸 없는 경우
	if (!flag) {
		int dir_back = (dir + 2) % 4;
		int ny = y + dy[dir_back], nx = x + dx[dir_back];
		// 뒤가 벽이 아닌 경우
		if (!map[ny][nx]) {
			if (!visited[ny][nx]) {
				visited[ny][nx] = 1;
				dfs(ny, nx, sum+1);
			}
			else dfs(ny, nx, sum);
		}
		else {
			cout << sum;
			return;
		}
	}

	// 청소되지 않은 빈 칸 있는 경우
	else {
		dir = (dir + 3) % 4;
		int ny = y + dy[dir], nx = x + dx[dir];
		if (!map[ny][nx] && !visited[ny][nx]) {
			visited[ny][nx] = 1;
			dfs(ny, nx, sum + 1);
		}
		else {
			dfs(y, x, sum);
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	cin >> robot_y >> robot_x >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = -1;
		}
	}

	if (map[robot_y][robot_x] == 0) {
		visited[robot_y][robot_x] = 1;
		dfs(robot_y, robot_x, 1);
	}
	else {
		dfs(robot_y, robot_x, 0);
	}

	return 0;
}