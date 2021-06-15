N = int( raw_input() ) 
cntA = [ 0 for i in xrange(105) ]
cntB = [ 0 for i in xrange(105) ]
res = 0

for i in xrange(N) :
	a, b = [ int(w) for w in raw_input().split() ]
	cntA[a] += 1
	cntB[b] += 1

for i in xrange(105) :
	res += cntA[i]*cntB[i]

print res
