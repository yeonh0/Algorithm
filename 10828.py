import sys
input = sys.stdin.readline
n = int(input().strip())
stack = []

for i in range(n):
    cmds = input().strip().split(' ')
    cmd = cmds[0]
    
    if (cmd == 'push'):
        stack.append(cmds[1])
    elif (cmd == 'pop'):
        if (len(stack) == 0):
            print(-1)
        else: 
            print(stack[-1])
            stack.pop()
    elif (cmd == 'size'):
        print(len(stack))
    elif (cmd == 'empty'):
        if (len(stack) == 0):
            print(1)
        else:
            print(0)
    elif (cmd == 'top'):
        if (len(stack) == 0):
            print(-1)
        else: 
            print(stack[-1])