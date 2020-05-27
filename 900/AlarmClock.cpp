#include <iostream>
#include <cmath>

int main() {

    int t(0);
    std::cin >> t;

    for(int i(0); i < t; ++i) {
        unsigned int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        if(b >= a) {
            std::cout << b << '\n';
            continue;
        }
        if(c <= d) {
            std::cout << -1 << '\n';
            continue;
        }
        unsigned int rest = std::ceil((a-b)/(c-d));
        std::cout << b + (rest * c) << '\n';
    }

    return 0;
}