// BOJ 9934 완전 이진 트리 (S1)
// 규칙 찾기 -> 나누기 2로 조건 찾고, 종료 조건으로 탈출
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int k, turn = 0, a[1030], ans[1030];
vector<int> ret[14];

void go(int here, int there, int level) {
	if (here > there) return;

	if (here == there) {
		ret[level].push_back(a[here]);
		return;
	}

	int center = (here + there) / 2;
	ret[level].push_back(a[center]);

	go(here, center - 1, level + 1);
	go(center + 1, there, level + 1);

	return;
}

void printgo() {
	for (int i = 0; i < k; i++) {
		for (int j : ret[i]) cout << j << " ";
		cout << '\n';
	}
}

void printans() {
	int cnt = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < pow(2, i - 1); j++) {
			cout << ans[cnt] << " ";
			cnt++;
		}
		cout << '\n';
	}
}


void check(int id) {
	// 자식 없음: turn에 적힌거 처리
	if (id * 2 + 1 >= pow(2, k) - 2) {
		ans[id] = a[turn];
		turn++;
		return;
	}

	// 왼쪽 방문
	check(id * 2 + 1);

	// 본인 처리: turn+1에 적힌거 처리
	ans[id] = a[turn];
	turn++;

	// 오른쪽 방문
	check(id * 2 + 2);
	
	return;
}

int main() {
	cin >> k;
	for (int i = 0; i < pow(2, k) - 1; i++) cin >> a[i];

	check(0);
	printans();

    go(0, pow(2, k) - 1, 0);
    printgo();

	return 0;
}
