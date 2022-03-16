#pragma once

#include <cstdint>
#include <utility>
#include <array>
#include <optional>
#include <bitset>

/**
 * @brief The Bar class Klasa reprezentująca "tabliczkę" w grze Scrabble
 */
class Bar
{
public:
    static const size_t capacity = 8; /**< Stała reprezentująca pojemność tabliczki. Zgodnie z zasadami gry Scrabble - 8 znaków */

private:
    using Letters = std::array<wchar_t, capacity>;
    using LettersMask = std::bitset<capacity>;

private:
    Letters letters; /**< Tablica przechowująca litery znajdujące sie w tabliczce */
    LettersMask letters_mask; /**< bitset do przechowywania stanu wykorzystania liter */

private:
    Bar(const Letters & letters, const LettersMask & letters_mask);

public:
    Bar(const wchar_t * const & init);

public:
    using Permutation = std::pair<wchar_t, Bar>;

    using PermutationOptional = std::optional<Permutation>; /// Permutation Optional daje możliwość permutacji przy długości tabliczki mniejszej od capacity
    using Permutations = std::array<PermutationOptional, capacity>; /// Permutation reprezentuje kombinacje, które można uzyskać z poszczególnych liter

    /**
     * @brief get_permutations Funckja zwracająca wszystkie permutacje liter znajdujących się w danej tabliczce
     * @return wszystki epermutacje liter
     */
    Permutations get_permutations() const;
};

