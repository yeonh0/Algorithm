from sys import stdin
input = stdin.readline

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
cnt = 0
nlist = [[0, 0] for _ in range(n)]
max_list = [0]

nlist[0][0] = arr[0][0]
nlist[0][1] = arr[0][1]
if arr[0][0] <= n:
    max_list.append(arr[0][1])

while not(cnt == n-1):
   cnt += 1
   for i in range(cnt):
       if nlist[i][0] <= cnt:
           if nlist[cnt][1] < nlist[i][1]:
               nlist[cnt][1] = nlist[i][1]
   if (cnt + arr[cnt][0] <= n):
       nlist[cnt][1] += arr[cnt][1]
       nlist[cnt][0] = cnt + arr[cnt][0]
   else:
       nlist[cnt][0] = cnt
   max_list.append(nlist[cnt][1])

print(max(max_list))