#include<bits/stdc++.h>
using namespace std;

vector<int> v1;

int printV(vector<int> v) {
    for(int i:v) cout << i << ' ';
    cout << '\n';
    return 0;
}

int makePermutation(int n, int r, int depth) {
    if(depth == r) {
        printV(v1);
        return 0;
    }
    
    for(int i = depth; i < r; i++) {
        swap(v1[i], v1[depth]);
        makePermutation(n, r, depth + 1);
        swap(v1[i], v1[depth]);
    }
}

int dowhilepermute() {
    do{
        for(int i:v1) cout << i << " ";
        cout << '\n';
    }while(next_permutation(v1.begin(), v1.end()));

    return 0;
}

int main() {
    for(int i = 1; i <= 3; i++) v1.push_back(i);;
    makePermutation(3, 3, 0);
    cout << '\n';
    dowhilepermute();

    return 0;
}