import java.math.* ;
import java.util.* ;
import java.io.* ;

class Main {
    static BigInteger[] fact ;
    static int[] sum ;

    static int calcDig( String S ) {
        int N = S.length() ;
        int res = 0 ;

        for( int i=0; i<N; i++ )
            res += ( S.charAt(i) - '0' ) ;

        return res ;
    }
	
    static void precarga() {
        fact = new BigInteger[1003] ;
        sum = new int[1003] ;
        fact[0] = new BigInteger("1") ;
        sum[0] = 1 ;
        for( int i=1; i<1003; i++ ) {
            // fib[i] =  fib[i-1].add( fib[i-2] ) ;
            fact[i] = fact[i-1].multiply( new BigInteger( String.valueOf(i) )  ) ;
            sum[i] = calcDig( fact[i].toString() ) ;
        }
    }
	
    public static void main( String[] args ) {
        Scanner ent = new Scanner(System.in) ;

        precarga() ;

        while( ent.hasNextInt() ) {
            int A = ent.nextInt() ;
            System.out.printf( "%d\n", sum[A] ) ;
        }
    }
}
