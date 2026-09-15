#include <iostream>
#include "leetcode/Q3483.h"

int main(){
    Q3483::Solution* solution = new Q3483::Solution();

    vector<int> v = {6,0,0};
    
    std::cout << "total solutions : " << solution->totalNumbers(v) << "\n";

    delete solution;
    return 0;
}

// [1,2,3,4]
// 2 -> [1,3,4] = 3!
// 4 -> [1,2,3] = 3!
//total = 3 * 2 + 3 * 2 = 12

//[6,0,0]
// 0 -> [0,6] = 2! - 1
// 6 -> [0,0] = 2! / 2! = 1 - 1 


