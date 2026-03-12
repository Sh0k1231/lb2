#pragma once

#include <iostream>
#include <Windows.h>

// Структура узла стека 
struct FStackNode
{
    int Data;
    FStackNode* Next;

    FStackNode(int InValue)
        : Data(InValue)
        , Next(nullptr)
    {
    }
};

// Класс стека с дружественным интерфейсом 
class FStack
{
public:
    FStack();
    ~FStack();

    // Добавление элемента в стек (Push) 
    void Push(int InValue);

    // Извлечение верхнего элемента с выводом данных и адреса новой вершины 
    void PopAndDisplay();

    // Вывод всех элементов стека 
    void Display() const;

    // Проверка, пуст ли стек
    bool IsEmpty() const;

private:
    FStackNode* Top;
    int Count;
};

// Функция для запуска задачи 
void SolveStackTask();