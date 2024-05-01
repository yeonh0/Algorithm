#  1   2   3   ... N-1  N
# 2N 2N-1 2N-2 ... N+2 N+1  시계 방향 회전
# i번 칸의 내구도는 Ai

# 로봇을 1번에 올림, N번 도착하면 즉시 내림
# 스스로 이동, 올리거나 칸 이동 시 내구도 1 감소

# 1. 로봇과 함께 한 칸 회전
# 2. if 가장 먼저 로봇 한칸 이동 가능하면 이동, 없으면 x
# 3.    로봇 이동하려면 이동칸 로봇x, 내구도 1 이상
# 4. 올리는 위치 칸 내구도 0 아니면 로봇 올림
# 5. 내구도 0 칸 K개 이상이면 종료, 없으면 1로

from sys import stdin
input = stdin.readline

N, K = map(int, input().split())
arr = list(map(int, input().split()))
robot =[0]*N

cnt = ans = 0

while(1) :
    # 로봇 회전
    ans += 1
    arr = [arr[-1]] + arr[:-1]
    robot = [0] + robot[:-1]
    # 로봇 내리기
    robot[N-1] = 0

    for i in range(N-2, 0, -1):
        # 먼저 올라간 로봇부터 처리
        if robot[i] == 1 and arr[i+1] > 0 and robot[i+1] == 0:
            robot[i], robot[i+1] = 0, 1
            arr[i+1] -= 1
            if arr[i+1] == 0:
                cnt += 1

    # 올리기
    if arr[0] > 0:
        robot[0] = 1
        arr[0] -= 1
        if arr[0] == 0:
            cnt += 1

    if cnt >= K:
        break

print(ans)