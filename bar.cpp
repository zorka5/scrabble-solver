#include "bar.hpp"

Bar::Bar(const Letters & letters, const LettersMask & letters_mask):
    letters(letters), letters_mask(letters_mask)
{

}

Bar::Bar(const wchar_t * const & init) {
    size_t i = 0;

    while(init[i]) {
        if (i >= capacity)
            throw std::out_of_range("init to large");

        letters[i] = init[i];
        letters_mask.set(i);

        ++i;
    }
}

Bar::Permutations Bar::get_permutations() const {
    Permutations permutations;

    std::array<wchar_t, capacity> used_letters;
    size_t used_letters_count = 0;

    for(size_t i = 0; i < capacity; ++i) {
        if (!letters_mask[i]) continue;

        bool duplicate_found = false;
        for (size_t j = 0; j < used_letters_count; ++j)
            if (used_letters[j] == letters[i]) {
                duplicate_found = true;
                break;
            }

        if (duplicate_found) continue;

        used_letters[used_letters_count] = letters[i];
        ++used_letters_count;

        LettersMask modified_letters_mask = letters_mask;
        modified_letters_mask.reset(i);

        Permutation permutation(
            letters[i],
            Bar(letters, modified_letters_mask)
        );

        permutations[i] = permutation;
    }

    return permutations;
}
