#include <vector>
using std::vector;

class Solution
{
public:
    bool hasValidPath(vector<vector<char>> &grid)
    {
        return helper(grid, 0, 0, 0);
    }

private:
    bool helper(vector<vector<char>> &grid, int r, int c, int sum)
    {
        if (!isValid(grid, r, c))
        {
            return false;
        }

        sum = grid[r][c] == '(' ? sum + 1 : sum - 1;

        if (r == grid.size() - 1 && c == grid[0].size() - 1 && sum == 0)
        {
            return true;
        }

        return helper(grid, r + 1, c, sum) || helper(grid, r, c + 1, sum);
    }

    bool isValid(vector<vector<char>> &grid, int r, int c)
    {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
};