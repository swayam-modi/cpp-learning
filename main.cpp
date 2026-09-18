#include "huffman/code.h"

int main()
{

    std::vector<uint8_t> data = {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    Huffman *huffman = new Huffman(data);
    const uint64_t size_bytes = huffman->sizeofTree();

    std::cout << "provided data size : " << data.size() * 8 << "b\n";
    std::cout << "compressed data size : " << huffman->getCompressedBits() << "b\n";
    std::cout << "height of tree : " << huffman->heightOfTree() << "\n";

    std::cout << "size of tree in bytes : " << size_bytes << "B\n";
    std::cout << "size of tree in bits : " << size_bytes * 8 << "b\n";

    const vector<uint8_t> compressed = huffman->getCompressedData();

    for (const uint8_t &c : compressed)
    {
        std::cout << static_cast<int>(c) << ":" << std::bitset<8>(c) << "\n";
    }

    delete huffman;
}