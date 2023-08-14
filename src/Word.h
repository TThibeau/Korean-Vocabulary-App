//
// Created by Thibeau on 8/4/2023.
//

#ifndef KOREANWORDLIST_WORD_H
#define KOREANWORDLIST_WORD_H


#include <string>
#include <ctime>

class Word {
private:
    void set_proficiency_score();

    void set_days_since_review();

public:
    Word();

    Word(std::wstring &learn_string, std::wstring &translation_string);

    Word(std::wstring &learn_string,
         std::wstring &translation_string,
         int review_count,
         int wrong_count,
         std::wstring last_review
    );

    std::wstring learn_string;
    std::wstring translation_string;

    int review_count{};
    int wrong_count{};
    std::wstring last_review_date{};
    int days_since_review{};

    float proficiency_score{}; // 100 means fully known, 0 means not known at all
    // 90-(wrong_count/review_count)*90 + (10-(days_since_review/review_days_goal)*10)

    void update_review_state(bool success);

    void display_word() const;
};


#endif //KOREANWORDLIST_WORD_H
