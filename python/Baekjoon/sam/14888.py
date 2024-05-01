from sys import stdin
input = stdin.readline

max_num = -100000000
min_num = 1000000000

def dfs(k, sum, mode1, mode2, mode3, mode4):
    global max_num
    global min_num

    if(k == n-1):
        max_num = max(max_num, sum)
        min_num = min(min_num, sum)
        return

    if (mode1):
        dfs(k+1, sum + A[k+1], mode1 -1, mode2, mode3, mode4)
    if (mode2):
        dfs(k+1, sum - A[k+1], mode1, mode2-1, mode3, mode4)
    if (mode3):
        dfs(k+1, sum * A[k+1], mode1, mode2, mode3-1, mode4)
    if (mode4):
        dfs(k + 1, int(sum / A[k + 1]), mode1, mode2, mode3, mode4-1)
n = int(input())
A = list(map(int, input().split()))
# [+, -, *, /]
B = list(map(int, input().split()))
dfs(0, A[0], B[0], B[1], B[2], B[3])
print(max_num)
print(min_num)