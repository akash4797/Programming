import java.util.Arrays;
import java.util.Scanner;

public class minesweeper {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int count = 0;

        while (true) {
            String[] input = scanner.nextLine().split(" ");
            int n = Integer.parseInt(input[0]);
            int m = Integer.parseInt(input[1]);

            if (m == 0 && n == 0)
                break;

            String[][] row_col = new String[n][m];
            for (String[] row : row_col) {
                Arrays.fill(row, "0");
            }

            for (int i = 0; i < n; i++) {
                String line = scanner.nextLine();
                for (int j = 0; j < m; j++) {
                    if (line.charAt(j) == '*') {
                        row_col[i][j] = "*";

                        // Iterate over the neighboring cells
                        for (int dx = -1; dx <= 1; dx++) {
                            for (int dy = -1; dy <= 1; dy++) {
                                int nx = i + dx;
                                int ny = j + dy;

                                // Check if the neighboring cell is within bounds
                                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                                    if (row_col[nx][ny] != "*") {
                                        row_col[nx][ny] = Integer.toString(Integer.parseInt(row_col[nx][ny]) + 1);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            System.out.println("Field #" + (count + 1) + ":");

            for (String[] row : row_col) {
                for (String result : row) {
                    System.out.print(result);
                }
                System.out.println();
            }

            System.out.println();
            count++;
        }
        scanner.close();
    }
}
