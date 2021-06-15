N = int(raw_input())
A = [ int(i) for i in raw_input().split() ]
tot = 0 
res = 0

for i in range(N) :
	tot += A[i]

for i in range(0,5) :
	if( (tot+i)%(N+1)!=0 ) :
		res += 1

print res
