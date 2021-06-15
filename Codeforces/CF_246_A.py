N = int(raw_input() )

if( N<3 ) :
	print "-1"
	exit(0) 

res = [str(N)]
for i in range(2,N) :
	res.append(str(i)) 
res.append("1")

print " ".join( res )
