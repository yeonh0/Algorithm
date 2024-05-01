from collections import deque

N, L, R = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]

dr = [0, -1, 0, 1]
dc = [-1, 0, 1, 0]

def bfs(r, c):
    q = deque()
    q.appendleft((r, c))

    v[r][c] = 1
    united = [(r, c)]
    sm = A[r][c]

    while q:
        ar, ac = q.pop()
        for i in range(4):
            cr, cc = ar + dr[i], ac + dc[i]
            if 0 <= cr < N and 0 <= cc < N:
                if v[cr][cc] == 0 and L <= abs(A[cr][cc] - A[ar][ac]) <= R:
                    q.appendleft((cr, cc))
                    sm += A[cr][cc]
                    united.append((cr, cc))
                    v[cr][cc] = 1

    num = len(united)

    if num > 1:
        for x, y in united:
            A[x][y] = int(sm / num)
        return 1
    return 0

ans = 0
while 1:
    flag = 0
    v = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if  not v[i][j] == 1:
                flag = max(flag, bfs(i, j))

    if flag == 0:
        break
    ans += 1
print(ans)

# 개방 위해 공유 국가 인구 차 조사

# 개방 완료

# 열려있으면 열린 칸 인구수 = int(인구합 / 칸개수)

# 문 닫음

