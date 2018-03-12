#!/env/bin/python3


def testCase(lin):
    inf = 1e9
    works = True
    nums = [int(x) for x in lin.split()]
    abr = [inf]
    rem = [inf]
    for n in nums:
        if n > 0:
            k = abr.pop()
            rem.pop()
            if k != n:
                works = False
                break
            continue
        n *= -1
        k = rem.pop()
        if k <= n:
            works = False
            break
        k -= n
        rem.append(k)
        rem.append(n)
        abr.append(n)
    if len(abr) > 1:
        works = False
    return works


def main():
    while True:
        try:
            lin = input()
        except:
            break
        print(":-) Matrioshka!" if testCase(lin) else ":-( Try again.")


main()
