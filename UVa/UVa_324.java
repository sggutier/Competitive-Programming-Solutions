import java.math.* ;
import java.util.* ;
import java.io.* ;

class Main {
    static int[][] cuentaNums ;

    static void cuenta(int res[], BigInteger A) {
	String S = A.toString() ;
	int N = S.length() ;

	for( int i=0; i<N; i++ )
	    res[ ((int) S.charAt(i)) - '0' ] ++ ;
    }
	
    static void precarga() {
	BigInteger act = new BigInteger("1") ;
	cuentaNums = new int[370][10] ;

	for( int i=1; i<=366; i++ ) {
	    act = act.multiply( new BigInteger( Integer.toString(i) ) ) ;
	    cuenta( cuentaNums[i], act ) ;
	}
    }
	
    public static void main( String[] args ) {
	Scanner ent = new Scanner(System.in) ;

	precarga() ;

	while( ent.hasNextInt()  ) {
	    int n = ent.nextInt() ;
	    if( n==0 )
		break ;
	    System.out.printf("%d! --\n",n ) ;
	    for( int i=0; i<5; i++ )
		System.out.printf("   (%d)  %3d", i, cuentaNums[n][i] ) ;
	    System.out.printf("\n" ) ;
	    for( int i=5; i<10; i++ )
		System.out.printf("   (%d)  %3d", i, cuentaNums[n][i] ) ;
	    System.out.printf("\n" ) ;
	}
    }
}
