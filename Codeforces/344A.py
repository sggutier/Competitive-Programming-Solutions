N = int(raw_input())
ult = "33"
res = 0

for i in xrange(N):
	tmp = raw_input()
	if tmp!=ult or i==0:
		res += 1
	ult = tmp

print res
