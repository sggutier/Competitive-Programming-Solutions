N = int(raw_input())
A = [ int(i) for i in raw_input().split() ]
cnt = [ 0, 0, 0 ]

for i in range(N) :
	cnt[i%3] += A[i]

if cnt[0]>cnt[1] and cnt[0]>cnt[2] :
	print "chest"
elif cnt[1]>cnt[0] and cnt[1]>cnt[2] :
	print "biceps"
else :
	print "back"
