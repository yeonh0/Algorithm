from sys import stdin
input = stdin.readline

def dfs(num, sum, tetlist):
    global maxnum

    # 가지치기
    if maxnum >= sum + (4-num)*maxval:
        return

    if num == 4:
        maxnum = max(maxnum, sum)
        return

    for dot in tetlist:
        (i, j) = dot
        visited[i][j] = 1

        for k in range(4):
            ni, nj = i + di[k], j + dj[k]
            if (0<=ni<N and 0<=nj<M):
                if visited[ni][nj] == 0:
                    visited[ni][nj] = 1
                    dfs(num+1, sum+arr[ni][nj], tetlist+[(ni,nj)])
                    visited[ni][nj] = 0


N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

maxnum = 0
maxval = max(map(max, arr))

visited = [[0 for _ in range(M)] for _ in range(N)]

di = [1, -1, 0, 0]
dj = [0, 0, 1, -1]

for i in range(N):
    for j in range(M):
        dfs(1, arr[i][j], [(i, j)])

print(maxnum)