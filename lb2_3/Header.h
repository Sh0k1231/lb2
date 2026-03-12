#pragma once

#include <iostream>
#include <Windows.h>

// Узел односвязного списка
struct FNode
{
    int Data;
    FNode* Next;

    FNode(int InValue) : Data(InValue), Next(nullptr) {}
};

// Класс односвязного списка
class FLinkedList
{
public:
    // Инициализирует пустой список
    FLinkedList();
    // Очищает память при уничтожении объекта
    ~FLinkedList();

    // Добавляет новый узел в конец списка
    void Add(int InValue);

    // Вставляет значение M перед каждым вторым элементом исходного списка
    void InsertMBeforeEverySecond(int InM);

    // Выводит значения всех узлов в консоль
    void Print() const;

    // Находит и возвращает указатель на последний элемент
    FNode* GetLastNode() const;

    // Последовательно удаляет все узлы списка
    void Clear();

private:
    FNode* Head;
};

// Координирует ввод данных и решение задачи
void SolveListTask();