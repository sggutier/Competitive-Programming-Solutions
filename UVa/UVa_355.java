import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.max;

public class Main {
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
    //--------------------------------------------------------

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        int srcB ;
        while(true) {
            try {
                srcB = sc.nextInt();
            } catch (Exception e) {
                break;
            }
            int tgtB = sc.nextInt();
            String num = sc.next();
            try {
                System.out.printf("%s base %d = %s base %d\n", num, srcB, (new BigInteger(num, srcB)).toString(tgtB).toUpperCase(), tgtB);
            }
            catch(Exception e) {
                System.out.printf("%s is an illegal base %d number\n", num, srcB);
            }
        }
    }
}
