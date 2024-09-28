// BOJ 17071 숨바꼭질 5 (P5)
// 
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m, s[2][500004];

int main() {
	cin >> n >> m;
	if (n == m) { cout << 0 << '\n'; return 0; }

	int turn = 0;
	queue<int> q;

	q.push(n);
	s[0][n] = 1;

	while (q.size()) {
		turn++;
		m += turn;
		if(m > 500000) { cout << -1 << '\n'; return 0; }
		if (s[turn % 2][m]) { cout << turn << '\n'; return 0; }

		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int now = q.front(); q.pop();
			for (int there : {now - 1, now + 1, now * 2}) {
				if (there < 0 || there>500000 || s[turn % 2][there]) continue;
				if (there == m) { cout << turn << '\n'; return 0; }

				s[turn % 2][there] = s[(turn - 1) % 2][now] + 1;
				q.push(there);
			}
		}
	}

	cout << -1 << '\n';
	return 0;
}