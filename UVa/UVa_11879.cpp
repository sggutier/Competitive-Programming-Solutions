import java.math.* ;
import java.util.* ;
import java.io.* ;

class main {
    public static void main( String[] args ) {
        cScanner ent = new Scanner(System.in) ;

        precarga() ;

        while( ent.hasBigInteger() ) {
            big n = ent.nextBigInteger(), k = ent.nextBigInteger() ;
            System.out.println( n.multiply(k) ) ;
        }
    }
}
