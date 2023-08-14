//
// Created by Thibeau on 8/4/2023.
//

#include <iostream>
#include <iomanip>
#include "Word.h"

std::wstring convertTimeTToWString(time_t timeValue) {
    std::tm* tmStruct = std::localtime(&timeValue); // Convert time_t to struct tm
    std::wstringstream wss;

    wss << std::put_time(tmStruct, L"%Y-%m-%d %H:%M:%S"); // Format time using put_time

    return wss.str(); // Extract the wide string
}

void Word::display_word() const {
    std::wcout << this->learn_string << " - " << this->translation_string << std::endl;
}

Word::Word(std::wstring &learn_string, std::wstring &translation_string)
        : learn_string(learn_string),
          translation_string(translation_string),
          review_count(0),
          wrong_count(0),
          last_review_date(convertTimeTToWString(time(nullptr))) {
}

Word::Word() : review_count(0),
               wrong_count(0),
               last_review_date(convertTimeTToWString(time(nullptr))) {
}

Word::Word(std::wstring &learn_string, std::wstring &translation_string, int review_count, int wrong_count,
           std::wstring last_review)
        : learn_string(learn_string),
          translation_string(translation_string),
          review_count(review_count),
          wrong_count(wrong_count),
          last_review_date(last_review) {
}

