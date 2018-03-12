N = int( raw_input() ) 
S = raw_input()

res = 0
N -= 1

for i in range(N) :
	if S[i]==S[i+1] :
		res += 1

print res
