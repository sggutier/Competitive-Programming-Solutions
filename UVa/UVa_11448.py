
def main():
    n = int(input())
    for i in range(n):
        x, y = [int(x) for x in input().split()]
        print(x-y)

main()
