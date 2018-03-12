maneras = []

def precarga(n=1000000):
    global maneras
    maneras = [0 for i in range(n)]
    maneras[0] = 1
    for i in range(1, n):
        maneras[i] = (i+1)*i//2 + (i+1)


def main():
    precarga()
    while True:
        try:
            n = int(input())
            print(maneras[n//2])
        except:
            break


main()
