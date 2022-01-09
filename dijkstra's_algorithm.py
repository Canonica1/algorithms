n, s, f = map(int, input().split()) # s -это вершина с которой начинаеться поиск f - та которую ищем. n - число вершин
m = [] # на вход подаеться взвешенный граф где -1 значит что ребра нет
s-=1
f -=1
for i in range(n):
    stru = list(map(int,input().split()))
    m.append(stru)
values = [10**20 for i in range(n)]
used = [1 for i in range(n) ]
used[s] = 0
values[s] = 0
ans = 0
q = True
while used.count(1) > 0:
    if not q:
        ans = 10**21
        for i in range(len(values)):
            if ans > values[i] and used[i] == 1:
                ans = values[i]
                s = i
    for j in range(n):
        if m[s][j] + values[s] < values[j] and m[s][j]> -1 :
            values[j]  =  m[s][j]+ values[s]
    used[s] = 0
    q = False
if values[f] >=10**20:
    print(-1)
else:
    print(values[f])
