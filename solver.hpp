#pragma once

#include <list>

#include "trienode.hpp"
#include "bar.hpp"
#include "list.hpp"

/**
 * @brief The Solver class
 * Klasa pozwalająca na wyszukiwanie słów z liter
 */
class Solver
{
public:

    using Words = List<std::wstring>;
    using StackArray = std::array<wchar_t, Bar::capacity>;
    using Stack = std::pair<StackArray, size_t>;

public:
    /**
     * @brief solve
     * Konstruktor Klasy Solver
     * @param node referencja na liść drzewa Trie
     * @param bar tabliczka liter
     * @return słowa, które można uzyskać z danej tabliczki
     */
    static Words solve(const TrieNode & node, const Bar & bar);
    static void solve(
        const TrieNode & node,
        const Bar & bar,
        const Stack & stack,
        Words & words
    );

};

