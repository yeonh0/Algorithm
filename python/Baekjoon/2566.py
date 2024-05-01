A = []
B = 0
a, b = 0, 0

for _ in range(9):
    A.append(list(map(int, input().split())))

for i in range(9):
    for j in range(9):
        if B < A[i][j]:
            B = A[i][j]
            a, b = i, j

print(B)
print(a+1, b+1, end=" ")
