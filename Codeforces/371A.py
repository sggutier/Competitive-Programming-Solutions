N, K = [ int(a) for a in raw_input().split() ]
arr = [ int(a) for a in raw_input().split() ]
res = 0 

for i in range(K):
	cnt = [0,0] 
	for j in range(N/K) :
		cnt[ arr[j*K +i]-1 ] += 1
	res += min( cnt[0], cnt[1] )

print res 
