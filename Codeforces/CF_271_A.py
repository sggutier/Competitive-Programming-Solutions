from sets import Set

N = int( raw_input() )

N += 1
while True :
	mapa =  Set( [x for x in str(N)] )
	if len(mapa)==4 :
		print N
		break
	N += 1
