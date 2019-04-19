def yang(x):
    if x > 1:
        print("yang" + str(x))
        return  yang(x-1)
    else:
        return 0
yang(30)