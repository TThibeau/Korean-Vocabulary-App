//
// Created by Thibeau on 2023-08-09.
//
#include <iostream>
#include "App.h"
#include "Word.h"

App::App(VocabularyList &vocab_list, std::wstring learning_language, std::wstring translation_language)
        : vocab_list(&vocab_list), app_state(true), learning_language(learning_language),
          translation_language(translation_language) {

    // Welcome
    if (learning_language == L"korean" || learning_language == L"Korean") {
        std::wstring welcome_string = L"한국어 어휘 연습에 오신 것을 환영합니다";
        std::wcout << welcome_string << std::endl;
    }
}

void App::add_word_mode() {
    system("cls");
    wchar_t delimiter = L'\n'; // Delimiter (newline)
    std::wcin.ignore(); // Ignore any potential leftover newline characters - Needed to avoid skipping user input

    std::wstring word_string; // Use wstring for wide characters
    std::wcout << L"\nType the " << learning_language << " word you want to add to the list: ";
    std::getline(std::wcin, word_string, delimiter);

    if (!(vocab_list->word_in_list(word_string))) {
        // Confirm the input
        display_new_word_message(word_string);

        std::wstring translation;
        std::wcout << "What is the " << translation_language << " translation of this " << learning_language
                   << " word? ";
        std::getline(std::wcin, translation, delimiter);

        Word new_word(word_string, translation);
        vocab_list->add_word(new_word);

        std::wcout << "'" << word_string << "' and its  " << translation_language << " translation '" << translation
                   << "' are added to the vocabulary list \n";

    } else {
        std::wcout << "'" << word_string << "' was already included in the vocabulary list" << std::endl;
    }
}

void App::app_loop() {
// Next action message
    std::cout << "\n=================================================================\n"
                 "What would you like to do?\n"
                 "[a]  - add a new word\n"
                 "[r]  - review the words\n"
                 "[d]  - display the current list of words\n"
                 "[s]  - show the size of the current list of words\n"
                 "[:q] - terminate the program\n"
                 "=================================================================\n";

    // User input
    std::string choice;
    std::cin >> choice;

    if (choice == ":q")
        app_state = false; // Terminate the program

    if (choice == "a" || choice == "A" || choice == "add" || choice == "Add")
        add_word_mode();

    if (choice == "d" || choice == "D" || choice == "display" || choice == "Display")
        vocab_list->display_all();

    if (choice == "s" || choice == "S" || choice == "size" || choice == "Size")
        vocab_list->display_size();

    if (choice == "r" || choice == "R" || choice == "review" || choice == "Review")
        review_words_mode();
}

void App::display_end_message() {
    if (learning_language == L"korean" || learning_language == L"Korean") {
        std::wcout << L"\n잘 했어요" << std::endl;
    }
}

void App::display_new_word_message(const std::wstring &word_string) {
    if (learning_language == L"korean" || learning_language == L"Korean") {
        std::wcout << L"새로운 단어: " << word_string << std::endl;
    }
}

void App::review_words_mode() {
    wchar_t delimiter = L'\n'; // Delimiter (newline)
    std::wcin.ignore(); // Ignore any potential leftover newline characters - Needed to avoid skipping user input

    bool review_on = true;

    while (review_on) {
        system("cls");
        std::wcout << "=======REVIEW=======" << std::endl;
        int index = vocab_list->get_next_review_word_index();

        Word &review_word = vocab_list->word_list.at(index);

        bool correct = false;

        while (!correct) {
            system("cls");
            std::wcout << "=======REVIEW=======" << std::endl;
            std::wcout << review_word.translation_string << " -> ";

            std::wstring user_input;
            std::getline(std::wcin, user_input, delimiter);

            if (user_input == L":q") {
                correct = true;
                review_on = false;
                break;
            }

            if (user_input == review_word.learn_string) {
                correct = true;
                std::wcout << L"\n맞습니다" << std::endl;
                review_word.update_review_state(true);
            } else {
                std::wcout << L"\n그것은 정확하지 않습니다. 다시 시도하십시오." << std::endl;
                std::wcout << L"The correct translation of '" << review_word.translation_string << L"' is "
                           << review_word.learn_string << std::endl;
                review_word.update_review_state(false);
            }

            system("pause");
        }
    }
}
