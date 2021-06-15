N, x = [ int(gna) for gna in raw_input().split() ]
A = [ a for a in raw_input() ]

for w in range(x) :
	i = 0
	while i+1<N :
		if A[i]=='B' and A[i+1]=='G' :
			A[i], A[i+1] = A[i+1], A[i]
			i += 1
		i += 1

print "".join(A)
