//
// Created by Thibeau on 8/4/2023.
//

#ifndef KOREANWORDLIST_VOCABULARYLIST_H
#define KOREANWORDLIST_VOCABULARYLIST_H


#include <vector>
#include "Word.h"

class VocabularyList {
private:
    std::vector<Word> word_list;
public:
    VocabularyList(std::string &file_name);

public:
    void display_all();

    void display_size();

    void add_word(Word &new_word);

    void save_to_file(std::string &file_name);

    bool word_in_list(std::wstring &word);

};


#endif //KOREANWORDLIST_VOCABULARYLIST_H
