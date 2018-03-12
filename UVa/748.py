#!/env/python3


def testCase(p, q, r):
    ult = len(q)-1
    while(ult > 0 and q[ult] == '0'):
        ult -= 1
    q = q[:ult+1]
    r = int(r)
    digs = len(q)*r
    p = int(p+q)
    num = str(p**r)
    num = max(0, digs-len(num))*'0' + num
    return num[:-digs] + '.' + num[-digs:]


def main():
    while True:
        try:
            line = input()
        except:
            break
        a, b = line.split()
        a = a.split('.')
        print(testCase(a[0], a[1], b))


if __name__ == "__main__":        
    main()
