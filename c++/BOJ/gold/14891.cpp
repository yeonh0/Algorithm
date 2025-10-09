// BOJ 14891 톱니바퀴 (G5)
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int k, wheel[5][10], v[10];
string s;

void rotate(int num, int dir) {
	int tmp;
	int left = num - 1, right = num + 1;

	if (left >= 0 && !v[left]) {
		v[left] = 1;
		if (wheel[num][6] != wheel[left][2]) {
			rotate(left, dir * (-1));
		}

	}

	if (right < 4 && !v[right]) {
		v[right] = 1;
		if (wheel[num][2] != wheel[right][6]) {
			rotate(right, dir * (-1));
		}
	}

	if (dir == 1) {
		tmp = wheel[num][7];
		for (int i = 7; i > 0; i--) {
			wheel[num][i] = wheel[num][i-1];
		}
		wheel[num][0] = tmp;
	}
	else {
		tmp = wheel[num][0];
		for (int i = 0; i < 7; i++) {
			wheel[num][i] = wheel[num][i + 1];
		}
		wheel[num][7] = tmp;
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			wheel[i][j] = s[j] - '0';
		}
	}

	cin >> k;
	while (k--) {
		fill(&v[0], &v[0] + 8, 0);
		int num, dir;
		cin >> num >> dir;

		v[num - 1] = 1;
		rotate(num-1, dir);
	}

	int ret = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == 1) ret += pow(2, i);
	}
	cout << ret;

	return 0;
}