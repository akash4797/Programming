import java.util.Scanner;

public class homework_checker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int correctCount = 0;

        while (scanner.hasNextLine()) {
            String line = scanner.nextLine().trim();

            if (line.isEmpty()) {
                break;
            }

            String[] parts = line.split("[+=-]");
            int a = Integer.parseInt(parts[0]);
            int b = Integer.parseInt(parts[1]);
            int c = line.contains("?") ? -1 : Integer.parseInt(parts[2]);

            char operator = line.contains("+") ? '+' : '-';

            if ((operator == '+' && a + b == c) || (operator == '-' && a - b == c)) {
                correctCount++;
            }
        }

        System.out.println(correctCount);
        scanner.close();
    }
}