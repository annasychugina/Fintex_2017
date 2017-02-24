/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Админ
 */
public class Chess {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        try {
            final int n = 8, m = 8;
            final char rook = 'R';
            final char elephant = 'B';
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String line;
            int l = 0;
            char[][] matrix = new char[n][m];
            while ((line = reader.readLine()) != null) {

                matrix[l++] = line.toCharArray();

            }
            Set<Integer> brokenFields = new HashSet();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == rook) {

                        for (int k = 0; k < 8; k++) {
                            brokenFields.add(k * 8 + j);
                            brokenFields.add(i * 8 + k);
                        }

                    } else if (matrix[i][j] == elephant) {

                        int c0 = j - i, c1 = j + i;
                        for (int i1 = 0; i1 < n; i1++) {
                            if (c0 >= 0 && c0 < n) {
                                brokenFields.add(i1 * 8 + c0++);
                            }
                            if (c1 < n && c1 >= 0) {

                                brokenFields.add(i1 * 8 + c1--);
                            }

                        }

                    }
                }
            }
            System.out.print(n * m - brokenFields.size());

        } catch (IOException ex) {
            Logger.getLogger(Chess.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}
