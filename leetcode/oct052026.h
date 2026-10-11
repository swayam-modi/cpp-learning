#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        vector<int> vct;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                vct.push_back(0);
            }

            else if (s[i] == ')')
            {
                int total = 0;
                while (!vct.empty() && vct.back() != 0)
                {
                    total += vct.back();
                    vct.pop_back();
                }

                vct.pop_back();
                vct.push_back(total == 0 ? 1 : total * 2);
            }
        }

        int total = 0;
        while (!vct.empty())
        {
            total += vct.back();
            vct.pop_back();
        }

        return total;
    }
};