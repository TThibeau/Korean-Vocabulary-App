//
// Created by Thibeau on 8/4/2023.
//

#ifndef KOREANWORDLIST_WORD_H
#define KOREANWORDLIST_WORD_H


#include <string>
#include <ctime>

class Word {
public:
    Word();
    Word(std::wstring &learn_string, std::wstring &translation_string);
    Word(std::wstring &learn_string,
         std::wstring &translation_string,
         int review_count,
         int wrong_count,
         std::wstring last_review);

    std::wstring learn_string;
    std::wstring translation_string;

    int review_count{};
    int wrong_count{};
//    time_t last_review_date{};
    std::wstring last_review_date{};

    void display_word() const;
};


#endif //KOREANWORDLIST_WORD_H
