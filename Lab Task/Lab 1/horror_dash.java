import java.util.Scanner;

public class horror_dash {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt(); // number of test cases
        scanner.nextLine(); // consume the newline character

        for (int i = 0; i < t; i++) {
            String[] input = scanner.nextLine().split(" ");
            int n = Integer.parseInt(input[0]);
            int[] creature_speeds = new int[input.length - 1];
            for (int j = 1; j < input.length; j++) {
                creature_speeds[j - 1] = Integer.parseInt(input[j]);
            }
            int ideal_speed = getIdealSpeed(creature_speeds);
            System.out.println("Case " + (i + 1) + ": " + ideal_speed);
        }

        scanner.close();
    }

    static int getIdealSpeed(int[] arr) {
        int max = arr[0];
        for (int i = 0; i < arr.length; i++) {
            if (max < arr[i]) {
                max = arr[i];
            }
        }
        return max;
    }
}
