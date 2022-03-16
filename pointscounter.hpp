#pragma once

#include <memory>
#include "list.hpp"
#include "pair.hpp"

/**
 * @brief The PointsCounter class
 * Klasa obsługująca operacje zwiazane z punktowaniem słów
 */
class PointsCounter
{
public:
    /**
     * @brief PointsCounter
     * Konstruktor funckji PointsCounter
     */
    PointsCounter();

private:
    /**
     * @brief letter_to_points
     * Funkcja pozwalajaca przyznać literze punkty zgodnie z instrukcja gry Scrabble
     * @param letter litera, której mają zostać przyznane punkty
     * @return ilość punktów
     */
    static size_t letter_to_points(wchar_t letter);

public:
    /**
     * @brief count_points
     * Funckja licząca punkty dla całego słowa
     * @param word
     * @return liczba punktów
     */
    static size_t count_points(std::wstring word);

    /**
     * @brief sort_by_points
     * Funckja sortująca słowa wg punktów
     * @param words lista słów
     * @return lista par posortowancyh wg liczby punktów (drugiego elementu pary)
     */
    static List<Pair<std::wstring, size_t>> sort_by_points(const List<std::wstring> &words);
};

