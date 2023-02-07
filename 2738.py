N, M = map(int, input().split())
a = []
b = []

for _ in range(N):
    a.append(list(map(int, input().split())))

for _ in range(N):
    b.append(list(map(int, input().split())))

for n in range(N):
    for m in range(M):
        print(a[n][m] + b[n][m], end=" ")
    print()
