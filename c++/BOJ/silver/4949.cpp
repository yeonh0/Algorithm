// BOJ 4949 균형잡힌 세상 (S4)
//
#include <bits/stdc++.h>
using namespace std;

string s;

bool check(string s) {
    stack<char> stk_small;

    for(char ch : s) {
        if(ch == '(') stk_small.push('(');
        else if(ch == ')') {
            if(!stk_small.empty()) {
                if(stk_small.top() == '[') return false;
                stk_small.pop();
            }
            else return false;
        }
        else if(ch == '[') stk_small.push('[');
        else if(ch == ']') {
            if(!stk_small.empty()) {
                if(stk_small.top() == '(') return false;
                stk_small.pop();
            }
            else return false;
        }
    }
    return stk_small.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true) {
        getline(cin, s);
        if(s == ".") break;

        if(check(s)) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}
