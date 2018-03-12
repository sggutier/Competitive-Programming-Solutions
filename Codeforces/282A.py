res = 0
N = int( raw_input() )

for i in xrange(N) :
	tmp = raw_input() 
	if tmp[0]=='X' :
		res += 1 if tmp[1:]=='++' else -1
	else :
		res += 1 if tmp[:-1]=='++' else -1

print res
