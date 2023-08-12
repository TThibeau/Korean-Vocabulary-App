//
// Created by Thibeau on 2023-08-09.
//

#ifndef KOREANWORDLIST_APP_H
#define KOREANWORDLIST_APP_H


#include "VocabularyList.h"

class App {
private:
    VocabularyList *vocab_list;
    std::wstring learning_language;
    std::wstring translation_language;
private:
    void display_new_word_message(const std::wstring &word_string);

public:
    App(VocabularyList &vocab_list, std::wstring learning_language, std::wstring translation_language);

    void add_word_mode();

    void app_loop();

    void display_end_message();

public:
    bool app_state;
};


#endif //KOREANWORDLIST_APP_H
