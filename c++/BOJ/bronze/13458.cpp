// BOJ 13458 시험 감독 (B2)
// 
#include <iostream>
using namespace std;

long long n, b, c, ret = 0, a[1000004];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		long long student = a[i];
		student -= b; ret++;
		if (student <= 0) continue;
		ret += student / c;
		if (student % c) ret++;
	}

	cout << ret << '\n';

	return 0;
}