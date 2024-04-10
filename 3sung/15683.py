def cal(tlst):
    cnt = 0
    v = [[0] * M for _ in range(N)]
    for num in range(CNT):
        x, y = lst[num]         # cam 좌표
        ctype = arr[x][y]       # cam type
        rot = tlst[num]         # cam rotation

        for dr in camera[ctype]:
            tmpx, tmpy = x, y
            dr = (dr + rot) % 4
            while True:
                tmpx, tmpy = tmpx + dx[dr], tmpy + dy[dr]
                if not (0<=tmpx<N and 0<=tmpy<M):
                    break
                if arr[tmpx][tmpy] == 6:
                    break
                v[tmpx][tmpy] = 1

    for i in range(N):
        for j in range(M):
            if v[i][j] == 0 and arr[i][j] == 0:
                cnt += 1

    return cnt


def dfs(n, tlst):
    global ans

    if n == CNT:
        ans = min(ans, cal(tlst))
        return

    dfs(n + 1, tlst+[0])
    dfs(n + 1, tlst+[1])
    dfs(n + 1, tlst+[2])
    dfs(n + 1, tlst+[3])

camera = [[], [1], [1, 3], [0, 1], [0, 1, 3], [0, 1, 2, 3]]
dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
lst = []

for i in range(N):
    for j in range(M):
        if 0<arr[i][j]<6:
            lst.append((i, j))

CNT = len(lst)
ans = N * M

dfs(0, [])

print(ans)