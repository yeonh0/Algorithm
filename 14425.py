N, M = map(int, input().split())
cnt = 0

A = set([input() for _ in range(N)])

for _ in range(M):
    a = input()
    if a in A:
        cnt += 1

print(cnt)
