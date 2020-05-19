/* Gardener Alexey teaches competitive programming to high school students. To congratulate Alexey on the Teacher's Day, 
the students have gifted him a collection of wooden sticks, where every stick has an integer length. Now Alexey wants to grow a tree from them.

The tree looks like a polyline on the plane, consisting of all sticks. The polyline starts at the point (0,0). 
While constructing the polyline, Alexey will attach sticks to it one by one in arbitrary order. 
Each stick must be either vertical or horizontal (that is, parallel to OX or OY axis). 
It is not allowed for two consecutive sticks to be aligned simultaneously horizontally or simultaneously vertically. See the images below for clarification.

Alexey wants to make a polyline in such a way that its end is as far as possible from (0,0). Please help him to grow the tree this way.

Note that the polyline defining the form of the tree may have self-intersections and self-touches, but it can be proved that the optimal answer does not contain any self-intersections or self-touches.

Input
The first line contains an integer n (1≤n≤100000) — the number of sticks Alexey got as a present.

The second line contains n integers a1,…,an (1≤ai≤10000) — the lengths of the sticks.

Output
Print one integer — the square of the largest possible distance from (0,0) to the tree end. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
int main() {

    int numSticks = 0;
    std::cin >> numSticks;

    std::vector<int> lenSticks;
    lenSticks.reserve(200);
    int input = 0;
    while(std::cin >> input) {
        lenSticks.push_back(input);
    }
    std::sort(lenSticks.begin(), lenSticks.end());
    int vecsize1 = std::floor(lenSticks.size() / 2);
    unsigned long long ycor = 0;

    for (int i = 0; i < vecsize1; ++i) {
        ycor += lenSticks[i];
    }
    int vecsize2 = lenSticks.size() - vecsize1;
    if(lenSticks.size() % 2) vecsize2 -= 1;
    unsigned long long xcor = 0;
    for (int i = vecsize2; i < lenSticks.size(); ++i) {
        xcor += lenSticks[i];
    }
    std::cout << (xcor*xcor) + (ycor*ycor);

    return 0;
}