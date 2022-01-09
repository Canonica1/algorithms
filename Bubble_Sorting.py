n= int(input())
a = list(map(int, input().split()))
ans = 0
j = 0
for run in range(n - 1):
    j += 1
    for i in range(n- j):
        if a[i] > a[i+1]:
            a[i],  a[i+1] = a[i+1], a[i]
            ans +=1
print(ans)
