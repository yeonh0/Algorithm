#include <bits/stdc++.h>
using namespace std;

int a[9];
pair<int, int> ret;
int asum = 0;

void permute1() {
    do {
        int sum = 0;
        for(int i=0; i<7; i++) sum += a[i];
        if(sum == 100) break;
    } while(next_permutation(a, a+9));

    for(int i=0; i<7; i++) cout << a[i] << endl;
}

void permute2() {
    for(int i=0; i<9; i++) {
        for(int j=i+1; j<9; j++) {
            if((asum - a[i] - a[j]) == 100) {
                ret = {i, j};
                return;
            }
        }
    }
}

int main() {
    for(int i=0; i<9; i++) {
        cin >> a[i];
        asum += a[i];
    }

    sort(a, a+9);
    permute1();
    permute2();
    
    vector<int> v;
    for(int i=0; i<9; i++) {
        if(ret.first == i || ret.second == i) continue;
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    for(int i:v) cout << i << endl;

    return 0;
}