N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))
numlist = [0]*20000000

for a in A:
    numlist[a+10000000] += 1

for b in B:
    if numlist[b+10000000] == 1:
        print(1, end=" ")
    else:
        print(0, end=" ")
