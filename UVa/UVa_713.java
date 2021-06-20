import java.math.* ;
import java.util.* ;
import java.io.* ;

class Main {

    public static String izquierda( String A ) {
	int N = A.length(), res=N-1 ;
	for( int i=0; i<N-1; i++ ) {
	    if( A.charAt(i)!='0' ) {
		res = i ;
		break ;
	    }
	}

	return A.substring( res, N ) ;
    }
    
    public static void main( String[] args ) {
	Scanner ent = new Scanner(System.in) ;
	int T = ent.nextInt() ;

	for( int t=0; t<T; t++ ) {
	    String A = ent.next(), B = ent.next(), C ;

	    String X = new StringBuilder( A ).reverse().toString(),  Y  = new StringBuilder( B ).reverse().toString() ;

	    X = izquierda(X) ;
	    Y = izquierda(Y) ;
	    
	    BigInteger n = new BigInteger( X ), k = new BigInteger( Y ) ;

	    C = (n.add(k)).toString()  ;
	    C = new StringBuilder( C ).reverse().toString() ;
	    C = izquierda(C) ;
	    
	    System.out.println( C ) ;
	}
    }
}
