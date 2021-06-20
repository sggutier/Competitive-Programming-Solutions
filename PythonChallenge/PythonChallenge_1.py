while True:
	line = raw_input()
	res = ""
	for c in line:
		if ord(c)>=ord('a') and ord(c)<=ord('z') :
			res += chr((ord(c)-ord('a')+2)%26+ord('a'))
		else :
			res += c
	print res

# 
