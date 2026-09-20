#include "huffman/code.h"
#include <fstream>
#include <bitset>

std::vector<uint8_t> readFile(const std::string &path)
{
    std::ifstream file(path, std::ios::binary);
    return std::vector<uint8_t>((std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>());
}

int main()
{
    std::string text;
    std::vector<uint8_t> data = {1, 2, 3, 1, 2, 3};

    auto compressed = Huffman::compress(data);
    for (auto &val : compressed.serializedTree)
    {
        std::cout << std::bitset<8>(val) << " - " << (int)val << " ";
    }

    vector<uint8_t> decompressed = Huffman::decompress(compressed.compressed, compressed.serializedTree, compressed.originalDataSize);

    std::cout << "data size : " << data.size() << "\n";
    std::cout << "after compressed and decomressed data size : " << decompressed.size() << "\n";

    for (size_t i = 0; i < decompressed.size(); i++)
    {
        std::cout << (int)data[i] << " - " << (int)decompressed[i] << ", ";
    }
    return 0;
}