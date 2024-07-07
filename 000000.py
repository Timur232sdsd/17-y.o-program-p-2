def l(s):
    arr = []
    for i in range(5):
        if s[i] == '.':
            arr.append([0, 0, i])
        else:
            arr.append([MAX, 0, i])
    return arr

n = int(input())
MAX = float('+inf')
a = [l('x' + input() + 'x')]

for _ in range(n - 1):
    a.append(l('x' + input() + 'x'))

    for j in range(1, 4):
        if a[1][j][0] == MAX:
            continue
        a[1][j] = a[0][j]
        a[1][j][1] = 0
        if a[0][j - 1][0] < MAX:
            if a[0][j - 1][0] + 1 < a[1][j][0] and a[1][j - 1][1] < 1 and a[1][j - 1][0] < MAX:
                a[1][j][0] = a[0][j - 1][0] + 1
                a[1][j][1] = 1
                a[1][j][2] = a[0][j - 1][2]
        if a[0][j + 1][0] < MAX:
            if a[0][j + 1][0] + 1 < a[1][j][0] and a[1][j + 1][1] < 1 and a[1][j+1][0] < MAX:
                a[1][j][0] = a[0][j + 1][0] + 1
                a[1][j][1] = 1
                a[1][j][2] = a[0][j + 1][2]

    del a[0]

a[0].sort()
if a[0][0][0] == MAX:
    print(-1)
else:
    print(a[0][0][2])
    print(a[0][0][0])
print(2)