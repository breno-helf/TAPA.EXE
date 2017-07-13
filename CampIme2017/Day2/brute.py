e = 1

for i in range(1101):
    s = e * e
#    print(i)
 #   print(e)
    print(i + 1)
    print(s)
    print(len(str(s)))
    print()
    e *= 10
    e += 1

'''
#for k in range(11):
#    v = []
#    for i in range(1, k):
#        v += [i]
#    for i in range(0, k):
#        v += [k - i]

#    acc = 0

 #   for i in v:
  #      print(i, end = ' ')
   # print()
    
    for i in range(len(v) - 1, -1, -1):
        print(acc, end = ' ')
        acc = (acc + v[i]) // 10
    print()
    print()
'''
