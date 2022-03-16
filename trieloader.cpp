#include "trieloader.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>
#include <codecvt>
#include <locale>
#include <string>

TrieNode TrieLoader::load_from_file(const char * const & file_name) {
    std::ifstream f(file_name);
    if (!f.good()) {
        throw std::runtime_error("f is not good");
    }

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    TrieNode root;

    size_t oks = 0;
    size_t errors = 0;

    std::string line_utf8;
    while (std::getline(f, line_utf8)) {
        std::wstring line = converter.from_bytes(line_utf8.data());
        try {
            root.add(line.data());
            ++oks;
        } catch (const std::exception &/* e*/) {
            ++errors;
        }
    }

    std::wcout << oks << " / " << errors << std::endl;

    return root;
}
