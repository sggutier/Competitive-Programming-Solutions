import os
import sys
import random
import time

filename, nom = sys.argv

fin = False
n, m, a, b, c = ( 0, 0, 0, 0, 0 )
by = 0

for i in range(0,1000):
    random.seed( time.time() )
    time.sleep(0.1)
    N = random.randint( 2, 8 )
    random.seed( time.time() )
    time.sleep(0.1)
    M = random.randint( 2, 8 ) 

    
    while True:
        time.sleep(0.1)
        A = ( random.randint(0,N-1), random.randint(0,M-1) )
        time.sleep(0.1)
        B = ( random.randint(0,N-1), random.randint(0,M-1) )
        time.sleep(0.1)
        C = ( random.randint(0,N-1), random.randint(0,M-1) )
        if A!=B and B!=C and A!=C :
            break

    # print "%d %d" % ( N, M )
    # print "%d %d %d %d %d %d" % ( A[0], A[1], B[0], B[1], C[0], C[1] )


    F = open( "1098.in", "w" )
    F.write( "%d %d\n" % ( N, M ) )
    F.write( "%d %d %d %d %d %d\n" % ( A[0], A[1], B[0], B[1], C[0], C[1] ) )
    F.close()

    os.system("./a.out < %s.in > %s.out" % ( nom, nom ) )

    F = open( "%s.out" % nom, "r" )
    Y = int( ( F.readline().split(' ') )[2] )
    F.close()

    if Y>by :
        n, m, a, b, c = ( N, M, A, B, C )
        by = Y
    
print "%d %d" % ( n, m )
print "%d %d %d %d %d %d" % ( a[0], a[1], b[0], b[1], c[0], c[1] )
