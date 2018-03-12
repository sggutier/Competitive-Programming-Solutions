#!/env/python3


pasc = []


def precarga(n=50):
    global pasc
    n += 1
    pasc = [[0 for i in range(n)] for y in range(n)]
    for i in range(n):
        pasc[i][0] = pasc[i][i] = 1
        for j in range(1, i):
            pasc[i][j] = pasc[i-1][j-1] + pasc[i-1][j]


def printea(a, e):
    if(e == 1):
        print(a, end='')
    elif(e > 0):
        print(a, end='')
        print("^" + str(e), end='')


def expo(a, b, pot):
    global pasc
    for j in range(pot+1):
        i = pot-j
        if(pasc[pot][i] > 1):
            print("{}*".format(pasc[pot][i]), end="")
        printea(a, i)
        if(i > 0 and j > 0):
            print('*', end='')
        printea(b, j)
        print("", end=('\n' if i == 0 else '+'))


def main():
    precarga()
    tc = int(input())
    for i in range(tc):
        line = input().split("^")
        print("Case {}: ".format(i+1), end='')
        a, b = line[0].split('+')
        expo(a[1:], b[:-1], int(line[1]))


if __name__ == "__main__":
    main()
