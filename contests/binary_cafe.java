import java.util.Scanner;

public class binary_cafe {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt(); // number of test cases
        scanner.nextLine(); // consume the newline character

        for (int i = 0; i < t; i++) {
            String[] input = scanner.nextLine().split(" ");
            int n = Integer.parseInt(input[0]); // number of coins Toma is willing to spend
            int k = Integer.parseInt(input[1]);

            int ways = countWays(n, k);
            System.out.println(ways);
        }
        scanner.close();
    }

    private static int countWays(int n, int k) {
        int ways = (int) Math.pow(2, k) - 1;

        if (n < (int) Math.pow(2, k)) {
            ways = n + 1;
        }

        return ways;
    }
}
