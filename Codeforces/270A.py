N = int( raw_input() )

for i in xrange(N) :
	a = int( raw_input() )
	print "YES" if 360%(180-a)==0 else "NO"
