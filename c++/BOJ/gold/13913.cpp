// BOJ 13913 숨바꼭질 4 (G4)
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, visited[100004], _prev[100004];

int main() {
	queue<int> q;
	vector<int> v;

	cin >> n >> m;
	if (n == m) { cout << 0 << '\n' << n; return 0; }
	visited[n] = 1;
	q.push(n);

	while (q.size()) {
		int now = q.front(); q.pop();
		if (now == m) break;

		for (int next : {now - 1, now + 1, now * 2}) {
			if (next < 0 || next > 100000) continue;

			if (!visited[next]) {
				visited[next] = visited[now] + 1;
				_prev[next] = now;
				q.push(next);
			}
		}
	}

	for (int i = m; i != n; i = _prev[i]) {
		v.push_back(i);
	}
	v.push_back(n);

	cout << visited[m] - 1 << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[v.size() - i - 1] << " ";
	}

	return 0;
}