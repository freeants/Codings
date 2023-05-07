
/*
    File:   e1001.java - Exponentiation
    Copyright:  © 2020-2025 freeants. All rights reserved.
*/
import java.util.*;
import java.math.BigDecimal;

class e1001 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            BigDecimal R = sc.nextBigDecimal();
            int n = sc.nextInt();
            R = R.pow(n).stripTrailingZeros();
            String str = R.toPlainString();
            if (str.charAt(0) == '0')
                str = str.substring(1);
            System.out.println(str);
        }
        sc.close();
    }
}