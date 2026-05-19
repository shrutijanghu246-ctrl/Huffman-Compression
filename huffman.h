#pragma once
#include <string>
#include <unordered_map>
#include <queue>
#include <memory>

struct HuffmanNode{
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    //leaf node (actual character)
    HuffmanNode(char c, int f)
        : ch(c), freq(f), left(nullptr), right(nullptr){}

    //Internal node (just a merger, no character)
    HuffmanNode(int f, HuffmanNode* l, HuffmanNode* r)
        : ch('\0'), freq(f), left(l), right(r){}

    bool isLeaf() const {
        return !left && !right;
    }
};

struct NodeCmp {
    bool operator()(HuffmanNode* a, HuffmanNode* b){
        return a->freq > b->freq;
    }
};

// function declarations go here — outside everything
std::unordered_map<char, int> buildFreqTable(const std::string& text);
HuffmanNode* buildTree(std::unordered_map<char, int>& freq);
void buildCodes(HuffmanNode* node, std::string code, std::unordered_map<char, std::string>& codes);
void compress(const std::string& inputPath, const std::string& outputPath);
void decompress(const std::string& inputPath, const std::string& outputPath, HuffmanNode* root);