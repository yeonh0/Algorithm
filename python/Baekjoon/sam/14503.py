# 로봇 청소기, 방 상태 -> 청소 영역 개수
# N x M, 벽 또는 빈칸
# 청소기 바라보는 방향
from sys import stdin
input = stdin.readline

N, M = map(int, input().split())
r, c, d = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

# [북, 동, 남, 서]
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

# 청소 안 된 칸이 0, 벽이 1
# 현재 칸 청소 X : 현재 칸 청소
# 현재 칸 주변 4칸 중 청소 되지 않은 빈칸 X:
    # 바라보는 방향 유지, 한칸 후진 가능 시 후진하고 1
    # 후진 x : 작동 중지
# 현재 칸 주변 4칸 중 청소 되 않은 빈칸 O:
    # 반시계 방향 90도 회전
    # 바라보는 방향 기준 앞칸 청소 안된 빈칸 : 한칸 전진
    # 1로 돌아감
clist = []

def f1(r, c, d):
    cleanflag = 1
    # 현재 칸이 청소되지 않은 경우
    if not ((r, c) in clist):
        # 청소하기
        clist.append((r,c))

    for i in range(4):
        near_r, near_c = r+dr[i], c+dc[i]
        if (0<=near_r<N and 0<=near_c<M):
            # 상하좌우 중 청소 안된 거 있는 경우
            if not((near_r, near_c) in clist):
                if (arr[near_r][near_c] != 1):
                    cleanflag = 0
                    break

    # 주변 4칸 청소 모두 했음
    if cleanflag:
        # d : [북, 동, 남, 서]
        # 바라보는 방향 유지, 후진 가능한가
        # 가능 : 후진하기
        if not arr[r-dr[d]][c-dc[d]]:
            r, c = r-dr[d], c-dc[d]
        # 벽때매 불가능 : return
        else:
            return

    # 주변 4칸 중 안된 곳 있음
    else:
        # 반시계 90도 회전
        d = (d - 1) % 4
        # 바라보는 앞쪽 청소 x:
        if not ((r+dr[d], c+dc[d]) in clist):
            # 벽이 아닌 경우 전진
            if (arr[r+dr[d]][c+dc[d]] != 1):
                r, c = r+dr[d], c+dc[d]
        # 1번으로
    f1(r, c, d)
f1(r, c, d)
print(len(clist))