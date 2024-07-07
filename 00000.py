for a in range(1,1000):
    for b in range(1,1000):
        for d in range(-1000,1000):
            if (b*27/5 == a+7*d) and (b*9 == a+2*d + 33) and (b*9 == 3*(a+3*d)):
                print(a+b)
