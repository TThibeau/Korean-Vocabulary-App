//
// Created by Thibeau on 8/4/2023.
//

#ifndef KOREANWORDLIST_WORD_H
#define KOREANWORDLIST_WORD_H


#include <string>
#include <ctime>

class Word {
public:
    Word(std::wstring &korean_string, std::wstring &english_string);

    std::wstring korean_string;
    std::wstring english_string;

    int review_count;
    int wrong_count;
    time_t last_review_date;

    void display_word() const;
};


#endif //KOREANWORDLIST_WORD_H
