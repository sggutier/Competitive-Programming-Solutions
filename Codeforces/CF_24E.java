import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF_24E {
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

    public static class Frac implements Comparable<Frac> {
        BigInteger num, den ;
        Frac(BigInteger num) {
            this.num = num;
            den = BigInteger.ONE;
        }
        Frac(BigInteger num, BigInteger den) {
            this.num = num;
            this.den = den;
        }
        Frac sbs(Frac b) {
            Frac a = this;
            return new Frac(a.num.multiply(b.den).subtract(b.num.multiply(a.den)), a.den.multiply(b.den));
        }
        Frac div(Frac b) {
            Frac a = this;
            return new Frac(a.num.multiply(b.den), a.den.multiply(b.num));
        }

        @Override
        public int compareTo(Frac b) {
            Frac a = this;
            return a.num.multiply(b.den).compareTo( b.num.multiply(a.den) ) ;
        }
    }

    public static class PDD {
        Frac first, second;

        PDD(Frac x, Frac y) {
            first = x;
            second = y;
        }
    }

    static ArrayList<PDD> spds;
    static Frac INF ;

    static Frac calcCol(PDD lft, PDD rgt) {
        return (rgt.first.sbs(lft.first)).div(lft.second.sbs(rgt.second));
    }

    static Frac colTim(PDD cur) {
        if(spds.size() == 0)
            return INF;
        if(spds.size() == 1) {
            Frac ans = calcCol(spds.get(0), cur);
            // System.out.print("ANS:     ");
            // System.out.print(ans.num);
            // System.out.print(" ");
            // System.out.println(ans.den);
            return ans;
        }
        int ini = 0, fin = spds.size() - 2;
        while(ini < fin) {
            int piv = (ini + fin) / 2;
            Frac x = calcCol(spds.get(piv), cur);
            Frac y = calcCol(spds.get(piv+1), cur);
            if(x.compareTo(y) == -1)
                fin = piv ;
            else
                ini = piv + 1;
        }
        Frac cvl = calcCol(spds.get(ini), cur);
        Frac lft = calcCol(spds.get(spds.size() - 1), cur);
        Frac ans = cvl.compareTo(lft) == -1? cvl : lft;
        // System.out.print("ANS:     ");
        // System.out.print(ans.num);
        // System.out.print(" ");
        // System.out.println(ans.den);
        return ans;
    }

    static void updSpds(PDD nov) {
        while(!spds.isEmpty() && spds.get(spds.size() - 1).second.compareTo(nov.second) != 1)
            spds.remove(spds.size() - 1);
        spds.add(nov);
        // for(PDD pr : spds) {
        //     System.out.print(pr.first.num);
        //     System.out.print(" ");
        //     System.out.print(pr.first.den);
        //     System.out.print("     ");
        //     System.out.print(pr.second.num);
        //     System.out.print(" ");
        //     System.out.println(pr.second.den);
        //     System.out.println("----------");
        // }
    }

    public static void main(String[] args) {
        INF = new Frac(BigInteger.valueOf((long) 1e9 + 1));
        spds = new ArrayList<>();
        MyScanner sc = new MyScanner();
        int N ;
        Frac ans = INF;

        N = sc.nextInt();
        for(int i=0; i < N; i++) {
            int a, b ;
            a = sc.nextInt();
            b = sc.nextInt();
            PDD cur = new PDD(new Frac(BigInteger.valueOf(a)), new Frac(BigInteger.valueOf(b)));
            if(b < 0) {
                Frac x = colTim(cur);
                ans = ans.compareTo(x) == 1? x : ans;
            }
            else
                updSpds(cur);
        }

        if(ans.compareTo(INF) == 0) {
            System.out.println(-1);
            return ;
        }

        if(ans.den.compareTo(BigInteger.ZERO) == -1) {
            ans.num = ans.num.negate();
            ans.den = ans.num.negate();
        }

        BigInteger g = ans.num.abs().gcd(ans.den);
        ans.num = ans.num.divide(g);
        ans.den = ans.den.divide(g);

        double num = ans.num.doubleValue();
        double den = ans.den.doubleValue();

        System.out.printf("%.20f\n", num / den);
        // System.out.println(ans.num);
        // System.out.println(ans.den);
    }
}
