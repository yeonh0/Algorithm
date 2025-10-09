// BOJ 14888 연산자 끼워넣기 (S1)
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

// (0, +), (1, -), (2, x), (3, /)
int n, a[14], oper[5];
int maxret = -10000000000, minret = 1000000000;

int cal(int a, int b, int op) {
	if (op == 0) return a + b;
	else if (op == 1) return a - b;
	else if (op == 2) return a * b;
	else if (op == 3) return a / b;

	return 0;
}

void dfs(int result, int count) {
	if (count == n - 1) {
		maxret = max(maxret, result);
		minret = min(minret, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (!oper[i]) continue;
		oper[i]--;
		dfs(cal(result, a[count + 1], i), count + 1);
		oper[i]++;
	}

	return;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < 4; i++) cin >> oper[i];

	vector<int> v;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < oper[i]; j++) {
			v.push_back(i);
		}
	}
	
	do {
		int sum = a[0];
		for (int i = 1; i < n; i++) {
			sum = cal(sum, a[i], v[i - 1]);
		}
		if (maxret < sum) maxret = sum;
		if (minret > sum) minret = sum;
	} while (next_permutation(v.begin(), v.end()));

	dfs(a[0], 0);

	cout << maxret << '\n' << minret;

	return 0;
}