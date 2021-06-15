N = int( raw_input() )
dis = [ int(a) for a in raw_input().split() ]
s, t = [ int(a)-1 for a in raw_input().split() ]
tot = 0
res = 0

if s>t :
	s, t = t, s

for i in xrange(N) :
	tot += dis[i]
while s<t :
	res += dis[s] 
	s += 1

print min(res,tot-res)
