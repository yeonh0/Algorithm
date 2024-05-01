N = int(input())
a = []
board = [[0 for i in range(100)] for j in range(100)]
space = 0

for _ in range(N):
    m, n = map(int, input().split())
    for i in range(10):
        for j in range(10):
            board[m+i][n+j] = 1

for i in range(100):
    space += board[i].count(1)
print(space)
