# 2
# I am happy today
# We want to win the first prize

# I ma yppah yadot
# eW tnaw ot niw eht tsrif ezirp


n = int(input())

for _ in range(n):
    msg = input().split(' ')
    for i in msg:
        print(i[::-1], end=" ")
    print()