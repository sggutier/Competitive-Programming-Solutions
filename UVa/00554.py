#!/env/python3.5


def chaToI(a):
    return 0 if a == ' ' else ord(a) - ord('A') + 1


def iToCha(a):
    return ' ' if a == 0 else chr(a-1+ord('A'))


def convo(dicto, line, n, k):
    otr = list(line)
    for i in range(n):
        otr[i] = iToCha((chaToI(otr[i]) + k) % 27)
    return ''.join(otr)


def decrypt(dicto, line):
    ans, posAns = (-1, 0)
    n = len(line)
    for k in range(0, 27):
        cnt = 0
        for w in convo(dicto, line, n, k).split():
            if w in dicto:
                cnt += 1
        if cnt > ans:
            ans = cnt
            posAns = k
    return convo(dicto, line, n, posAns)


def main():
    dicto = set()
    while True:
        line = input()
        if line == '#':
            break
        dicto.add(line)
    line = input()
    ans = decrypt(dicto, line).split()
    sumo = 0
    for w in ans:
        k = len(w)
        if sumo > 0:
            sumo += 1
        if sumo + k > 60:
            sumo = 0
            print()
        elif sumo > 0:
            print(' ', end='')
        print(w, end='')
        sumo += k
    print()


main()
