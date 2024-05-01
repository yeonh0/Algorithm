import sys
input = sys.stdin.readline
N, M = map(int, input().split())
D = {}
DD = []

for i in range(N):
    po = input().strip("\n")
    D[po] = i+1
    DD.append(po)

for _ in range(M):
    a = input().strip("\n")
    try:
        a = int(a)
        print(DD[a-1])
    except:
        print(D[a])
