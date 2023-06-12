import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class One_Handed_Typist {
    private static final String DVORAK_LAYOUT = "`123qjlmfp/[]456.orsuyb;-789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+&*(AEHTDCK_)ZX<INWVG*";
    private static final String QWERTY_LAYOUT = "`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}ASDFGHJKL*:ZXCVBNM<>?";

    public static void main(String[] args) throws IOException {
        Map<Character, Character> layoutMap = createLayoutMap();
        File file = new File(
                "/Users/shariarakash/Documents/Programming/Lab Task/Lab 1/one_handed_typist.txt");

        BufferedReader br = new BufferedReader(new FileReader(file));

        String st;

        while ((st = br.readLine()) != null) {
            for (int i = 0; i < st.length(); i++) {
                char convertedChar = layoutMap.getOrDefault(st.charAt(i), st.charAt(i));

                System.out.print(convertedChar);
            }
            System.out.println();
        }

        br.close();
    }

    private static Map<Character, Character> createLayoutMap() {
        Map<Character, Character> layoutMap = new HashMap<>();
        for (int i = 0; i < DVORAK_LAYOUT.length(); i++) {
            char dvorakChar = DVORAK_LAYOUT.charAt(i);
            char qwertyChar = QWERTY_LAYOUT.charAt(i);

            layoutMap.put(qwertyChar, dvorakChar);
        }
        return layoutMap;
    }
}
