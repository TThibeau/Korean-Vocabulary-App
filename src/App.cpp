//
// Created by Thibeau on 2023-08-09.
//
#include <iostream>
#include <utility>
#include "App.h"
#include "Word.h"

App::App(VocabularyList vocab_list) : vocab_list(std::move(vocab_list)), app_state(true) {
}

void App::add_word_mode() {
    system("cls");

    std::wstring word_string; // Use wstring for wide characters
    std::wcout << L"\nType the korean word you want to add to the list: ";
    std::wcin >> word_string;

    std::wcout << L"새로운 단어: " << word_string << std::endl;


    if (!(vocab_list.word_in_list(word_string))) {
        std::wstring translation;
        std::cout << "What is the english translation of this korean word? ";
        std::wcin >> translation;

        Word new_word(word_string, translation);
        vocab_list.add_word(new_word);

        std::wcout << "'" << word_string << "' and its english translation '" << translation
                   << "' are added to the vocabulary list \n";

    } else {
        std::wcout << "'" << word_string << "' was already in the vocabulary list" << std::endl;
    }
}

void App::app_loop() {
// Next action message
    std::cout << "\n=================================================================\n"
                 "What would you like to do?\n"
                 "[a]  - add a new word\n"
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
        vocab_list.display_all();

    if (choice == "s" || choice == "S" || choice == "size" || choice == "Size")
        vocab_list.display_size();
}
