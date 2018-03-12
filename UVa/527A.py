

def main():
    a, b = [int(x) for x in input().split()]
    ans = 0
    while a > 0 and b > 0:
        if a < b:
            a, b = b, a
        ans += a//b
        a %= b
    print(ans)

main()
