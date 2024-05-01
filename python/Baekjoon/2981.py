from math import gcd
from math import sqrt

N = int(input())
n = list(int(input()) for _ in range(N))
n.sort()
s = []

for i in range(1, len(n)):
    s.append(n[i]-n[i-1])

myGCD = s[0]

for i in range(len(s)):
    if gcd(myGCD, s[i]) < myGCD:
        myGCD = gcd(myGCD, s[i])

ans = []

for j in range(2, int(sqrt(myGCD))+1):
    if myGCD % j == 0:
        ans.append(j)
        ans.append(myGCD // j)
ans.append(myGCD)
ans = list(set(ans))

print(*sorted(ans))
