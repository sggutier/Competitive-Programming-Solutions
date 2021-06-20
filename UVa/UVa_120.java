import java.math.* ;
import java.util.* ;
import java.io.* ;

class Main {
    static BigInteger[] fib ;
	
    static void precarga() {
        fib = new BigInteger[5003] ;
        fib[0] = new BigInteger("0") ;
        fib[1] = new BigInteger("1") ;
        for( int i=2; i<=5000; i++ ) {
            fib[i] =  fib[i-1].add( fib[i-2] ) ;
        }
    }
	
    public static void main( String[] args ) {
        Scanner ent = new Scanner(System.in) ;

        precarga() ;

        while( ent.hasNextInt() ) {
            int n = ent.nextInt() ;
            System.out.println( "The Fibonacci number for " + n +  " is " + fib[n] ) ;
        }
    }
}
