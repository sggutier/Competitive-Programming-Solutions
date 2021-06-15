N = int(raw_input())
arr = sorted( int(i) for i in raw_input().split(' ') )
res = ""

for i in range(N):
    res += "%d " % arr[i]

print res


