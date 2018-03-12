n,k,r,T = (0, 0, 0, 0)

def g(x):
    return (x*(x+1))//2;

def c(x):
    return x*x*x;

def testCase(n, k):
    return (n-k+1)*((6*g(k)+1))+c(k)

def main():
    tc = int(input())
    while tc>0:
        tc -= 1
        n, k = [int(x) for x in input().split()]
        print(testCase(n,k))

main()
