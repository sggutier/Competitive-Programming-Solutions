A = int( raw_input() ) 
res = 0

for i in xrange(A) :
	res += (A-i)*i +1

print res
