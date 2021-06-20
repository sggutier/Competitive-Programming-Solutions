#!/env/bin/python3


def divo(lin):
    return int(lin[:-1], base=2) % 131071 == 0


def main():
    str = ""
    while True:
        try:
            lin = input()
        except:
            break
        str += lin
        if lin[-1:] == '#':
            print("YES" if divo(str) else "NO")
            str = ""


if __name__ == "__main__":
    main()
