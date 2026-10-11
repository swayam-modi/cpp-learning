#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using std::move;
using std::reverse;
using std::string;
using std::unordered_map;
using std::vector;

// You are given a string s that contains some bracket pairs, with each pair containing a non-empty key.

// For example, in the string "(name)is(age)yearsold", there are two bracket pairs that contain the keys "name" and "age".
// You know the values of a wide range of keys. This is represented by a 2D string array knowledge where each knowledge[i] = [keyi, valuei] indicates that key keyi has a value of valuei.

// You are tasked to evaluate all of the bracket pairs. When you evaluate a bracket pair that contains some key keyi, you will:

// Replace keyi and the bracket pair with the key's corresponding valuei.
// If you do not know the value of the key, you will replace keyi and the bracket pair with a question mark "?" (without the quotation marks).
// Each key will appear at most once in your knowledge. There will not be any nested brackets in s.

// Return the resulting string after evaluating all of the bracket pairs.

class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)

    {
        unordered_map<string, string> map(knowledge.size());
        vector<string> dec;
        string res;
        size_t n = s.size();

        for (vector<string> &data : knowledge)
        {
            map.insert({data[0], data[1]});
        }

        for (size_t i = 0; i < n; i++)
        {
            if (s[i] == ')')
            {
                string key;
                while (!dec.empty())
                {
                    string val = dec.back();
                    dec.pop_back();

                    if (val == "(")
                    {
                        reverse(key.begin(), key.end());
                        const string &val = map.count(key) > 0 ? map[key] : "?";
                        dec.push_back(val);
                        break;
                    }

                    key += val;
                }
                continue;
            }
        }

        for (string &val : dec)
        {
            res += val;
        }

        return res;
    }
};