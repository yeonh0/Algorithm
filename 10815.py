N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))
A.sort()


def findCard(b):
    down, up = 0, len(A)-1
    while (down <= up):
        mid = (down+up) // 2

        if A[mid] > b:
            up = mid - 1
        elif A[mid] < b:
            down = mid + 1
        else:
            return mid
    return None


for b in B:
    if findCard(b) is not None:
        print(1, end=" ")
    else:
        print(0, end=" ")
