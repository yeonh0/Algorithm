# 첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

A, B, C = map(int, input().split())
s = 1
while B != 1:
    if B % 2 != 0:
        s = (s * A) % C
    B = B // 2
    A = (A * A) % C
print((A*s) % C)
