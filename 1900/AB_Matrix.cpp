/*You are given four positive integers n, m, a, b (1≤b≤n≤50; 1≤a≤m≤50).
Find any such rectangular matrix of size n×m that satisfies all of the following conditions:

- each row of the matrix contains exactly a ones;
- each column of the matrix contains exactly b ones;
- all other elements are zeros. 

If the desired matrix does not exist, indicate this.

For example, for n=3, m=6, a=2, b=1, there exists a matrix satisfying the conditions above:
|010001|
|100100|
|001010|

Input:
The first line contains an integer t(1≤ t ≤1000) — the number of test cases. 
Then t test cases follow.
Each test case is described by four positive integers n, m, a, b (1≤b≤n≤50; 1≤a≤m≤50),
where n and m are the sizes of the matrix, and a and b are the number of ones for rows and columns, respectively.

Output:
For each test case print:
- "YES" (without quotes) and the required matrix (if there are several answers, print any) if it exists, or
- "NO" (without quotes) if it does not exist. 

To print the matrix n×m, print n rows, each of which consists of m numbers 0 or 1 describing a row of the matrix.
Numbers must be printed without spaces.
*/

#include <iostream>
#include <vector>


int main() {

    int test;
    std::cin >> test;

    for(int i(0); i < test; ++i) {
        int rows, cols, a, b;
        std::cin >> rows >> cols >> a >> b;

        if(rows * a != cols * b) {
            std::cout << "NO\n";
            continue;
        }
        std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));

        int d(0);

        for(d = 1; d < cols; ++d) {
            if(d * rows % cols == 0) {
                break;
            }
        }
        for(int i(0), pld = 0; i < rows; ++i, pld += d) {
            for(int j(0); j < a; ++j) {
                matrix[i][(j+pld) % cols] = 1; 
            }
        }

        std::cout << "YES\n";

        for(int i(0); i < rows; ++i) {
            for(int j(0); j < cols; ++j) {
                std::cout << matrix[i][j];
            }
            std::cout << '\n';
        }
    }
    return 0;
}