#include "pointscounter.hpp"
#include <iostream>
PointsCounter::PointsCounter()
{

}

size_t PointsCounter::letter_to_points(wchar_t letter)
{
    switch(letter) {
        case L'a': return 1;
        case L'ą': return 5;
        case L'b': return 3;
        case L'c': return 2;
        case L'ć': return 6;
        case L'd': return 2;
        case L'e': return 1;
        case L'ę': return 5;
        case L'f': return 5;
        case L'g': return 3;
        case L'h': return 3;
        case L'i': return 1;
        case L'j': return 3;
        case L'k': return 2;
        case L'l': return 2;
        case L'ł': return 3;
        case L'm': return 2;
        case L'n': return 1;
        case L'ń': return 7;
        case L'o': return 1;
        case L'ó': return 5;
        case L'p': return 2;
        case L'q': return 10;
        case L'r': return 1;
        case L's': return 1;
        case L'ś': return 5;
        case L't': return 2;
        case L'u': return 3;
        case L'v': return 4;
        case L'w': return 1;
        case L'x': return 2;
        case L'y': return 2;
        case L'z': return 1;
        case L'ź': return 9;
        case L'ż': return 5;
        case L'_': return 0;

        default:
            throw std::out_of_range("letter_to_points out of range");
    }

}

size_t PointsCounter::count_points(std::wstring word)
{
    size_t points = 0;
    for(wchar_t l: word)
    {
        points += letter_to_points(l);
    }
    return points;
}

List<Pair<std::wstring, size_t>> PointsCounter::sort_by_points(const List<std::wstring> &words )
{
    List<Pair<std::wstring, size_t>> words_points;


    for(auto itr = words.begin();itr != words.end();itr++)
    {
        std::wstring word = *itr;
        size_t points = count_points(word);
        Pair<std::wstring, size_t> list_element(word, points);
        words_points.add_last(list_element);
    }

    auto begin = words_points.begin();
    auto end = words_points.end();

    for(auto i = begin; i != end; ++i)
    {
        for(auto j = begin; j != i; ++j)
        {
            if((*i).second > (*j).second)
            {

                Pair<std::wstring, size_t> temp = *i;
                *i = *j;
                *j = temp;

            }
        }
    }

    return words_points;
}
