#include <iostream>
#include "src/VocabularyList.h"
#include "src/App.h"
#include <locale.h> // For setlocale
#include <windows.h>

int main() {
    // Set the correct Language settings for the console
    setlocale(LC_CTYPE, "Korean"); // !!!
    SetConsoleOutputCP(949);
    SetConsoleCP(949);

    // Welcome
    std::wstring welcome_string = L"한국어 어휘 연습에 오신 것을 환영합니다";
    std::wcout << welcome_string << std::endl;

    // Initialization
    std::string vocabulary_filename = "vocabulary_list.txt";
    VocabularyList vocab_list(vocabulary_filename);
//    VocabularyList vocab_list;
    App app(vocab_list);

    // Loop
    while (app.app_state) {
        app.app_loop();
    }

    // Save the vocab list to a file
    vocab_list.save_to_file(vocabulary_filename);

    // End
    std::wcout << L"\n잘 했어요" << std::endl;

    // Wait for user input before closing
    system("pause");

    return 0;
}