from sys import stdin
from collections import deque
input = stdin.readline

n, m = map(int, input().split())
miro = [list(map(int, list(input().rstrip()))) for _ in range(n)]
x, y = 0, 0
queue = deque([(0,0)])

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

while queue:
    x, y = queue.popleft()
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if(0 <= nx < n and 0 <= ny < m):
            print(nx, ny)
            if(miro[nx][ny] == 1):
                queue.append((nx, ny))
                miro[nx][ny] = miro[x][y] + 1

print(miro[-1][-1])