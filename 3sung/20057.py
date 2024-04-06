from sys import stdin
input = stdin.readline

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

ci = cj = n // 2
di, dj = [0, 1, 0, -1], [-1, 0, 1, 0]
mul = [2, 10, 7, 1, 5, 10, 7, 1, 2, 0]
ai = [[-2, -1, -1, -1, 0, 1, 1, 1, 2, 0],
      [0, 1, 0, -1, 2, 1, 0, -1, 0, 1],
      [2, 1, 1, 1, 0, -1, -1, -1, -2, 0],
      [0, -1, 0, 1, -2, -1, 0, 1, 0, -1]]
aj = [[0, -1, 0, 1, -2, -1, 0, 1, 0, -1],
      [-2, -1, -1, -1, 0, 1, 1, 1, 2, 0],
      [0, 1, 0, -1, 2, 1, 0, -1, 0, 1],
      [2, 1, 1, 1, 0, -1, -1, -1, -2, 0]]

ds = cnt = flag = ans = 0
cnt_max = 1

while((ci, cj) != (0, 0)):
    sm = k = 0
    ci, cj = ci + di[ds], cj + dj[ds]
    cnt += 1

    val = arr[ci][cj]
    if(val > 0):
        arr[ci][cj] = 0
        for i in range(10):
            ni, nj = ci + ai[ds][i], cj + aj[ds][i]
            k = (val * mul[i]) // 100
            if i == 9:
                k = val - sm
            if(0<=ni<n and 0<=nj<n):
                arr[ni][nj] += k
            else:
                ans += k
            sm += k

    if(cnt == cnt_max):
        cnt = 0
        ds = (ds + 1) % 4
        if(flag == 1):
            cnt_max += 1
            flag = 0
        else:
            flag = 1

print(ans)