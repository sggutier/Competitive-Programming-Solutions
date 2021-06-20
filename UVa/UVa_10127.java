import java.math.* ;
import java.util.* ;
import java.io.* ;

class Main {
    static int unos(int S) {
	int K = 1, res=1 ;
	while( K!=0 ) {
	    res ++ ;
	    K = (K*10+1)%S ;
	}
	return res ;
    }
	
    public static void main( String[] args ) {
	Scanner ent = new Scanner(System.in) ;

	while( ent.hasNextInt() ) {
	    int n = ent.nextInt() ;
	    System.out.println( Main.unos(n) ) ;
	}
    }
}
