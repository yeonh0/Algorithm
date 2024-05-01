from sys import stdin
input = stdin.readline

minval = 10000

#1) 썡 DFS
def cal(alist, blist):
    A = B = 0
    for i in range(int(n/2)):
        for j in range(i+1, int(n/2)):
            A += arr[alist[i]][alist[j]]
            A += arr[alist[j]][alist[i]]
            B += arr[blist[i]][blist[j]]
            B += arr[blist[j]][blist[i]]
    return abs(A-B)
def f1(num, alist, blist):
    global minval
    if num == n:
        if len(alist) == len(blist):
            minval = min(minval, cal(alist, blist))
        return
    f1(num + 1, alist + [num], blist)
    f1(num + 1, alist, blist + [num])

#2) visted 쓴 DFS
def f2(num, k):
    global minval
    if num == n/2:
        A = B = 0
        for i in range(n):
            for j in range(i+1, n):
                if (visited[i] == 1) and (visited[j] == 1):
                    A = A + arr[i][j] + arr[j][i]
                elif (visited[i] == 0) and (visited[j] == 0):
                    B = B + arr[i][j] + arr[j][i]
        minval = min(minval, abs(A-B))
        return

    for i in range(k, n):
        if not visited[i]:
            visited[i] = 1
            f2(num+1, i+1)
            visited[i] = 0



n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]
visited = [0 for _ in range(n)]

#f1(0, [], [])
f2(0, 0)
print(minval)