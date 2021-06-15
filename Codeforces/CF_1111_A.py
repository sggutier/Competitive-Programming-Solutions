vocs = 'aoeui'

def dts(s):
    return [1 if x in vocs else 0 for x in s]

def main():
    print('Yes' if dts(input()) == dts(input()) else 'No')


print('Hello there')
# main()
