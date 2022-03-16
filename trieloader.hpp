#pragma once

#include "trienode.hpp"

/**
 * @brief The TrieLoader class
 * Klasa pozwalajaca wczytać z pliku bazę słów dopuszczonych w grach
 */
class TrieLoader
{
public:
    //constant pointer to a constant character + reference
    /**
     * @brief load_from_file Funckja pozwalajaca wczytać dane z pliku
     * @param file_name nazwa pliku
     * @return wskaźnik na korzeń drzewa Trie
     */
    static TrieNode load_from_file(const char * const & file_name);
};

