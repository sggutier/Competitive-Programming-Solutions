#!/env/bin/ python3
import re


def testCase(lin):
    ans = 0
    try:
        lin = lin.split('=')
        a, b = [int(x) for x in re.match(r"(\d+)([+-]\d+)", lin[0]).groups()]
        c = int(lin[1])
        if a+b == c:
            ans = 1
    except:
        pass
    return ans


def main():
    ans = 0
    while True:
        try:
            lin = input()
        except:
            break
        ans += testCase(lin)
    print(ans)


if __name__ == "__main__":
    main()
