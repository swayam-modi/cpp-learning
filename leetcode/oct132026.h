#include <vector>
#define MOD 1000000007

using std::vector;

class Solution
{
public:
    int maxSum(vector<int> &nums, int k)
    {
        int bit_count[32]{};
        unsigned long long square_sum = 0;

        // count all the total number of bits available in nums
        for (int num : nums)
        {
            for (int i = 0; i < 32 && num > 0; i++)
            {
                if ((num & 1) == 1)
                {
                    bit_count[i]++;
                }

                num >>= 1;
            }
        }

        // create number bit by bit using available bits
        for (int i = 0; i < k; i++)
        {
            int curr = 0;
            for (int i = 0; i < 32; i++)
            {
                if (bit_count[i] > 0)
                {
                    curr |= (1 << i);
                    bit_count[i]--;
                }
            }
            square_sum += curr * curr;
        }

        return (int)(square_sum % MOD);
    }
};