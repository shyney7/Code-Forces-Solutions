/* One day Kefa found n baloons. For convenience, we denote color of i-th baloon as s i — lowercase letter of the Latin alphabet. 
Also Kefa has k friends. Friend will be upset, If he get two baloons of the same color. Kefa want to give out all baloons to his friends. 
Help Kefa to find out, can he give out all his baloons, such that no one of his friens will be upset — print «YES», if he can, and «NO», otherwise. 
Note, that Kefa's friend will not upset, if he doesn't get baloons at all.

Input:
The first line contains two integers n and k (1 ≤ n, k ≤ 100) — the number of baloons and friends.
Next line contains string s — colors of baloons.

Output:
Answer to the task — «YES» or «NO» in a single line.
You can choose the case (lower or upper) for each letter arbitrary. */

#include <iostream>
#include <string>
#include <algorithm>

int main() {

    int numBaloons = 0, numFriends = 0;
    std::cin >> numBaloons;
    std::cin >> numFriends;
    std::string colors;
    colors.reserve(numBaloons);
    std::cin >> colors;
    std::string cpy_colors = colors;
    for(std::string::size_type i = 0; i < cpy_colors.size(); ++i) {
        std::string::size_type j = i + 1;
        while(j < cpy_colors.size()) {
            if(cpy_colors[i] == cpy_colors[j]) {
                cpy_colors.erase(j, 1);
            }
            else {
                ++j;
            }
        }
    }

    for(int i = 0; i < cpy_colors.size(); ++i) {
        std::ptrdiff_t n = std::count(colors.begin(), colors.end(), cpy_colors[i]);
        if(n > numFriends) {
            std::cout << "NO";
            return 0;
        }
    }
    std::cout << "YES";

    return 0;
}