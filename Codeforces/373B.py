w, m, k = [ int(a) for a in raw_input().split() ]

pot = 10
tam = 1
res = 0

while pot<=m :
	pot *= 10
	tam += 1

while tam*k<=w :
	r = min( pot-m, w/(k*tam) )
	res += r
	if r!=pot-m :
		break
	w -= r*tam*k
	m = pot
	pot *= 10
	tam += 1

print res
