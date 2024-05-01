#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

vector<int> usingMap(vector<int> v) {
    vector<int> ret;

    for(int i:v) {
        if(mp[i]) continue;
        else mp[i] = 1;
    }

    for(auto at:mp) ret.push_back(at.first);
    return ret;
}

vector<int> usingUnique(vector<int> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    return v;
}

void printV(vector<int> v) {
    for(int i:v) cout << i << " ";
    cout << '\n';
    
    return ;
}

int main() {
    vector<int>v1 = {2, 1, 4, 6, 4, 3, 2, 1, 5, 3, 2, 1};
    vector<int>ret;

    ret = usingMap(v1);
    printV(ret);

    ret = usingUnique(v1);
    printV(ret);
}