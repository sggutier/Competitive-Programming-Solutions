K = int( raw_input() ) 
mat = [raw_input() for i in range(4) ]
cnt = [ 0 for i in range(10) ]

for x in mat :
	for y in x :
		if y=='.' :
			continue
		cnt[ int(y) ] += 1

for a in cnt :
	if a>K*2 :
		print "NO"
		exit(0)

print "YES"
