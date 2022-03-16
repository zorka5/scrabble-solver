#include "solver.hpp"
#include <iostream>

Solver::Words Solver::solve(const TrieNode & node, const Bar & bar) {
    Words words;
    Stack stack(
       StackArray(),
       0
    );
    solve(node, bar, stack, words);

    return words;
}

void Solver::solve(const TrieNode & node, const Bar & bar, const Stack & stack, Words & words) {
    if (node.get_is_terminal()) {
        std::wstring word(stack.first.data(), stack.second);
        //words.emplace_back(std::move(word));

        words.add_last(word);
    }

    Bar::Permutations permutations = bar.get_permutations();
    for (const auto & permutation_opt : permutations)
    {
        if (!permutation_opt) continue;
        const auto & permutation = *permutation_opt;

        if(permutation.first == '_')
        {
            size_t letters_count = TrieNode::get_letters_count();
            for(size_t i = 0; i < letters_count; i++)
            {
                wchar_t letter = node.index_to_letter(i);
                const TrieNode * const child_node = node.get_next(letter);

                if (!child_node) continue;

                StackArray child_stack_array(stack.first);
                child_stack_array[stack.second] = letter;
                Stack child_stack(
                    child_stack_array,
                    stack.second + 1
                );

                solve(*child_node, permutation.second, child_stack, words);
            }
        }
        else{
            const TrieNode * const child_node = node.get_next(permutation.first);
            if (!child_node) continue;

            StackArray child_stack_array(stack.first);
            child_stack_array[stack.second] = permutation.first;

            Stack child_stack(
                child_stack_array,
                stack.second + 1
            );


            solve(*child_node, permutation.second, child_stack, words);


        }


    }
}


