/**
 * @file word_shuffler.h
 * @brief Объявление функции перемешивания букв в слове
 */

#pragma once

#include <string>

 /**
  * @brief Перемешивает буквы в слове до получения исходного слова
  * @param word Исходное слово для перемешивания
  * @return int Количество попыток перемешивания до совпадения с исходным словом
  */

int shuffle_until_original(const std::string& word);

