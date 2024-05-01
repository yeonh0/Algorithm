from collections import deque
N, Q = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(2**N)]
lev = list(map(int, input().split()))

def bfs(i, j):
    global maxans
    q = deque()
    q.append((i, j))
    v[i][j] = 1
    qcnt = 0
    while q:
        flag = 0
        nq = deque()
        for si, sj in q:
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                ni, nj = si+dx, sj+dy
                if 0<=ni<2**N and 0<=nj<2**N:
                    if v[ni][nj] == 0 and arr[ni][nj] > 0:
                        nq.append((ni, nj))
                        qcnt += 1
                        v[ni][nj] = 1
                        flag = 1
        if flag == 0:
            maxans = max(maxans, qcnt+1)
            return
        q = nq



def check(i, j):
    cnt = 0
    for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        ni, nj = dx+i, dy+j
        if 0<=ni<2**N and 0<=nj<2**N:
            if arr[ni][nj] > 0:
                cnt += 1
    return cnt

for L in lev:
    # 회전하기
    new = [[0]*(2**N) for _ in range(2**N)]
    for si in range(0, 2**N, 2**L):
        for sj in range(0, 2**N, 2 **L):
            for i in range(2**L):
                for j in range(2 ** L):
                    new[si+i][sj+j] = arr[si+(2**L)-1-j][sj+i]
    arr = new
            # rotatedlst = [[arr[i][j] for i in range   (i+2**L-1, i-1, -1)] for j in range(j, j+2**L)]
            # for k in range(len(rotatedlst)):
            #     arr[i+k][j:j+2**L] = rotatedlst[k]

    new = [x[:] for x in arr]
    for i in range(2**N):
        for j in range(2**N):
            cnt = check(i, j)
            if cnt <= 2 and arr[i][j] > 0:
                new[i][j] -= 1
    arr = new
ans = 0

for i in arr:
    ans += sum(i)
print(ans)

maxans = 0
v = [[0] * (2 ** N) for _ in range(2 ** N)]
for i in range(2**N):
    for j in range(2**N):
        if not(arr[i][j] <= 0 or v[i][j] == 1):
            bfs(i, j)
print(maxans)