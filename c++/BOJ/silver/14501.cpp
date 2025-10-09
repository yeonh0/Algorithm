// BOJ 14501 퇴사 (S3)
// 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, ret, t[17], p[17], ans[17];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int c_t, c_p;
		cin >> c_t >> c_p;
		t[i] = c_t, p[i] = c_p;
	}

	for (int i = n + 1; i > 0; i--) {
		for (int j = n + 1; j > i; j--) {
			ans[i] = max(ans[i], ans[j]);
		}
		if (i + t[i] <= n + 1) {
			ans[i] = max(ans[i], ans[i + t[i]] + p[i]);
		}
	}

	for (int i = 0; i < n + 1; i++) {
		ret = max(ret, ans[i]);
	}
	cout << ret << '\n';

	return 0;
}