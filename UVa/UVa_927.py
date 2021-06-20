def test_case(poly, d, k):
    suma, n = (0,0)
    while(suma < k):
        n += 1
        suma += n*d
    return sum(list(map(lambda c, p: c*(n**p), poly, list(range(len(poly))))))


def get_input():
    poly = list(map(int, input().split()))
    d = int(input())
    k = int(input())
    return poly[1:], d, k


def main():
    tc = int(input())
    for i in range(tc):
        print(test_case(*get_input()))


main()
