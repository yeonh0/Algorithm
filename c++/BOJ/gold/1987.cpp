// BOJ 1987 알파벳 (G4)
// 
#include <iostream>
#include <vector>
using namespace std;

int visited[30];
int r, c, ret, x = 0, y = 0;
char a[24][24];
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };

void dfs(int m, int n, int cnt) {
	bool flag = false;

	for (int i = 0; i < 4; i++) {
		int ny = m + dy[i], nx = n + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (visited[a[ny][nx] - 'A']) continue;
		
		visited[a[ny][nx] - 'A'] = 1;
		dfs(ny, nx, cnt + 1);
		visited[a[ny][nx] - 'A'] = 0;
		flag = true;
	}
	if (!flag) ret = max(ret, cnt);

	return;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}

	visited[a[0][0] - 'A'] = 1;
	dfs(0, 0, 1);

	cout << ret;

	return 0;
}