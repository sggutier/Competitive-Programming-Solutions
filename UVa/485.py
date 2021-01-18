#!/usr/bin/env python3

def main():
    maxo = 10**60
    ans = [1]
    print(ans[0])
    while True:
        n = len(ans)
        nxt = [1 for i in range(n+1)]
        for i in range(1, n):
            nxt[i] = ans[i-1] + ans[i]
        print(' '.join([str(x) for x in nxt]))
        if max(nxt) >= maxo:
            break
        ans = nxt


main()
