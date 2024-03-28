#코드를 입력하세요.
from sys import stdin
input = stdin.readline

def sol(i):
    visited[i] = 1
    if(visited[numlist[i]] == 0):
        sol(numlist[i])
    return

t = int(input())
for _ in range(t):
    n = int(input())
    cnt = 0
    numlist = list(map(int, input().split()))
    numlist.insert(0, 0)
    visited = [0] * (n + 1)

    for i in range(1, n+1):
        if(visited[i] == 0):
            sol(i)
            cnt += 1

    print(cnt)