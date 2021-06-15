import random

K, N = [ int(i) for i in raw_input().split() ]
A = [ int(i) for i in raw_input().split() ]

def ord( L, R, piv ) :
	A[piv], A[R] = A[R], A[piv]
	tam = L
	for i in range(L,R) :
		if A[i] < A[R] :
			A[i], A[tam] = A[tam], A[i]
			tam += 1
	A[tam], A[R] = A[R], A[tam]
	return tam

def rapidoSort( L, R ) :
	if L>=R :
		return
	piv = random.randrange(L,R+1)
	piv = ord( L, R, piv )
	rapidoSort( L, piv-1 )
	rapidoSort( piv+1, R )

rapidoSort(0,N-1)

res = 2000000000

for i in range(N-K+1) :
	res = min( res, A[i+K-1]-A[i] )

print res
