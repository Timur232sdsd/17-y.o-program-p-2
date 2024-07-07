x = []
for n in range(1, 100):
    s = bin(n)[2:]
    if s.count('1') % 2 == 0:
        s = '11' + s[2:] + '00'
    if s.count('1') % 2 == 0:
        s = '11' + s[2:] + '00'
    else:
        s = '10' + s[2:] + '11'
    i = int(s, 2)
    if i < 1500:
        x.append(i)
    
print(max(x))