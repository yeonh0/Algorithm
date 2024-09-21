// BOJ 12851 숨바꼭질 2 (G4)
//
#include <iostream>
#include <queue>
using namespace std;

int n, k, visited[100004], cnt[100004];
queue<int> q;

int main() {
    cin >> n >> k;

    visited[n] = 1;
    cnt[n] = 1;
    q.push(n);

    if(n == k) {
        puts("0"); puts("1");
        return 0;
    }

    while (q.size()) {
        int now = q.front(); q.pop();

        for (int next : {now - 1, now + 1, now * 2}) {
            if (next < 0 || next > 100000) continue;

            if (!visited[next]) {
                q.push(next);
                visited[next] = visited[now] + 1;
                cnt[next] += cnt[now];
            }

            else if (visited[next] == visited[now] + 1) {
                cnt[next] += cnt[now];
            }
        }

    }

    cout << visited[k] - 1 << '\n' << cnt[k];

    return 0;
}
