# 바이러스 상하좌우로 인접한 빈 칸에 퍼짐
# 새로 벽을 3개(무조건) 세워야 함
# 0은 빈칸, 1은 벽, 2는 바이러스(2 이상 10 이하로 주어짐)
# 3개 세우고 안퍼지는 공간 : 안전공간

from sys import stdin
input = stdin.readline

def find(wall1, vi1):
    global maxval

    ptr = 0
    while(1):
        if ptr == len(vi1):
            break
        for dot in range(ptr, len(vi1)):
            (i, j) = vi1[dot]

            for k in range(4):
                ni, nj = i + dx[k], j + dy[k]
                if (0 <= ni < N and 0 <= nj < M):
                    if not((ni, nj) in vi1 or (ni, nj) in wall1):
                        vi1.append((ni, nj))
            ptr = dot + 1

    maxval = max(maxval, N*M - (len(vi1) + len(wall1)))


N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

# 상하좌우로 0이면 2 쓰고 1,2 이면 패스

dx, dy = [1, -1, 0, 0], [0, 0, -1, 1]

zero = []
maxval = 0

for i in range(N):
    for j in range(M):
        if arr[i][j] == 0:
            zero.append((i, j))

# 바이러스 전파 시 추가 된 바이러스 좌표에서만 다시 탐색
wall, vi = [], []
for i in range(N):
    for j in range(M):
        if arr[i][j] == 1:
            wall.append((i, j))
        elif arr[i][j] == 2:
            vi.append((i, j))

for a in range(len(zero)):
    for b in range(a+1, len(zero)):
        for c in range(b+1, len(zero)):
            find(wall+[zero[a], zero[b], zero[c]], vi+[])

print(maxval)

# 벽 따로, 2 따로
# 2 좌표에서 상하좌우 : 벽이나 2가 있는지 확인
# 범위 내 상하좌우 중에서 벽이나 2가 아니면 0이니까 2에 추가
