#include <vector>
#include <functional>

using std::vector;

template <typename T, typename Compare = std::less<T>>
class Heap
{
public:
    Heap() = default;

private:
    int size = 10;
    vector<T> data = vector<T>(10);
};