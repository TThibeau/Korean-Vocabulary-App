//
// Created by Thibeau on 8/4/2023.
//

#include <iostream>
#include "Word.h"

void Word::display_word() const {
    std::wcout << this->korean_string << " - " << this->english_string << std::endl;
}

Word::Word(std::wstring &korean_string, std::wstring &english_string)
        : korean_string(korean_string),
          english_string(english_string),
          review_count(0),
          wrong_count(0),
          last_review_date(time(nullptr)) {
}

Word::Word(): korean_string(L""),
              english_string(L""),
              review_count(0),
              wrong_count(0),
              last_review_date(time(nullptr)) {
}
