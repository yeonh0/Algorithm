// BOJ 16637 괄호 추가하기 (G3)
//
#include <bits/stdc++.h>
using namespace std;

int n, ret = -987654321;
string str;
vector<int> num;
vector<char> oper;

int operation(int a, int b, char ch) {
    if (ch == '+') return a + b;
    if (ch == '*') return a * b;
    if (ch == '-') return a - b;
}

void dfs(int idx, int _num) {
    if (idx == num.size() - 1) {
        ret = max(_num, ret);
        return;
    }

    dfs(idx + 1, operation(_num, num[idx + 1], oper[idx]));
    if (idx + 2 <= num.size() - 1) {
        int tmp = operation(num[idx + 1], num[idx + 2], oper[idx + 1]);
        dfs(idx + 2, operation(_num, tmp, oper[idx]));
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> str;
    for (int i = 0; i < str.size(); i++) {
        if (i % 2) oper.push_back(str[i]);
        else num.push_back(str[i] - '0');
    }
    
    dfs(0, num[0]);
    cout << ret;

    return 0;
}

//9
//3 + 8 * 7 - 9 * 2