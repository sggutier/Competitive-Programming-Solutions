import java.math.* ;
import java.util.* ;
import java.io.* ;

class Main {
    public static void main( String[] args ) {
        Scanner ent = new Scanner(System.in) ;

        while( ent.hasNextInt() ) {
            int n = ent.nextInt() ;
            if(n>=0)
                break;
            System.out.println( Integer.toString(n,3) );
        }
    }
}
