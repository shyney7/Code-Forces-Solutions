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