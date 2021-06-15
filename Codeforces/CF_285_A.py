N, K = [ int(i) for i in raw_input().split() ]
A = [ i+1 for i in range(N) ]

A[K], A[N-1] = A[N-1], A[K]

print " ".join( [str(i) for i in A] )
