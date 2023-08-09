//
// Created by Thibeau on 2023-08-09.
//

#ifndef KOREANWORDLIST_APP_H
#define KOREANWORDLIST_APP_H


#include "VocabularyList.h"

class App {
private:
    VocabularyList vocab_list;
public:
    explicit App(VocabularyList vocab_list);

    void add_word_mode();

    void app_loop();

public:
    bool app_state;
};


#endif //KOREANWORDLIST_APP_H
