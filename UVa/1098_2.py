import os
import sys
import random
import time

filename, nom, N, M = sys.argv
N = int(N)
M = int(M)

fin = False
n, m, a, b, c = ( 0, 0, 0, 0, 0 )
by = 0

for x_0 in range( 0, N ):
    for y_0 in range ( 0, M) :
        A = ( x_0, y_0 )
        for x_1 in range( 0, N ):
            for y_1 in range ( 0, M) :
                B = ( x_1, y_1 )
                if A==B :
                    continue 
                for x_2 in range( 0, N ):
                    for y_2 in range ( 0, M) :
                        C = ( x_2, y_2 )
                        if C==A or C==B :
                            continue

                        # print "%d %d" % ( N, M )
                        # print "%d %d %d %d %d %d" % ( A[0], A[1], B[0], B[1], C[0], C[1] )

                        F = open( "%s.in" % nom, "w" )
                        F.write( "%d %d\n" % ( N, M ) )
                        F.write( "%d %d %d %d %d %d\n" % ( A[0], A[1], B[0], B[1], C[0], C[1] ) )
                        F.write( "0 0" )
                        F.close()

                        # X = time.time()    
                        os.system("./a.out < %s.in > %s.out" % ( nom, nom ) )
                        # Y = time.time()-X

                        F = open( "%s.out" % nom, "r" )
                        Y = int( ( F.readline().split(' ') )[2] )
                        F.close()
                        # print S
                        # os.system( "cat 1098.out" )
                        # exit()
                        # print Y
                        if Y>by :
                            n, m, a, b, c = ( N, M, A, B, C )
                            by = Y
    
print "%d %d" % ( n, m )
print "%d %d %d %d %d %d" % ( a[0], a[1], b[0], b[1], c[0], c[1] )
