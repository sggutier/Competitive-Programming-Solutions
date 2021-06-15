import math

pots10 = [10**i for i in range(19)]

def getAlt(n, b):
	ans = 0
	i = 0
	while n > 0:
		w = n % b
		if w >= 10:
			return 0 
		ans += pots10[i] * w
		i += 1
		n //= b
	return ans
	
def solvo(a, b, c, sg):
	det = b*b - 4*a*c
	if(det < 0 or a==0):
		return -1
	rt = int(math.sqrt(det))
	if(rt * rt != det):
		return -1
	tot = -b + sg * rt
	if(tot % (2*a)):
		return -1
	return tot // (2 * a)


def main():
	n, l = [int(x) for x in input().split()]
	ans = 10
	for i in range(11, 1000001):
		w = getAlt(n, i)
		if l <= w:
			ans = max(ans, i)
	for a in range(1, 10):
		for c in range(0, 10):
			if (n-c) % a != 0:
				continue
			x = (n-c) // a
			if l <= a*10 + c:
				ans = max(ans, x)
	for a in range(1, 10):
		for b in range(0, 10):
			for c in range(0, 10):
				x = solvo(a, b, c-n, 1)
				if l <= a*100 + b*10 + c :
					ans = max(ans, x)
				x = solvo(a, b, c-n, -1)
				if l <= a*100 + b*10 + c :
					ans = max(ans, x)
	print(ans)
	
	
main()
