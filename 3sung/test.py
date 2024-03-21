import sys 
input = sys.stdin.readline


def GCD(m, n, a):
    a += 1
    if(m < n):
        m, n = n, m
    
    if (m % n == 0):
        return n
    else:
        GCD(n, m % n, a)
    print(f"hi from {a}")

m, n = map(int, input().split())

print(GCD(m, n, 0))