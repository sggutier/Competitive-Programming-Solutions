bdsong = ("Happy birthday to you Happy birthday to you Happy birthday"
          " to Rujia Happy birthday to you").split(' ')

n = int(input())
names = [input() for i in range(n)]
bdSongLen = len(bdsong)

pos = 0
while(pos < n or pos % bdSongLen != 0):
    print(names[pos % n] + ": " + bdsong[pos % bdSongLen])
    pos += 1
