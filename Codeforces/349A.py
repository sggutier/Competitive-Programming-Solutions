N = int(raw_input())
a, b, c = 0, 0, 0

for i in raw_input().split() :
	if i=="25" : 
		a += 1
	elif i=="50" :
		if a<=0 :
			print "NO"
			exit(0)
		a -= 1
		b += 1
	elif i=="100" :
		if b>=1 and a>=1 :
			a -= 1
			b -= 1
		elif a>=3 :
			a -= 3
		else :
			print "NO"
			exit(0) 

print "YES" 
