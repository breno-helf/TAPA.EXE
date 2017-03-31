fin = open('input.txt', 'r')
fout = open('output.txt', 'w')

n = int(fin.read())
fout.write(str(8 * (9 ** (min(n - 1, 8))) * (10 ** (max(0, n - 9)))))
