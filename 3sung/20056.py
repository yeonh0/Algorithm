# 격자, 불공 개수, 실행 횟수
N, M, K = map(int, input().split())
# r, c, m, s, d (1<=r, c<=N)
arr = [list(map(int, input().split())) for _ in range(M)]

dr = [-1, -1, 0, 1, 1, 1, 0, -1]
dc = [0, 1, 1, 1, 0, -1, -1, -1]

for _ in range(K):
    # 공 이동 시키기
    for i in range(len(arr)):
        arr[i][0] = (arr[i][0] + dr[arr[i][4]] * arr[i][3] -1)  % N
        arr[i][1] = (arr[i][1] + dc[arr[i][4]] * arr[i][3] -1)  % N

    # 공 정렬하기
    arr.sort()
    arr.append([100, 100, 1, 1, 1])

    # 공 하나씩 꺼내서 분류
    newlst = []
    i = 0
    while(i<len(arr)-1):
        si, sj, m, s, d = arr[i]
        start = 0
        # i부터 앞으로 가면서 같은 공 나올 때 까지 반복
        for j in range(i+1, len(arr)):
            # 다음 공과 같으면 값 더함
            if arr[j][0] == si and arr[j][1] == sj:
                m += arr[j][2]
                s += arr[j][3]
                if d%2 != arr[j][4]%2:
                    start = 1
            # 다음 공과 다르면
            else:
                # 바로 다음 공이 아니라면 질량 나눠서 0보다 큰거만 새 리스트에 추가
                if j-i == 1:
                    newlst.append(arr[i])
                else:
                    if m//5 > 0:
                        for dire in range(start, start+8, 2):
                            newlst.append([si, sj, m//5, s//(j-i), dire])
                break
        i = j
    arr = newlst

mass = 0
for i in range(len(arr)):
    mass += arr[i][2]
print(mass)