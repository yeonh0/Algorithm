#코드를 입력하세요.
from sys import stdin
input = stdin.readline

a, p = map(int, input().split())
D = [a]

while(1):
    tmp = 0
    lastnode = D[-1]

    for i in str(lastnode):
        tmp += int(i) ** p

    if tmp in D:
        break
    D.append(tmp)

print(D.index(tmp))