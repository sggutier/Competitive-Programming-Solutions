stpNum = []
rev = []

def precarga():
    global stpNum, rev
    stpNum = [-1 for i in range(100)]
    rev = [-1 for i in range(100)]
    pot = 1
    stp = 0
    while stpNum[pot] == -1:
        rev[stp] = pot
        stpNum[pot] = stp
        pot = (pot*66)%100
        stp += 1


def testCase(n):
    global stpNum, rev
    if n >= 2:
        n = (n-2)%5
        print(rev[n+2])
    else:
        print(rev[n])


def main():
    precarga()
    tc = int(input())
    while tc>0:
        lin = input()
        testCase(int(lin))
        tc -= 1

if __name__ == "__main__":
    main()
