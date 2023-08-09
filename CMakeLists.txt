cmake_minimum_required(VERSION 3.25)
project(KoreanWordList)

set(CMAKE_CXX_STANDARD 20)

add_executable(KoreanWordList main.cpp src/VocabularyList.cpp src/VocabularyList.h src/Word.cpp src/Word.h src/App.cpp src/App.h)
