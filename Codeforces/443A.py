d = dict()
S = raw_input()
S = S[1:len(S)-1]

for i in S.split(', '):
    if not i in d:
        d[i] = 1

print min( len(d), len(S) )
