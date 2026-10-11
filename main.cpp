#include "leetcode/Q2333.h"
#include <iostream>

int main()
{
    Solution s;
    vector<int> num1 = {10, 10, 10, 11, 5};
    vector<int> num2 = {1, 0, 6, 6, 1};

    std::cout << s.minSumSquareDiff(num1, num2, 11, 27) << '\n';
}