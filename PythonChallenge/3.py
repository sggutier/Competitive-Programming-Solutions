from sys import argv

script, nomArchivo = argv

chiv = open(nomArchivo)
ltr = ""
res = ""

for line in chiv:
	ltr += line[:-1]

for c in range(len(ltr)-6) :
	posb = True
	for i in range(7):
		if ltr[i+c].isupper()==(i==3) :
			posb = False
	if posb==True :
		for i in range(7):
			res += ltr[i+c]
		print res
		res = ""


