def mcd(a,b):
	while b!=0:
		c = a%b
		a = b
		b = c
	return a

tmp = raw_input().split(' ')
X = int(tmp[0])
Y = int(tmp[1])
A = raw_input()
B = raw_input()
N = len(A)
M = len(B)
Q = mcd(N,M)
usd = [ False for i in xrange(N) ]
usd2 = [ False for j in xrange(M) ]
con = -ord('a')
res = 0

quak = 0
gna = N/ Q
X /= M/ Q
Y /= M / Q

for i in range(0, Q):
	if usd[i] == True:
		continue
	quak += 1
	pos = i
	rep = [ 0 for w in xrange(26) ] 
	while usd[pos] == False :
		usd[pos] = True
		rep[ ord(A[pos]) + con ] += 1
		pos = (pos+M)%N 
	j = i
	while usd2[j] == False :
		usd2[j] = True
		act = ord(B[j]) + con
		res += (gna-rep[act])*X
		j = (j+Q)%M 


print res
