import java.math.* ;
import java.util.* ;
import java.io.* ;

class Main {
    static BigInteger[] fib ;
	
    static void precarga() {
	fib = new BigInteger[1001] ;
	fib[0] = new BigInteger("1") ;
	fib[1] = new BigInteger("1") ;
	for( int i=2; i<=1000; i++ ) {
	    fib[i] =  fib[i-1].multiply( new BigInteger(Integer.toString(i)) ) ;
	}
    }
	
    public static void main( String[] args ) {
	Scanner ent = new Scanner(System.in) ;

	precarga() ;

	while( ent.hasNextInt() ) {
	    int n = ent.nextInt() ;
	    System.out.println( n + "!\n" + fib[n] ) ;
	}
    }
}
