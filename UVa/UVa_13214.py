pasc = []

def precarga(n=26):
    global pasc
    pasc = [[0 for i in range(n)] for j in range(n)]
    for i in range(n):
        pasc[1][i] = 1
    for i in range(2, n):
        for j in range(1, n):
            pasc[i][j] = pasc[i-1][j] + pasc[i][j-1]

def main():
    global pasc
    precarga()
    tc = int(input())
    while tc>0:
        tc -= 1
        a, b = [int(x) for x in input().split()]
        print(pasc[a][b])

main()
