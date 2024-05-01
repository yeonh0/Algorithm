from sys import stdin
input = stdin.readline

N = int(input())
A = list(map(int, input().split()))
B, C = map(int, input().split())
ans = 0

for i in range(N):
    tmp = A[i]-B
    ans += 1
    if tmp > 0:
        if int(tmp/C) != tmp/C:
           ans += 1
        ans += int(tmp/C)

print(ans)