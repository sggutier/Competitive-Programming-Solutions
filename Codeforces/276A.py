N, K = [ int(k) for k in raw_input().split() ]
res = -2000000000

for i in xrange(N) :
	a, b = [int(k) for k in raw_input().split() ]
	res = max( res, a-max(0,b-K)  )

print res
