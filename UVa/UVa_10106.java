import java.math.* ;
import java.util.* ;
import java.io.* ;

class Main {
    public static void main( String[] args ) {
        Scanner ent = new Scanner(System.in) ;

        while( ent.hasNextBigInteger() ) {
            BigInteger n = ent.nextBigInteger(), k = ent.nextBigInteger() ;
            System.out.println( n.multiply(k) ) ;
        }
    }
}
