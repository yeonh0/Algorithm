// BOJ 2559 수열 (S3)
// 
#include <bits/stdc++.h>
using namespace std;

int N, K, num, sum, mymax = -99999999;

int main() {
    cin >> N >> K;

    // 내 풀이 : 단순합 - 944ms
    int a[N];
    for(int i=0; i<N; i++) {
        cin >> a[i];
    }

    for(int i=0; i<N-K+1; i++) {
        for(int j=0; j<K; j++) {
            sum += a[i+j];
        }
        if(sum > mymax) mymax = sum;
        sum = 0;
    }

    // 강의 : 누적합 - 32ms
    int b[N+1]; b[0] = 0;
    for(int i=1; i<N+1; i++) {
        cin >> b[i];
        b[i] += b[i-1];
    }

    for(int i=K; i<=N; i++) {
        mymax = max(b[i] - b[i-K], mymax);
    }

    cout << mymax;
}