

def main():
    r, c = [int(x) for x in input().split()]
    ans = 0
    for i in range(r):
        ans = max(ans, min([int(x) for x in input().split()]))
    print(ans)


main()
