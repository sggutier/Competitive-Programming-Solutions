N = int( raw_input() ) 
A = [ i for i in raw_input().split() ]
X, Y = 0, 0
res = ""

for i in A :
	if i=='5' :
		X += 1
	else :
		Y += 1

if Y>0 :
	if X/9 > 0 :
		print "555555555"*(X/9) + "0"*Y 
	else :
		print "0"
else :
	print "-1"

