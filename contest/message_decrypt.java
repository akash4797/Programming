import java.util.Scanner;

public class message_decrypt {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt(); // number of test cases

        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt(); // length of the encrypted message
            String s = scanner.next(); // encrypted message

            String decryptedString = decryptMessage(s);
            System.out.println(decryptedString);
        }
        scanner.close();
    }

    private static String decryptMessage(String encryptedMessage) {
        StringBuilder decryptedString = new StringBuilder();
        char currentChar = 'a';
        int index = 0;
        for (int i = 0; i < encryptedMessage.length(); i++) {
            if (i == index) {
                currentChar = encryptedMessage.charAt(i);
            } else {
                if (encryptedMessage.charAt(i) == currentChar) {
                    decryptedString.append(encryptedMessage.charAt(i));
                    index = i + 1;
                }
            }
        }

        return decryptedString.toString();
    }
}
