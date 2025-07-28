import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static long N, reverseN = 0;


    public static void main(String[] args) throws IOException {

        String str = br.readLine();
        N = Long.parseLong(str);

        if (N == 1) {
            System.out.println("no");
            return;
        }

        boolean flag = false;
        for (int i = 2; i <= Math.sqrt(N); i++) {
            if (N % i == 0) {
                flag = true;
                break;
            }
        }

        if (flag) {
            System.out.println("no");
            return;
        }

        int len = str.length();
        for (int i = 0; i < len; i++) {
            long now = str.charAt(i) - '0';
            if (now == 3 || now == 4 || now == 7){
                flag = true;
                break;
            }

            if (now == 6) now = 9;
            else if (now == 9) now = 6;

            reverseN += (long)Math.pow(10, i) * now;
        }

        if (flag) {
            System.out.println("no");
            return;
        }

        for (int i = 2; i <= Math.sqrt(reverseN); i++) {
            if (reverseN % i == 0) {
                flag = true;
                break;
            }
        }

        if (flag) {
            System.out.println("no");
            return;
        }

        System.out.println("yes");
    }
}