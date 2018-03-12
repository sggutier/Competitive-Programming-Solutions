#!/usr/env/python3


def valido(lista, ini, fin, dep, ans):
    # print(str(ini) + " => " + str(fin))
    if ini > fin:
        return True
    # print(str(lista[ini:fin+1]) + " " + str(ini) + " " + str(fin) + " " + str(dep))
    if len(lista[ini]) != dep:
        return False    
    ans[ini] = (dep, ini)
    if ini == fin:
        return True
    ini += 1
    piv = ini
    while piv <= fin and lista[piv][dep] == 'L':
        piv += 1
    return valido(lista, ini, piv-1, dep+1, ans) and valido(lista, piv, fin, dep+1, ans)


def testCase(lista):
    lista.sort()
    n = len(lista)
    lista = list(zip(*lista))
    # print(lista)
    ans = [0 for x in range(n)]
    if valido(lista[0], 0, len(lista[0])-1, 0, ans):
        ans.sort()
        # print(ans)
        # return ' '.join([lista[1][ans[x][1]] for x in range(n)])
        for i in range(n):
            print(lista[1][ans[i][1]], end="\n" if i==n-1 else " ")
    else:
        print("not complete")


def main():
    lista = []
    while True:
        try:
            linea = input()
        except:
            break
        for par in linea.split():
            if par == "()":
                testCase(lista)
                # print(testCase(lista))
                # print("not complete")
                lista = []
            else:
                ro = par[1:-1].split(",")
                lista.append((ro[1], ro[0]))


main()
