#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <set>
#include <iostream>

/*
  Basic Trie Implementation

  unordered map with char as key and array of char as value

  let L = length of input word/prefix
  has_prefix(std::string prefix); - O(L) time complexity
  has_word(std::string word); - O(L) time complexity
  add_word(std::string); - O(L) time complexity
  remove_word(std::string); - O(L) time complexity

*/

struct TrieNode
{
    bool is_word{false};
    std::unordered_map<char, std::shared_ptr<TrieNode>> children;
    char cur_char{};
    int prefix_count{1};

    TrieNode();

    TrieNode(char letter, bool is_word_val);
};

class Trie
{
private:
    std::shared_ptr<TrieNode> root;
    std::unique_ptr<std::set<std::string>> words;

public:
    explicit Trie(const std::vector<std::string> passed_in_words);

    bool contains_word(const std::string &word);

    bool has_prefix(const std::string &word);

    void add_word(const std::string &word);

    void add_words_from_txt_file(const std::string &file_path);

    void remove_word(const std::string &word);

    std::set<std::string> get_words();
};
