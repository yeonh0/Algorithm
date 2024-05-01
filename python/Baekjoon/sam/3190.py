from sys import stdin
input = stdin.readline

# 0. 목적지가 벽이거나(=N), 몸통일 때 (in list)
# 1. 사과가 있는지 -> 있으면 맨 앞에 하나 추가
# 2. 사과가 없으면 맨 앞에 하나 추가, 맨 뒤에 하나 빼기

def check(x, y, snakelist):
    if (0<=x<N and 0<=y<N):
        if not ([nx, ny] in snakelist):
            return 0
    return 1


N = int(input())
K = int(input())
app = [list(map(int, input().split())) for _ in range(K)]
L = int(input())
direct = [list(input().split()) for _ in range(L)]

snake = [[0, 0]]
nx, ny = 0, 0

old_t = cnt = mv = 0

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

for i in range(L):
    # X초 Y방향
    X, Y = int(direct[i][0]), direct[i][1]

    # 해당 방향으로 전진
    for j in range(X - old_t):
        nx += dx[mv]
        ny += dy[mv]
    # 목적지가 벽/몸인지 체크하기
        if check(nx, ny, snake):
            print(cnt+1)
            exit()
    # 안 부딪혔으면 사과인지 아닌지
        if not ([nx+1, ny+1] in app):
            snake.pop()
        else:
            app.remove([nx+1, ny+1])
        snake.insert(0, [nx, ny])
        cnt += 1

    if Y == 'D':
        mv = (mv + 1) % 4
    else:
        mv = (mv - 1) % 4

    old_t = X

while(1):
    nx += dx[mv]
    ny += dy[mv]
    if check(nx, ny, snake):
        print(cnt + 1)
        exit()
    if not ([nx + 1, ny + 1] in app):
        snake.pop()
    snake.insert(0, [nx, ny])
    cnt += 1