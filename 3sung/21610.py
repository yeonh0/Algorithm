N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]     # 물바구니
move = [list(map(int, input().split())) for _ in range(M)]     # 이동의 정보 di, si

# 1부터 <- 에서 45도씩 증가
dx = [0, -1, -1, -1, 0, 1, 1, 1]
dy = [-1, -1, 0, 1, 1, 1, 0, -1]

rx = [-1, -1, 1, 1]
ry = [-1, 1, -1, 1]

gureumlist = [(N-2, 0), (N-2, 1), (N-1, 0), (N-1, 1)]
ans = 0

# move에서 하나씩 빼서 움직임
for mvinfo in move:
    d, s = mvinfo[0], mvinfo[1]

    v = [[0] * N for _ in range(N)]
# 1. di, si 값을 가지고 구름을 움직임. 이 때 구름은 N-1 -> 0 이렇게 좌표 넘어감
    for num in range(len(gureumlist)):
        cx, cy = gureumlist[num]
        cx, cy = (cx+(dx[d-1] * s)) % N, (cy+(dy[d-1] * s)) % N
        gureumlist[num] = (cx, cy)
        v[cx][cy] = 1

# 2. 이동한 칸에 물 + 1 함
        A[cx][cy] += 1

# 3. 구름은 사라짐
# 4. 물 증가한 칸 대각선 방향 1인 칸에 물 있는 바구니 수만큼 물 양 증가 -> 얘는 경계 안넘어감
    for gureum in gureumlist:
        cx, cy = gureum
        cnt = 0
        for i in range(4):
            ix, iy = cx+rx[i], cy+ry[i]
            if 0<=ix<N and 0<=iy<N:
                if A[ix][iy] > 0:
                    cnt += 1

        A[cx][cy] += cnt

# 5. 바구니 물 2 이상이면 구름 생기고 물 - 2 => 3에서 구름 사라진 칸은 해당 안됨
    newgureumlist = []
    ans = 0
    for i in range(N):
        for j in range(N):
            if A[i][j] >= 2 and v[i][j] == 0:
                A[i][j] -= 2
                newgureumlist.append((i, j))
            ans += A[i][j]
    gureumlist = newgureumlist

print(ans)