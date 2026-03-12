#pragma once

#include <iostream>
#include <Windows.h>

// Узел двусвязного списка
struct FDoublyNode
{
    int Data;
    FDoublyNode* Prev;
    FDoublyNode* Next;

    FDoublyNode(int InValue)
        : Data(InValue), Prev(nullptr), Next(nullptr) {
    }
};

// Класс двусвязного линейного списка
class FDoublyLinkedList
{
public:
    // Инициализирует пустой список
    FDoublyLinkedList();
    // Вызывает очистку памяти
    ~FDoublyLinkedList();

    // Добавляет новый узел в конец списка
    void Add(int InValue);

    // Выводит элементы, находящиеся между Min и Max
    void DisplayBetweenMinMax();

    // Выводит все элементы списка
    void Print() const;

    // Полностью очищает список
    void Clear();

private:
    // Ищет узлы с минимальным и максимальным значениями
    void FindMinMax(FDoublyNode*& OutMin, FDoublyNode*& OutMax);

    FDoublyNode* Head;
};

// Запускает выполнение задачи
void SolveDoublyListTask();