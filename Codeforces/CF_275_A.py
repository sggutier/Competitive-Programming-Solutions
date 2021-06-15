mat = [ [1 for i in range(3)] for w in range(3) ]
cmb = [ [int(a) for a in raw_input().split() ] for i in range(3) ]
dr = [ -1, 0, 1, 0 ] 
dc = [ 0, 1, 0, -1 ]

for i in range(3) :
	for j in range(3) :
		if cmb[i][j]%2==0 :
			continue 
		mat[i][j] = (mat[i][j]+1)%2
		for d in range(4) :
			x = i+dr[d] 
			y = j+dc[d]
			if( x<0 or x>2 or y<0 or y>2 ) :
				continue 
			mat[x][y] = (mat[x][y]+1)%2

for i in range(3) :
	print "%d%d%d" % ( mat[i][0], mat[i][1], mat[i][2] )
