N = int(raw_input())
A = [ int(a) for a in raw_input().split() ]
res = -1000000000
tot = 0

for i in range(0,N) :
	tot += A[i]
	for j in range(i,N) :
		tmp = 0
		fug = ""
		for k in range(i,j+1) :
			if A[k]==1 :
				tmp -= 1
			else :
				tmp += 1
			fug += str(k)
		res = max( res, tmp )

print res + tot
