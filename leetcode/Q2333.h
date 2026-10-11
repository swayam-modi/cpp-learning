#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include <algorithm>
#include <iterator> // For prev
#include <map>

using std::abs;
using std::distance;
using std::greater;
using std::prev;
using std::sort;
using std::upper_bound;
using std::vector;

class Solution
{
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        const int n = nums1.size();
        long long k = k1 + k2;
        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back(abs(nums1[i] - nums2[i]));
        }

        sort(v.begin(), v.end(), [](int a, int b)
             { return a > b; });

        long long computed_val = v[0];
        int i = 0;

        while (k > 0)
        {
            auto it = upper_bound(v.begin() + i, v.end(), computed_val, greater<int>());
            i = distance(v.begin(), it);

            if (i >= n)
            {
                break;
            }

            long long diff = i * (computed_val - v[i]);

            if (k >= diff)
            {
                k -= diff;
                computed_val = v[i];
            }
            else
            {
                break;
            }
        }

        while (computed_val > 0 && k > 0 && k >= i)
        {
            computed_val--;
            k -= i;
        }

        long long a = computed_val > 0
                          ? k * (computed_val - 1) * (computed_val - 1)
                          : 0;

        long long b = (i - k) * computed_val * computed_val;
        long long c = 0;

        while (i < n)
        {
            c += 1LL * v[i] * v[i];
            i++;
        }

        return a + b + c;
    }
};