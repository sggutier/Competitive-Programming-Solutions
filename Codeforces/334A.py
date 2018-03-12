N = int( raw_input() )

a=1
b=N*N

for i in xrange(N) :
	gna = ""
	for j in xrange(N/2) :
		gna += " " + str(a) + " " + str(b)
		a += 1 
		b -= 1
	print gna[1:]
