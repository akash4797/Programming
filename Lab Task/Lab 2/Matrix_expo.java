public class Matrix_expo {
    static final int N = 100;
    static final int mod = 1000000007;

    static class Matrix {
        int row, col;
        long[][] m;

        Matrix(int row_num, int col_num) {
            row = row_num;
            col = col_num;

            m = new long[row][col];
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    m[i][j] = 0;
                }
            }
        }

        Matrix multiply(Matrix B) {
            Matrix product = new Matrix(row, B.col);

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < B.col; j++) {
                    for (int k = 0; k < col; k++) {
                        product.m[i][j] += m[i][k] * B.m[k][j];
                        product.m[i][j] %= mod;
                    }
                }
            }

            return product;
        }
    }

    public static void main(String[] args) {

    }
}