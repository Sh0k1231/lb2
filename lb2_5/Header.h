#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <fstream>
#include <ctime>
#include <Windows.h>

// Заполняет контейнер разными способами (клавиатура, рандом, файл)
template <typename Container>
void FillContainer(Container& OutContainer, int InSize);

// Выводит элементы контейнера в консоль через итераторы
template <typename Container>
void PrintContainer(const Container& InContainer);

// Выполняет вставку элементов дека в список согласно условию задачи
void ExecuteTask(std::deque<int>& OutDeque, std::list<int>& OutList);

// Координирует выполнение программы
void SolveContainerTask();