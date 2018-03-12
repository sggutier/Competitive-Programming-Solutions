from sys import argv

script, nomArchivo = argv

chiv = open(nomArchivo)

cnt = {}

for line in chiv:
	for c in line:
		if not( c in cnt ):
			cnt[c] = 0
		cnt[c] += 1

res = ""

for line in chiv:
	for c in line:
		if cnt[c]<30 :
			res += c
			print c

print res
