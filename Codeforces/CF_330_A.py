R, C = [ int(x) for x in raw_input().split() ]
M = [ raw_input() for x in range(R) ]

res = 0

for i in range(R) :
	for j in range(C) :
		flag = True
		for x in range(R) :
			if M[x][j]=='S' :
				flag = False
		if flag==True :
			res += 1
			continue
		flag = True
		for x in range(C) :
			if M[i][x]=='S' :
				flag = False
		if flag==True :
			res += 1
			continue

print res
