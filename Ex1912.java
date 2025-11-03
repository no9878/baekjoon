import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // 1 <= n <= 100000
        ArrayList<Integer> Array = new ArrayList<>(n);
        int Sum =0;
        for (int i = 0; i < n; i++) {
            int input = scanner.nextInt();
            Array.add(input);
            if (i==0)
            Sum = Array.get(i);
            else if (input>Sum)
                Sum = input;
        }

        int tmp = 0;
        for (int i = 0; i < Array.size(); i++) {
            tmp += Array.get(i);
            if (tmp>Sum)
                Sum = tmp;
            else if (tmp < 0)
                tmp =0;
            }

        System.out.println(Sum);
    }
}
