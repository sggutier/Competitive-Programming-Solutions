

def testCase():
    n = int(input())
    ans = int(1e9)
    aar = []
    for i in range(n):
        w  = len(input().split())
        if w < ans:
            ans = w
            aar = []
        if w == ans:
            aar.append(i+1)
    return ' '.join([str(x) for x in aar])


def main():
    n = int(input())
    for i in range(n):
        if i > 0:
            input()
        print(testCase())


main()
