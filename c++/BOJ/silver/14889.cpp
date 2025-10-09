// BOJ 14889 스타트와 링크 (S1)
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, ret = 9999999, a[24][24];

int getabil(vector<int> team) {
	int abil = 0;
	for (int i = 0; i < team.size(); i++) {
		for (int j = i + 1; j < team.size(); j++) {
			abil += a[team[i]][team[j]];
			abil += a[team[j]][team[i]];
		}
	}

	return abil;
}

void dfs(int depth, vector<int> team1) {
	if (team1.size() == n / 2) {
		vector<int> team2;
		int cnt = -1;
		for (int num : team1) {
			for (int i = cnt+1; i < num; i++) {
				team2.push_back(i);
			}
			cnt = num;
		}
		for (++cnt; cnt < n; cnt++) {
			team2.push_back(cnt);
		}
		int team1abil = getabil(team1);
		int team2abil = getabil(team2);
		ret = min(abs(team1abil - team2abil), ret);

		return;
	}

	for (int i = depth + 1; i < n; i++) {
		team1.push_back(i);
		dfs(i, team1);
		team1.pop_back();
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}

	// 팀 가르기
	vector<int> v;
	dfs(-1, v);
	cout << ret;

	return 0;
}