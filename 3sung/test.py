def dfs(graph, v, visited):
    # 방문한 노드 표시
    visited[v] = True
    print(v, end=" ")

    # 인접 노드 중 방문 안한 노드 찾기
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

# 노드는 1번부터 사용하기 위해 첫번째 []
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
dfs(graph, 1, visited)