n = int(input())
v = []
for i in range(n):
    c = int(input())
    v.append(c)

v.sort()
ok = False
for i in range(2, n):
    if (v[i - 1] + v[i - 2] > v[i]):
        ok = True
        print(str(v[i - 2]) + ' ' + str(v[i - 1]) + ' ' + str(v[i]))
        break

if (ok == False):
    print("0 0 0")
