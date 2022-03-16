#include <iostream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <chrono>
//#include <thread>

#include <codecvt>
//#include <locale>
#include <string>

#include "trieloader.hpp"
#include "trienode.hpp"
#include "bar.hpp"
#include "solver.hpp"
#include "pointscounter.hpp"
#include "pair.hpp"
#include "list.hpp"


/**
 * @brief displayer Wypisywanie
 *
 * Funckja pozwalająca wyświetlać w konsoli działanie programu
 * @param bar_string ciąg znaków zawierający stan "tabliczki"
 * @param root korzeń drzewa Trie
 */

void displayer(std::wstring bar_string, TrieNode &root)
{
    if (bar_string.empty())
    {
        std::wcout << "Enter some letters" << std::endl;
        return;
    }
    if(bar_string.size() > Bar::capacity)
    {
        std::wcout << "Too many letters. Try again. " << std::endl;
        system("PAUSE");
        return;
    }
    try {
        Bar bar(bar_string.c_str());

        //std::wcout << "Starting search" << std::endl;
        Solver::Words words = Solver::solve(root, bar);
        std::wcout << "Completed search: " << words.get_size() << std::endl;

        size_t size = words.get_size();

        if(size == 0)
        {
            std::wcout << "Can't form any word from letters:" << bar_string <<". Try again." << std::endl;
        }

        List<Pair<std::wstring, size_t>> words_points = PointsCounter::sort_by_points(words);
        int sentinel = 0;
        for(auto itr = words_points.begin();itr != words_points.end();itr++)
        {
            std::wcout << sentinel +1 << ". " <<  itr->first << "(" << itr->second << ")"<< std::endl;
            sentinel++;
        }
    } catch (std::exception &e) {
        std::wcout << L"Exception occured: " <<  e.what() <<"\nTry again. " << std::endl;
    }

}

/**
 * \mainpage
 * \par Program szukający rozwiązań do gry Scrabble przy użyciu drzewa Trie
 * \author Zofia Kubrak
 * \date 2020.05.27
 */

int main()
{
    srand(time(nullptr));

    _setmode(_fileno(stdout), _O_U16TEXT); ///poprawne wypisywanie polskich znaków
    _setmode( _fileno(stdin), _O_U16TEXT ); ///poprawne wczytywanie polskich znaków

    std::wcout << L"Starting file loading. This may take a while." << std::endl;
    TrieNode root = TrieLoader::load_from_file("slowa.txt");
    std::wcout << L"Completed file loading" << std::endl;

    system("PAUSE");

    while (true) {
        system("cls");
        std::wcout <<  "Select your choice: \n1.end\n2.enter your letters\n3.generate random letters" << std::endl;
        wchar_t choice;
        std::wcin >> choice;

        switch(choice){
        case '1':
            return 0;
        case '2':
        {
            std::wcout << "Enter your letters. For 'blank' enter '_'. " << std::endl;
            std::wstring bar_string;
            std::wcin >> bar_string;
            std::transform(bar_string.begin(), bar_string.end(), bar_string.begin(), ::tolower);
            displayer(bar_string, root);
            break;
        }

        case '3':
        {
            std::wstring bar_string;

            size_t len = 2 + std::rand()%(Bar::capacity - 2 +1); ///losowanie co najmniej 2 liter
            for(wchar_t i = 0; i < len; ++i)
            {
                const size_t index =  std::rand()%36;
                bar_string += root.index_to_letter(index);
            }

            std::wcout << "Generated letters: "<< bar_string << std::endl;
            displayer(bar_string, root);
            break;
        }
        default:
            continue;

        }
        system("PAUSE");
    }

    return 0;
}

