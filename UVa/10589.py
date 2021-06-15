#!/env/bin/python3

mo = int(1e7)


class Point:
    def __init__(self, x=0.0, y=0.0):
        self.x = x
        self.y = y


def insideCircle(p, c, r):
    dx = p.x - c.x
    dy = p.y - c.y
    Euc = dx * dx + dy * dy
    rSq = r * r
    return 0 if Euc < rSq else (1 if Euc == rSq else 2)


def testCase(N, a, cords):
    a *= mo
    pts = [Point(0, 0), Point(0, a), Point(a, 0), Point(a, a)]
    M = 0
    for W in cords:
        works = True
        for j in range(4):
            if insideCircle(W, pts[j], a) == 2:
                works = False
                break
        if works:
            M += 1
    a //= mo
    return M*a*a/N


def main():
    while True:
        n, a = [int(x) for x in input().split()]
        if n == 0 and a == 0:
            break
        cords = []
        for i in range(n):
            x, y = [int(x.replace('.', '')) for x in input().split()]
            cords.append(Point(x, y))
        print("%.5f" % testCase(n, a, cords))


main()
