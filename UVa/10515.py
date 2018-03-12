
def precarga():
    global ans
    ans = [[] for i in range(10)]
    for i in range(10):
        lin = ans[i]
        d = i
        while d not in lin:
            lin.append(d)
            d = (d * i) % 10


def main():
    global ans
    precarga()
    while True:
        a, b = [int(x) for x in input().split()]
        if a == 0 and b == 0:
            break
        lin = ans[a % 10]
        print(lin[(b-1) % len(lin)] if b > 0 else 1)


main()
