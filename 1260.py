from collections import deque
import sys

input = sys.stdin.readline

def dfs(numlist, v, visited):
    visited[v] = True
    print(v, end=" ")
    numlist[v].sort()

    for i in numlist[v]:
        if not (visited[i]):
            dfs(numlist, i, visited)

def bfs(numlist, v, visited):
    queue = deque([v])
    visited[v] = True

    while(queue):
        node = queue.popleft()
        print(node, end=" ")
        numlist[node].sort()

        for i in numlist[node]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

n, m, v = map(int, input().split())
numlist = [[] for _ in range(n+1)]

for i in range(m):
    a, b = map(int, input().split())
    numlist[a].append(b)
    numlist[b].append(a)

dfs(numlist, v, [False] * (n+1))
print()
bfs(numlist, v, [False] * (n+1))