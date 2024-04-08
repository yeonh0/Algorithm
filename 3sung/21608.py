# 교실 N x N, 학생 1 ~ N*N, 자리 번호 (1, 1) ~ (N, N)
# 각 학생마다 좋아하는 4명
# (r1,c1),(r2,c2) 인접: |r1-r2|+|c1-c2|= 1

# 1. 빈칸 중 좋아하는 학생 인접한 칸 가장 많은 자리
# 2. 1 여러개면 인접한 칸 중 비어있는 칸 가장 많은 자리
# 3. 2 여러개면 행 번호 가장 작은-> 열 번호 가장 작은 자리

from sys import stdin
input = stdin.readline

# 자리 배치 함수
def f1(person, seat):
    hogam, bincan = -1, -1
    bestseat = [0, 0]
    for i in range(N*N):
        r, c = i//N, i%N
        jo, mt = 0, 0   # 좋학, 빈칸
# 1. 자리 순회하면서 빈자리 찾음
        if seat[r][c] != 0:
            continue
        elif seat[r][c] == 0:
# 2. 빈 자리의 인접칸 4개 중 좋학, 빈칸 각각 구하기
            for j in range(4):
                nr, nc = r+dr[j], c+dc[j]
                if(0 <= nr < N and 0 <= nc < N):
                    # 인접칸: inperson
                    inperson = seat[nr][nc]
                    if inperson in person:
                        jo += 1
                    elif inperson == 0:
                        mt += 1
    # 3. 좋학이 max보다 크면 갱신
        if jo > hogam:
            bestseat = [r, c]
            hogam, bincan = jo, mt
    # 4. 같은 경우, 빈칸 비교해서 더 많으면 갱신
        elif jo == hogam:
            if mt > bincan:
                bestseat = [r, c]
                hogam, bincan = jo, mt

    seat[bestseat[0]][bestseat[1]] = person[0]


N = int(input())
arr = [list(map(int,input().split())) for _ in range(N*N)]

seat = [[0 for _ in range(N)] for _ in range(N)]
dr, dc = [-1, 1, 0, 0], [0, 0, -1, 1]

# arr 순서대로 학생 뽑음
for stu in arr:
    # stu : [4 / 2, 5, 1, 7]
    # 자리 배치하는 함수
    f1(stu, seat)

arr.sort()

ans = 0
for r in range(N):
    for c in range(N):
        cnt = 0
        for k in range(4):
            nr, nc = r + dr[k], c + dc[k]
            if (0 <= nr < N and 0 <= nc < N):
                if seat[nr][nc] in arr[seat[r][c]-1]:
                    cnt += 1
        if cnt == 1:
            ans += 1
        elif cnt == 2:
            ans += 10
        elif cnt == 3:
            ans += 100
        elif cnt == 4:
            ans += 1000
print(ans)