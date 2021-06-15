
tors = [[], [], []]


def mueve(a, c):
	global mov
	mov += 1
	print(f'mov {mov}:')
	c.append(a.pop())
	for i in range(3):
		print(tors[i])
	print('-----')
	if len(tors[0]) == len(tors[1]) and len(tors[0]) == len(tors[2]):
		print('aguanta')
		exit(0)


def hanoi(a, b, c, lev):
	if lev == 0:
		mueve(a, c)
		return
	hanoi(a, c, b, lev-1)
	mueve(a, c)
	hanoi(b, a, c, lev-1)
	

def main():
	global mov
	mov = 0
	with open('input.txt') as fp:
		for line in iter(fp.readline, ''):
			n = int(line)
	n //= 3
	with open('output.txt', 'w') as f:
		if n % 2 == 0:
			print(2**(2*n - 1) + 2**(n-1) -1, file=f)
		else:
			print(2**(2*n-1) + 2**n - 2, file=f)
	return
	n *= 3
	tors[0] = [n-1-i for i in range(n)]
	hanoi(tors[0], tors[1], tors[2], n-1)
	
	
main()
