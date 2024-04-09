# 8개 톱니 가진 4개의 톱니바퀴, N극/S극 톱니.
# 톱니 시계/반시계 방향 회전 : 한 칸씩
# A 회전, B와 맞닿은 톱니 극 다르면 B는 A와 반대로 회전

from sys import stdin
input = stdin.readline

def turnfunc(i, turndir):
    tmparr = [0 for _ in range(8)]

    # 시계 방향으로 회전
    if turndir == 1:
        plus = 1
    # 반시계 방향으로 회전
    else:
        plus = -1

    # 회전
    for q in range(8):
        tmparr[(q + plus) % 8] = arr[i][q]

    arr[i] = tmparr

arr = [list(map(int, " ".join(input().split()))) for _ in range(4)]
K = int(input())
turn = [list(map(int, input().split())) for _ in range(K)]
ans = 0

# 0 : N극, 1 : S극
# 1 : 시계, -1 : 반시계


for turninfo in turn:
    # 돌릴 바퀴, 돌릴 방향
    wheel, turndir = turninfo[0], turninfo[1]

    wheel -= 1
    up, down = wheel+1, wheel-1
    updir, downdir = -1*turndir, -1*turndir
    turnlist = []

    # 상승
    while(1):
        if up >= 4:
            break
        if arr[up][6] != arr[up-1][2]:
            turnlist.append((up, updir))
            updir *= -1
            up += 1
        else:
            break

    # 하강
    while (1):
        if down < 0:
            break
        if arr[down+1][6] != arr[down][2]:
            turnlist.append((down, downdir))
            downdir *= -1
            down -= 1
        else:
            break

    # 여기서 한꺼번에 돌려야함
    turnlist.append((wheel, turndir))
    for turnparam in turnlist:
        x, y = turnparam
        turnfunc(x, y)



for i in range(4):
    if arr[i][0] == 1:
        if i == 0:
            ans += 1
        elif i == 1:
            ans += 2
        elif i == 2:
            ans += 4
        elif i == 3:
            ans += 8
print(ans)