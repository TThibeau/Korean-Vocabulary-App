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

    std::wstring learn_lang = L"korean";
    std::wstring translate_lang = L"english";

    // Initialization
    std::string vocabulary_filename = "vocabulary_list.txt";
    VocabularyList vocab_list(vocabulary_filename);
    App app(vocab_list, learn_lang, translate_lang);

    // Loop
    while (app.app_state) {
        app.app_loop();
    }

    // Save the vocab list to a file
    vocab_list.save_to_file(vocabulary_filename);

    // End message
    app.display_end_message();

    // Wait for user input before closing
    system("pause");

    return 0;
}