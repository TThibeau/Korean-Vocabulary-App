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
    std::string vocabulary_filename = "vocabulary_list.csv";
    VocabularyList vocab_list(vocabulary_filename); // TODO: To be implemented
    App app(vocab_list);

    // Loop
    while (app.app_state) {
        app.app_loop();
    }

    // End
    std::wcout << L"\n잘 했어요" << std::endl;

    // Wait for user input before closing
    system("pause");

    return 0;
}


//#include <stdio.h>
//#include <locale.h>
//#include <iostream>
//#include "windows.h"
//
//int main(void) {
//    // localization (perhaps needed for some computers)
//    setlocale(LC_CTYPE, "Korean");
//    SetConsoleOutputCP(949);
//    SetConsoleCP(949);
//
//    // open log file for writing
//    FILE *outfile;
//    outfile = _wfopen(L"log.txt", L"wt+,ccs=UTF-16LE");
//    // test data
//    wchar_t wch = L'술';
//    std::wcout << wch << std::endl;
//
//    wchar_t nwch;
//    std::wcin >> nwch;
//    std::wcout << "Entered korean_string: " << nwch << std::endl;
//
//    // write one character to log file
//    fwrite(&wch, sizeof(wchar_t), 1, outfile);
//    // close file
//    fclose(outfile);
//
//    return 0;
//}