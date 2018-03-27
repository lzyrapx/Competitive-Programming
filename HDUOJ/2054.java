import java.math.BigDecimal;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            BigDecimal num1=cin.nextBigDecimal();
            BigDecimal num2=cin.nextBigDecimal();
            String str1=num1.stripTrailingZeros().toPlainString();
            String str2=num2.stripTrailingZeros().toPlainString();
            if(str1.equals(str2))
                System.out.println("YES");
            else System.out.println("NO");
        }
    }
}