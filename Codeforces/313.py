N = raw_input()
print max( max( int(N[:-1]), int(N[:-2] + N[-1:]) ), int(N) )
