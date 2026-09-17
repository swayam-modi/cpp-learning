#include <vector>
#include <functional>
#include <iostream>
#include <utility>

using std::size_t;
using std::vector;

template <typename T, typename Compare = std::less<T>>
class Heap
{
public:
    Heap() {}; // default constructor
    Heap(const vector<T> &v) : data(v)
    {
        heapify(); // call heapify for re-structor data in //~O(n)
    }

    size_t size() const
    {
        return data.size();
    }

    void printData() const
    {
        for (const T &val : data)
        {
            std::cout << val << "  ";
        }

        std::cout << "\n";
    }

    // returns top element
    T top() const
    {
        return data[0];
    }

    void push(T val)
    {
        data.push_back(val);
        heapifyUp();
    }

    // removes top element and return it
    T pop()
    {
        T topEle = top();
        swap(0, size() - 1);
        data.pop_back();
        heapifyDown();

        return topEle;
    }

    // returns boolean value for is empty or not
    bool isEmpty() const
    {
        return size() == 0;
    }

private:
    vector<T> data;
    Compare compare{}; // safe initalize for user definde type

    void heapify()
    {
        for (int i = size() / 2 - 1; i >= 0; i--)
        {
            heapifyDown(i);
        }
    }

    void heapifyDown(size_t i = 0)
    {
        while (i < size())
        {
            size_t leftChild = left(i);
            size_t rightChild = right(i);
            size_t currIdx = i;

            if (leftChild < size() && compare(data[leftChild], data[i]))
            {
                i = leftChild;
            }

            if (rightChild < size() && compare(data[rightChild], data[i]))
            {
                i = rightChild;
            }

            if (currIdx == i)
                break;

            swap(currIdx, i);
        }
    }

    void heapifyUp()
    {
        size_t idx = size() - 1;

        while (idx > 0)
        {

            size_t parentNode = parent(idx);

            if (parentNode >= 0 && compare(data[idx], data[parentNode]))
            {
                swap(idx, parentNode);
                idx = parentNode;
            }
            else
            {
                break;
            }
        }
    }

    size_t parent(const size_t &i) const
    {
        return (i - 1) / 2;
    }

    size_t left(const size_t &i) const
    {
        return i * 2 + 1;
    }

    size_t right(const size_t &i) const
    {
        return i * 2 + 2;
    }

    void swap(size_t a, size_t b)
    {
        std::swap(data[a], data[b]);
    }
};
