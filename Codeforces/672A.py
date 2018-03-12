

def main():
    n = int(input())
    ans = ""
    for i in range(1, n+1):
        ans += str(i)
        if len(ans) > n:
            break
    print(ans[n-1])


main()
