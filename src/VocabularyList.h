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
    explicit VocabularyList(std::string &file_name);
    ~VocabularyList();

public:
    void display_all();

    void display_size();

    void add_word(Word &new_word);

    std::vector<Word> load_from_file(std::string &file_name);

    void read_word_from_file(std::string file_name);

    void save_to_file(std::string &file_name);

    bool word_in_list(std::wstring &word);

};


#endif //KOREANWORDLIST_VOCABULARYLIST_H
