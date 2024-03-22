from collections import deque

def bfs(graph, start, visited):
    # 큐 생성, 현재 노드 방문 처리
    queue = deque([start])
    visited[start] = True

    # 큐가 빌 때까지 반복
    while queue:
        # 큐에서 원소 하나 뽑아서 출력
        v = queue.popleft()
        print(v, end=" ")

        # 아직 방문하지 않은 인접 노드를 큐에 넣음
        for node in graph[v]:
            if not (visited[node]):
                queue.append(node)
                visited[node] = True


graph = [
    [],
    [2, 3, 8],
    [1, 7],
    [1, 4, 5],
    [3, 5],
    [3, 4],
    [7],
    [2, 6, 8],
    [1, 7]
]

visited = [False] * 9
bfs(graph, 1, visited)