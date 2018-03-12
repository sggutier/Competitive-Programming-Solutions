#!/env/python3


def precalc():
    global ans
    ans = [0 for i in range(27)]
    cat = [0 for i in range(27)]
    pars = [0 for i in range(27)]
    cat[0] = cat[1] = 1
    for i in range(2, 27):
        for j in range(1, i):
            cat[i] += cat[j]*cat[i-j]
    pars[0] = 1
    for i in range(1, 27):
        s = 0
        for j in range(1, i-1):
            s += pars[j+1]*pars[i-1-j]
        pars[i] = pars[i-1] + s*2
    for i in range(1, 27):
        ans[i] = pars[i]-cat[i]


def main():
    global ans
    precalc()
    while True:
        try:
            n = int(input())
        except:
            break
        print(ans[n])


if __name__ == "__main__":
    main()
