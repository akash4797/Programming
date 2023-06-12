import java.util.Scanner;

class bafana_bafana {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt(); // number of test cases
        scanner.nextLine(); // consume the newline character

        for (int i = 0; i < t; i++) {
            String[] input = scanner.nextLine().split(" ");
            int n = Integer.parseInt(input[0]); // number of player
            int k = Integer.parseInt(input[1]); // starting player
            int p = Integer.parseInt(input[2]); // number of passes
            int lastPerson = countLast(n, k, p);
            System.out.println("Case " + (i + 1) + ": " + lastPerson);

        }
        scanner.close();
        System.exit(0);
    }

    static int countLast(int n, int k, int p) {

        int l = k;

        for (int i = 0; i < p; i++) {
            if (l == n) {
                l = 1;
            } else {
                l = l + 1;
            }
        }
        return l;
    }
}
