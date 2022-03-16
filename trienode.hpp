#pragma once

#include <memory>

/**
 * @brief The TrieNode class
 * Klasa reprezentująca element drzewa Trie
 */
class TrieNode
{
private:
    static const size_t letters_count = 36; /// zmienna reprezentujaca ilość znaków (35 liter + '_')
public :
    /**
     * @brief letter_to_index Funkcja zwracajaca indeks danej litery
     * @param letter litera
     * @return indeks
     */
    static size_t letter_to_index(const wchar_t & letter);

    /**
     * @brief index_to_letter Funckja zwracająca literę na podstawie indeksu
     * @param index indeks litery
     * @return litera
     */
    static wchar_t index_to_letter(const size_t & index);

private:
    bool is_terminal; ///zmienna oznaczająca, czy litera jest ostatnią w słowie
    std::unique_ptr<TrieNode> children[letters_count]; ///wskaźnik na dzieci

public:
    /**
     * @brief TrieNode Konstruktor klasy
     */
    TrieNode();

public:
    /**
     * @brief get_is_terminal
     * Funckja pozwalajaca uzyskać informację o tym, czy lisć przechowuje ostatnią literę słowa
     * @return wartość prawda/fałsz, informująca o tym, czy jets to ostatnia litera
     */
    const bool & get_is_terminal() const { return is_terminal; }

    /**
     * @brief get_letters_count
     * Funkcja zwracają ilość liter
     * @return ilosć liter
     */
    static size_t get_letters_count() {return letters_count;}

public:
    /**
     * @brief get_next Funkcja pozwalajaca uzyskać referencje na nasteony element
     * @param letter
     * @return referencja na następny element
     */
    TrieNode & get_next(const wchar_t & letter);

    /**
     * @brief get_next Funckja pozwalajaca uzyskać stały wskaxnik na następny element
     * @param letter
     * @return stały wskaźnik na następny element
     */
    const TrieNode * get_next(const wchar_t & letter) const;

    /**
     * @brief set_terminal Funkcja pozwalająca zaznaczyć, że dana lietra jets ostatnią słowa
     */
    void set_terminal();

public:
    /**
     * @brief add Funkcja pozwalajaca dodać słowo do drzewa
     * @param text łancuch znakw, który ma zostać dodany do drzewa
     */
    void add(const wchar_t * const & text);

    /**
     * @brief exists Funckja sprawdzająca, czy dane słowo istnieje już w drzewie
     * @param text dane słowo
     * @return wartość prawda/fałsz, informujaca tym czy słowo istnieje w drzewie
     */
    bool exists(const wchar_t * const & text) const;

    /**
     * @brief has_chlidren
     * Funckcja sprawdzająca cyz dany element ma dzieci
     * @return wartość prawda/fałsz informujaca czy dany element ma dzieci
     */
    bool has_chlidren() const;
};
