//
// Created by Thibeau on 8/4/2023.
//
#include <iostream>
#include <fstream> // For std::ofstream
#include <codecvt>
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

VocabularyList::~VocabularyList() {
    std::cout << "VocabularyList destructor called" << std::endl;
}

std::vector<Word> VocabularyList::load_from_file(std::string &file_name) {
    std::wifstream file_obj(file_name, std::ios::app);

    std::vector<Word> loaded_words;

    // Move the reading position to the beginning of the file
    file_obj.seekg(0);

    if (file_obj.is_open()) {
        std::wstring korean_string;
        file_obj >> korean_string;
        Word first_word{};
        first_word.korean_string = korean_string;
        loaded_words.push_back(first_word);

        while (!file_obj.eof()) {
            std::getline(file_obj, korean_string);
            file_obj >> korean_string;
            if (file_obj) {
                Word new_word{};
                new_word.korean_string = korean_string;
                loaded_words.push_back(new_word);
            }
        }
    }
    file_obj.close();
    return loaded_words;
}



void VocabularyList::save_to_file(std::string &file_name) {
    std::wofstream file_obj(file_name, std::ios::binary);

    if (!file_obj.is_open()) {
        std::cerr << "Error opening file for writing: " << file_name << std::endl;
        return;
    }

    // Write each word in the vector
    for (const Word &word: word_list) {
        file_obj << word.korean_string << std::endl;
    }

    file_obj.close();
}

//void VocabularyList::read_word_from_file(std::string file_name) {
//    std::wifstream file_obj(file_name, std::ios::app);
//
//    // Move the reading position to the beginning of the file
//    file_obj.seekg(0);
//
//    if (file_obj.is_open()) {
//        std::wstring korean_string;
//
//        file_obj >> korean_string;
//        std::wcout << L"Word read from file: " << korean_string << std::endl;
//
//        while (!file_obj.eof()) {
//            std::getline(file_obj, korean_string);
//            file_obj >> korean_string;
//            if (file_obj)
//                std::wcout << L"Word read from file: " << korean_string << std::endl;
//        }
//    }
//    file_obj.close();
//}

VocabularyList::VocabularyList(std::string &file_name): word_list(load_from_file(file_name)) {}
