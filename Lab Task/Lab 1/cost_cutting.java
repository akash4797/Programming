import java.util.Scanner;

class cost_cutting {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt(); // number of test cases
        scanner.nextLine(); // consume the newline character

        for (int i = 0; i < t; i++) {
            String[] input = scanner.nextLine().split(" ");
            int fi = Integer.parseInt(input[0]); // number of player
            int sc = Integer.parseInt(input[1]); // starting player
            int th = Integer.parseInt(input[2]); // number of passes

            int survived_one = findSurvied(fi, sc, th);

            System.out.println("Case " + (i + 1) + ": " + survived_one);

        }

        scanner.close();
    }

    static int findSurvied(int fi, int sc, int th) {

        if (fi > sc && fi > th) {
            if (sc > th) {
                return sc;
            } else {
                return th;
            }
        } else if (sc > fi && sc > th) {
            if (fi > th) {
                return fi;
            } else {
                return th;
            }
        } else {
            if (fi > sc) {
                return fi;
            } else {
                return sc;
            }
        }

    }
}
