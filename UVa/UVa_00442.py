

def calca():
    global S, pos, mats
    c = S[pos]
    if 'A' <= c and c <= 'Z':
        pos += 1
        c = ord(c)-ord('A')
        return (mats[c][0], mats[c][1], 0)
    pos += 1
    x = calca()
    y = calca()
    pos += 1
    if x and y and x[1] == y[0]:
        return (x[0], y[1], x[0]*y[1]*x[1] + x[2] + y[2])
    return None


def main():
    global S, pos, mats
    mats = [None for i in range(26)]
    w = int(input())
    for i in range(w):
        lin = input().split()
        mats[ord(lin[0]) - ord('A')] = (int(lin[1]), int(lin[2]))
    while True:
        try:
            S = input()
        except:
            break
        pos = 0
        ans = calca()
        if ans:
            print(ans[2])
        else:
            print("error")


main()
