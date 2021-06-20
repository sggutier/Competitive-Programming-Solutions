limN = 250000
limW = 22001
d9 = int(1e9)


def precalca():
    esComp = [False for i in range(limN)]
    ans = []
    for i in range(3, limN):
        if not esComp[i]:
            j = 2*i
            while j < limN:
                esComp[j] = True
                j += i
    a, b = 1, 1
    for i in range(3, limN):
        c = a+b
        if esComp[i]:
            a = b
            b = c
            continue
        ans.append(c)
        if len(ans) >= limW:
            return ans
        if len(ans) < 200:
            print("%d %s" % (i, str(ans[len(ans)-1])[:9]))
        a = b
        b = c
    return ans


def main():
    ans = precalca()
    while True:
        try:
            n = int(input())
        except:
            break
        print(str(ans[n-1])[:9])


main()
