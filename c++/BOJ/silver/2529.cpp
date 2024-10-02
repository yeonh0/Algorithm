// BOJ 2529 부등호 (S1)
// string 크기 비교: vector 정렬
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int m, visited[10];
char ch, a[10];
vector<string> ret;

bool good(char x, char y, char ch) {
	if (ch == '<' && x < y) return true;
	else if (ch == '>' && x > y) return true;

	return false;
}

void go(int idx, string s) {
	if (idx == m + 1) {
		ret.push_back(s);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (visited[i]) continue;
		if (idx == 0 || good(s[idx - 1], i + '0', a[idx - 1])) {
			visited[i] = 1;
			go(idx + 1, s + to_string(i));
			visited[i] = 0;
		}
	}

	return;
}

int main() {
	cin >> m;
	for (int i = 0; i < m; i++) cin >> a[i];

	go(0, "");
	sort(ret.begin(), ret.end());
	cout << ret.back() << '\n' << ret.front();

	return 0;
}