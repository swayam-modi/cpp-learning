#include <iostream>

int main()
{
    int t;
    std::cin >> t;

    while (t > 0)
    {
        t--;
        int a, b, x, y;

        std::cin >> a >> b >> x >> y;

        if (a == b)
        {
            std::cout << 0 << '\n';
            continue;
        }

        if (a > b)
        {
            std::cout << ((a ^ 1) == b ? y : -1) << '\n';
            continue;
        }

        int diff = b - a;

        if (x <= y || diff == 1)
            std::cout << (b - a) * x << '\n';

        else if ((diff & 1) == 0)
            std::cout << ((diff >> 1) * (x + y)) << '\n';

        else
            std::cout << (((diff >> 1) + 1) * x + (diff >> 1) * y) << '\n';
    }

    return 0;
}