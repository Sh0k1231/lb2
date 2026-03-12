#pragma once

#include <iostream>
#include <Windows.h>

//Структура узла очереди (аналог TNode)

struct FNode
{
    int Data;
    FNode* Next;

    FNode(int InValue)
        : Data(InValue)
        , Next(nullptr)
    {
    }
};

// Структура управления очередью (аналог TQueue)
struct FQueue
{
    FNode* Head;
    FNode* Tail;

    FQueue()
        : Head(nullptr)
        , Tail(nullptr)
    {
    }
};

// Добавляет новый элемент в конец очереди Q (процедура Enqueue)
void Enqueue(FQueue& OutQ, int InData);

// Извлекает первый элемент из начала очереди Q (функция Dequeue).
int Dequeue(FQueue& OutQ);

// Выводит все элементы очереди на экран для визуализации.
void DisplayQueue(const FQueue& InQ);

// Проверяет, является ли очередь пустой.
bool IsQueueEmpty(const FQueue& InQ);

// Очищает всю динамическую память, занятую очередью.
void ClearQueue(FQueue& OutQ);

// Главная функция-координатор для решения задачи.
void SolveQueueTask();