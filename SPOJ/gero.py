import random

n = int(input())
print("%d %d" % (n, n//2))
for i in range(n):
    print(chr(ord('a') + random.randrange(0, 26)), end='')
