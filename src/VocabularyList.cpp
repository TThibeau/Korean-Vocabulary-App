//
// Created by Thibeau on 8/4/2023.
//
#include <iostream>
#include <fstream> // For std::ofstream
#include <codecvt>
#include <sstream> // For std::wstringstream
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
        if (wil.learn_string == word) {
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
        std::wstring line;

        while (!file_obj.eof()) {
            std::getline(file_obj, line);
            if (file_obj) {
                Word word = build_word_from_line(line);
                if (!word.learn_string.empty())
                    loaded_words.push_back(word);
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
        file_obj << word.learn_string << ","
                 << word.translation_string << ","
                 << word.review_count << ","
                 << word.wrong_count << ","
                 << word.last_review_date << std::endl;
    }

    file_obj.close();
}

VocabularyList::VocabularyList(std::string &file_name) : word_list(load_from_file(file_name)) {}

Word VocabularyList::build_word_from_line(const std::wstring &line) {
    std::wstringstream ss(line);  // Create a wstringstream from the line

    std::vector<std::wstring> values;  // Create a vector to store the separated values

    while (ss.good()) {
        std::wstring substr;
        getline(ss, substr, L',');  // Split the line using ',' as the delimiter
        values.push_back(substr);   // Add the extracted value to the vector
    }

    if (values.size() > 1) {
        // TODO: Perhaps an enum (instead of vector) serves better here?
        Word new_word(values.at(0),
                      values.at(1),
                      std::stoi(values.at(2)),
                      std::stoi(values.at(3)),
                      values.at(4)
        );
        return new_word;
    } else {
        return {};
    }
}
