// BOJ 3986 좋은 단어 (S4)
// 잘 안되면 뒤집기, 돌리기 다 해보자
#include <bits/stdc++.h>
using namespace std;

int N, cnt;
string myin;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) {
        vector<int> v;
        cin >> myin;

        for(char chr:myin) {
            if(chr == 'A') v.push_back(1);
            else if(chr == 'B') v.push_back(2);

            if(v[v.size()-1] == v[v.size()-2]) {
                v.pop_back(); v.pop_back();
            }
        }

        if(v.size() == 0) cnt++;
    }


    cout << cnt;

    return 0;
}