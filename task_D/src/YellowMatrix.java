/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import static java.lang.Math.max;
import java.util.Scanner;
import java.util.Stack;

/**
 *
 * @author Админ
 */
public class YellowMatrix {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        int n, m;
        int[][] matrix;
        try ( // TODO code application logic here
                Scanner sc = new Scanner(System.in)) {
            n = sc.nextInt();
            m = sc.nextInt();
            matrix = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = sc.nextInt();
                }
            }

        }
        int res = 0;
        int[] d = new int[m], d1 = new int[m], d2 = new int[m];
        Stack<Integer> stack = new Stack();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 1) {
                    d[j] = i;
                }
            }
            while (!stack.empty()) {
                stack.pop();
            }
            for (int j = 0; j < m; ++j) {
                while (!stack.empty() && d[stack.peek()] <= d[j]) {
                    stack.pop();
                }
                d1[j] = stack.empty() ? -1 : stack.peek();
                stack.push(j);
            }
            while (!stack.empty()) {
                stack.pop();
            }
            for (int j = m - 1; j >= 0; --j) {
                while (!stack.empty() && d[stack.peek()] <= d[j]) {
                    stack.pop();
                }
                d2[j] = stack.empty() ? m : stack.peek();
                stack.push(j);
            }
            for (int j = 0; j < m; ++j) {
                res = max(res, (i - d[j]) * (d2[j] - d1[j] - 1));
            }

        }
        System.out.println(res);

    }

}
