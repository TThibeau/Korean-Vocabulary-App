//
// Created by Thibeau on 8/4/2023.
//

#include <iostream>
#include <iomanip>
#include "Word.h"
#include "util.h"
#include "Date.h"

std::wstring convertTimeTToWString(time_t timeValue) {
    std::tm *tmStruct = std::localtime(&timeValue); // Convert time_t to struct tm
    std::wstringstream wss;

    wss << std::put_time(tmStruct, L"%Y-%m-%d"); // Format time using put_time

    return wss.str(); // Extract the wide string
}

void Word::display_word() const {
    std::wcout << this->learn_string << " - " << this->translation_string << std::endl;
}

Word::Word(std::wstring &learn_string, std::wstring &translation_string)
        : learn_string(learn_string),
          translation_string(translation_string),
          review_count(1),
          wrong_count(0),
          last_review_date(convertTimeTToWString(time(nullptr))),
          proficiency_score(0.0) {
}

Word::Word() : review_count(1),
               wrong_count(0),
               last_review_date(convertTimeTToWString(time(nullptr))),
               days_since_review(0),
               proficiency_score(0.0) {
}

Word::Word(std::wstring &learn_string, std::wstring &translation_string, int review_count, int wrong_count,
           std::wstring last_review)
        : learn_string(learn_string),
          translation_string(translation_string),
          review_count(review_count),
          wrong_count(wrong_count),
          last_review_date(last_review) {
    set_days_since_review();
    set_proficiency_score();
}

void Word::set_proficiency_score() {
    float review_days_goal = 30;

    // Set
    proficiency_score = 90 - std::min((float) 1.0, ((float) wrong_count / (float) review_count)) * 90 +
                        (10 - std::min((float) 9, (float) ((float) days_since_review / review_days_goal)) * 10);
    std::cout << "Proficiency score is at " << proficiency_score << std::endl;
}

void Word::set_days_since_review() {
    Date then = get_date_from_wstring(last_review_date);
    time_t currentTime;
    time(&currentTime); // Get the current time in seconds since the epoch

    struct tm *localTime = localtime(&currentTime); // Convert to local time

    int day = localTime->tm_mday;  // Day of the month (1-31)
    int year = localTime->tm_year + 1900; // Year (current year since 1900)
    int month = localTime->tm_mon + 1; // Month (0-11, so add 1 for human-readable month)

    Date now = {day, month, year};
    int delta = getDifference(then, now);

    // Set
    days_since_review = delta;
}

void Word::update_review_state(bool success) {
    last_review_date = convertTimeTToWString(time(nullptr));
    review_count++;
    if (!success) {
        wrong_count++;
    }
    set_days_since_review();
    set_proficiency_score();
}

