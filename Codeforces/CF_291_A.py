N = int( raw_input() )
A = [ int(a) for a in raw_input().split() ] 
rec = {}
res = 0

for i in A :
	rec[i] = 0

for i in A :
	rec[i] += 1

for a,c in rec.iteritems() :
	if a!=0 and c>2 :
		print "-1"
		exit(0)
	if a>=1 and c==2 :
		res += 1

print res
