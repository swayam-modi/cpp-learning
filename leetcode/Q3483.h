# include <vector>
using std::vector;

//{0,1,2,2}

namespace Q3483{
    class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        const int& totalDigits = digits.size();
        int result = 0;
        int counts[10] = {0};

        for(int& digit : digits){
            counts[digit]++;
        }
        
        const int& totalFact = factorial(totalDigits - 1);
        const int& zeroFact = counts[0] > 0 ? factorial(counts[0]) : 0;

        for(int i = 0; i < 10; i+=2){
            if(counts[i] > 0){
            const int& currZeroFact = i == 0 ? (counts[0] <= 1 ? 0 : zeroFact/counts[0]) : zeroFact;
            const int& repeted = repetedFactorial(i,counts);
            result += totalFact / repetedFactorial(i,counts) - currZeroFact;
        }
        }

        return result < 0 ? 0 : result;
    }

private : 
    int factorial(int n){
        int res = 1;
        for(int i = n; i > 1; i--){
            res *= i;
        }

        return res;
    }

    int repetedFactorial(int& curr,int* arr){
        int res = 1;
        for(int i = 0; i < 10; i++){
            if(i == curr) res *= factorial(arr[i] - 1);
            else res *= factorial(arr[i]);
        }

        return res;
    }
};
}