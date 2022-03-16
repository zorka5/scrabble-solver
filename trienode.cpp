#include "trienode.hpp"
#include <iostream>
#include <stdexcept>

size_t TrieNode::letter_to_index(const wchar_t & letter) {
    switch(letter) {
        case L'a': return 0;
        case L'ą': return 1;
        case L'b': return 2;
        case L'c': return 3;
        case L'ć': return 4;
        case L'd': return 5;
        case L'e': return 6;
        case L'ę': return 7;
        case L'f': return 8;
        case L'g': return 9;
        case L'h': return 10;
        case L'i': return 11;
        case L'j': return 12;
        case L'k': return 13;
        case L'l': return 14;
        case L'ł': return 15;
        case L'm': return 16;
        case L'n': return 17;
        case L'ń': return 18;
        case L'o': return 19;
        case L'ó': return 20;
        case L'p': return 21;
        case L'q': return 22;
        case L'r': return 23;
        case L's': return 24;
        case L'ś': return 25;
        case L't': return 26;
        case L'u': return 27;
        case L'v': return 28;
        case L'w': return 29;
        case L'x': return 30;
        case L'y': return 31;
        case L'z': return 32;
        case L'ź': return 33;
        case L'ż': return 34;
        case L'_': return 35;

        default:
            throw std::out_of_range("letter_to_index out of range");
    }
}
wchar_t TrieNode::index_to_letter(const size_t & index) {
    switch(index) {
        case 0: return L'a';
        case 1: return L'ą';
        case 2: return L'b';
        case 3: return L'c';
        case 4: return L'ć';
        case 5: return L'd';
        case 6: return L'e';
        case 7: return L'ę';
        case 8: return L'f';
        case 9: return L'g';
        case 10: return L'h';
        case 11: return L'i';
        case 12: return L'j';
        case 13: return L'k';
        case 14: return L'l';
        case 15: return L'ł';
        case 16: return L'm';
        case 17: return L'n';
        case 18: return L'ń';
        case 19: return L'o';
        case 20: return L'ó';
        case 21: return L'p';
        case 22: return L'q';
        case 23: return L'r';
        case 24: return L's';
        case 25: return L'ś';
        case 26: return L't';
        case 27: return L'u';
        case 28: return L'v';
        case 29: return L'w';
        case 30: return L'x';
        case 31: return L'y';
        case 32: return L'z';
        case 33: return L'ź';
        case 34: return L'ż';
        case 35: return L'_';

        default:
            throw std::out_of_range("letter_to_index out of range");
    }
}

TrieNode::TrieNode():
    is_terminal(false)
{}

TrieNode & TrieNode::get_next(const wchar_t & letter) {
    const size_t index = letter_to_index(letter);
    std::unique_ptr<TrieNode> & next_node = children[index];
    if (!next_node) {
        next_node.reset(new TrieNode);
    }
    return *next_node;
}
const TrieNode * TrieNode::get_next(const wchar_t & letter) const {
    const size_t index = letter_to_index(letter);
    const std::unique_ptr<TrieNode> & next_node = children[index];
    return next_node.get();
}
void TrieNode::set_terminal() {
    is_terminal = true;
}

void TrieNode::add(const wchar_t * const & text) {
    if (*text == 0) {
        set_terminal();
    } else {
        get_next(*text).add(text + 1);
    }
}
bool TrieNode::exists(const wchar_t * const & text) const {
    if (*text == 0) {
        return is_terminal;
    } else {
        const TrieNode * next = get_next(*text);
        if (next == nullptr) return false;
        return next->exists(text + 1);
    }
}

bool TrieNode::has_chlidren() const
{
    for(size_t i = 0; i < letters_count; ++i)
    {
        if(children[i])
        {
            return true;
        }
    }
    return false;
}
