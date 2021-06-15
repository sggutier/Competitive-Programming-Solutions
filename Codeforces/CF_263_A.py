M = [ raw_input().split(' ') for i in xrange(5) ]

for i in xrange(5) :
	for j in xrange(5) :
		if M[i][j]=='1' :
			print abs(i-2) + abs(j-2)
