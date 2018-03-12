import java.math.* ;
import java.util.* ;
import java.io.* ;

class Main {
    // class Actual {
	
    public static void main( String[] args ) {
        Scanner ent = new Scanner(System.in) ;
        BigInteger sev = new BigInteger("17");

        while( ent.hasNextBigInteger() ) {
            BigInteger A = ent.nextBigInteger();
            if(A.equals(BigInteger.ZERO))
                break ;
            System.out.printf("%d\n", A.remainder(sev).equals(BigInteger.ZERO)? 1:0);
            // System.out.println(A.remainder(sev));
        }
    }
}
