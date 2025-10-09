// BOJ 14890 경사로 (G3)
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, l, ret, a[104][104];

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int y = 0; y < n; y++) {
		int cnt = 1, flag = 1, suc = 1, before_num = a[y][0];
		for (int x = 1; x < n; x++) {
			if (abs(before_num - a[y][x]) > 1) { suc = 0; break; }
			if (!flag && cnt >= l) {
				flag = 1;
				cnt = 0;
			}
			if (before_num == a[y][x]) cnt++;

			else {
				if (!flag) { suc = 0; break; }
				if (before_num > a[y][x]) {
					flag = 0, cnt = 1;
				}
				else if (before_num < a[y][x]) {
					if (!flag || cnt < l) { suc = 0; break; }
					cnt = 1;
				}
			}
			before_num = a[y][x];
		}
		if (!flag && cnt >= l) flag = 1;
		if (flag && suc) { ret++; }
	}
	for (int x = 0; x < n; x++) {
		int cnt = 1, flag = 1, suc = 1, before_num = a[0][x];
		for (int y = 1; y < n; y++) {
			if (abs(before_num - a[y][x]) > 1) { suc = 0; break; }
			if (!flag && cnt >= l) {
				flag = 1;
				cnt = 0;
			}
			if (before_num == a[y][x]) cnt++;

			else {
				if (!flag) { suc = 0; break; }
				if (before_num > a[y][x]) {
					flag = 0, cnt = 1;
				}
				else if (before_num < a[y][x]) {
					if (!flag || cnt < l) { suc = 0; break; }
					cnt = 1;
				}
			}
			before_num = a[y][x];
		}
		if (!flag && cnt >= l) flag = 1;
		if (flag && suc) { ret++; }
	}

	cout << ret;


	return 0;
}