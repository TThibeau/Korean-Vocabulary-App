//
// Created by Thibeau on 8/4/2023.
//
#include <iostream>
#include "VocabularyList.h"

void VocabularyList::display_all() {
    system("cls");
    std::cout << "\nWords in the vocabulary list: " << std::endl;
    for (Word &word: word_list) {
        word.display_word();
    }
    std::cout << "=============================" << std::endl;
}

void VocabularyList::display_size() {
    system("cls");
    std::cout << "\nSize of the vocabulary list: " << word_list.size() << std::endl;
    std::cout << "=============================" << std::endl;
}


bool VocabularyList::word_in_list(std::wstring &word) {
    for (Word &wil: word_list) {
        if (wil.korean_string == word) {
            return true;
        }
    }
    return false;
}

void VocabularyList::add_word(Word &new_word) {
    word_list.push_back(new_word);
}

VocabularyList::VocabularyList(std::string &file_name) {
    // TODO: Implement this such that it constructs the obj based on the file
    std::cout << "VocabularyList constructor called" << std::endl;
}

void VocabularyList::save_to_file(std::string &file_name) {
    //TODO
}
