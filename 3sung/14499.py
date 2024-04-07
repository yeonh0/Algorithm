from sys import stdin
input = stdin.readline

# N x M 지도, (r, c), 각 칸에 숫자 하나씩 있음
# 주사위, (x, y), 처음 : 모든 면에 0


# 세로(N), 가로(M), 주사위 좌표(x,y), 명령 개수(K)
N, M, x, y, K = map(int, input().split())
maplist = [list(map(int, input().split())) for _ in range(N)]
D = list(map(int, "".join(input().split())))

# 1, 2, 3, 4 = 동, 서, 북, 남
dx = [0, 0, 0, -1, 1]
dy = [0, 1, -1, 0, 0]

def dice(d, K):
    if K == 1:
        d[0],d[1],d[2],d[3],d[4],d[5] = d[0],d[5],d[1],d[2],d[4],d[3]
    if K == 2:
        d[0],d[1],d[2],d[3],d[4],d[5] = d[0],d[2],d[3],d[5],d[4],d[1]
    if K == 3:
        d[0],d[1],d[2],d[3],d[4],d[5] = d[2],d[1],d[4],d[3],d[5],d[0]
    if K == 4:
        d[0],d[1],d[2],d[3],d[4],d[5] = d[5],d[1],d[0],d[3],d[2],d[4]


back = 6
dicelist = [[2, 0],[4, 0],[1, 0],[3, 0],[5, 0],[6, 0]]
# 순서대로 명령 수행
for d in D:
    nx, ny = x + dx[d], y + dy[d]   # 이동할 좌표
    # 이동할 좌표가 지도 바깥인 경우
    if (0<=nx<N and 0<=ny<M):
        # 주사위 이동하기
        dice(dicelist, d)
        # 상단에 쓰인 값
        print(dicelist[2][1])

        # 이동한 좌표의 값이 0이면 칸 = 바닥
        if (maplist[nx][ny] == 0):
            maplist[nx][ny] = dicelist[5][1]
        # 0이 아니면 바닥 = 칸, 칸 = 0
        else:
            dicelist[5][1] = maplist[nx][ny]
            maplist[nx][ny] = 0
        x, y = nx, ny

# 굴려서 이동한 칸 = 0 : 칸에 주사위의 바닥면 복사
# 0이 아니면 : 칸이 주사위 바닥면으로 복사, 칸은 0

# in : 주사위 놓은 곳 좌표, 이동시키는 명령
# out : 이동할 때마다 상단에 쓰여있는 값
# 바깥으로 이동 X : 명령 무시, 출력도 X