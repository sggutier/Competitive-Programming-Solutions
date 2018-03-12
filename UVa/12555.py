import math

def procesa():
    

def main():
    n = int(input())
    tc = 0
    for i in range(n):
        ans = procesa(input())
        tc += 1
        if ans % 10 != 0:
            print("Case %d: %d.%d%d" % (tc, ans//100, (ans//10)%10, ans%10))
        elif (ans//10) % 10 != 0:
            print("Case %d: %d.%d" % (tc, ans//100, (ans/10)%10))
        else:
            print("Case %d: %d" % (tc, ans//100))


main()
