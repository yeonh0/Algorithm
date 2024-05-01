from sys import stdin
input = stdin.readline

# NxN 도시, (r,c) : 1부터 시작, 빈칸/치킨집/집
# 0: 빈칸, 1: 집, 2: 치킨집

# 치킨거리 : 집과 가장 가까운 치킨집 사이 거리
# 도시 치킨거리 : 모든 치킨거리의 합
# abs(r값 차) + abs(c값 차)

# M개 빼고 다 문닫음 : 최소 도시 치킨거리

def cal(cl):
    global ans
    citysum = 0
    for i in home:
        sum = 10000
        for j in cl:
            (x, y) = i
            (x2, y2) = chi[j]
            sum = min(sum, abs(x2-x) + abs(y2-y))
        citysum += sum
    ans = min(ans, citysum)

# 계산: 집 - 치킨 최단거리 구해서 sum에 합
def dfs(n, cl):
    global ans
    if n == len(chi):
        if len(cl) == M:
            cal(cl)
        return

    dfs(n+1, cl)
    dfs(n+1, cl + [n])

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

# 도시에 치킨 집, 집 리스트 구함
home, chi = [], []
citysum = 0

ans = 10000000

for i in range(N):
    for j in range(N):
        if arr[i][j] == 1:
            home.append((i, j))
        elif arr[i][j] == 2:
            chi.append((i, j))

# M값과 치킨집 개수 비교
# 다르면
if(len(chi) != M):
    # chi 중 M개 뽑아서 최단거리 갱신
    dfs(0, [])
else:
    cal([i for i in range(len(chi))])
print(ans)