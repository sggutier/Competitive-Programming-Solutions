N = int(raw_input())
A = [ int(a) for a in raw_input().split() ]
K = int(raw_input())

for i in range(K) :
	r, c = [ int(a) for a in raw_input().split() ]
	A[r-1] -= c
	if r>1 :
		A[r-2] += c-1
	if r<N :
		A[r] += A[r-1]
	A[r-1] = 0

print "\n".join( [str(w) for w in A] )
