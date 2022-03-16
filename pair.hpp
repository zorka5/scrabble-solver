#pragma once

template <typename T1, typename T2>
/**
 * @brief The Pair struct
 * Struktura reprezentujaca krotke podwójną (parę)
 */
struct Pair
{
public:
    /**
     * @brief Pair
     * Konstruktor struktury Pair
     */
    Pair();

    /**
     * @brief Pair Konstruktor kopiujący
     * @param x pierwszy element pary
     * @param y drugi element pary
     */
    Pair(const T1& x, const T2& y);
public:
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first; ///zmienna reprezentująca pierwszy element pary
    T2 second; ///zmienna reprezentująca drugi element pary

};

template <typename T1, typename T2>
Pair<T1, T2>::Pair(): first(T1()), second(T2())
{

}

template <typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& x, const T2& y): first(x), second(y)
{

}

