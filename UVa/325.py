import re


def testCase(str):
    if re.search(r"((?:^[+,-]?[0-9]+\.[0-9]+$)|(?:^[+,-]*[0-9]+(\.[0-9]+)?[E,e][+,-]?[0-9]+$))", str):
        print(str + " is legal.")
    else:
        print(str + " is illegal.")


def main():
    while True:
        str = input()
        if str == '*':
            break
        testCase(str.strip())


main()
