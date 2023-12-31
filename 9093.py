# 2
# I am happy today
# We want to win the first prize

# I ma yppah yadot
# eW tnaw ot niw eht tsrif ezirp


n = int(input())

for _ in range(n):
    msg = input().split(' ')
    for i in msg:
        for j in reversed(i):
            print(j, end='')
        print(' ', end="")
    print()