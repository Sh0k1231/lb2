#include "header.h"

// Реализует добавление элемента в хвост очереди
void Enqueue(FQueue& OutQ, int InData)
{
    FNode* NewNode = new FNode(InData);

    if (OutQ.Tail)
    {
        OutQ.Tail->Next = NewNode;
    }
    else
    {
        OutQ.Head = NewNode;
    }

    OutQ.Tail = NewNode;
}

// FIX_ME: некорректные имена (front/last вместо Head/Tail), отсутствие PascalCase, отсутствие std::
/*
int Dequeue(PQueue& Q) {
    PNode* temp = Q.front;
    int value = temp->data;
    Q.front = Q.front->next;
    if (Q.front == nullptr) {
        Q.last = nullptr; // Если очередь стала пустой
    }
    delete temp; // Освобождаем память
    return value;
}
*/

// Реализует извлечение элемента из головы очереди
int Dequeue(FQueue& OutQ)
{
    if (IsQueueEmpty(OutQ))
    {
        return 0;
    }

    FNode* Temp = OutQ.Head;
    int ResultData = Temp->Data;

    OutQ.Head = OutQ.Head->Next;

    if (OutQ.Head == nullptr)
    {
        OutQ.Tail = nullptr;
    }

    delete Temp;
    return ResultData;
}

// Проверяет состояние указателей Head и Tail
bool IsQueueEmpty(const FQueue& InQ)
{
    return InQ.Head == nullptr;
}

// Выполняет последовательный обход очереди от головы до хвоста
void DisplayQueue(const FQueue& InQ)
{
    if (IsQueueEmpty(InQ))
    {
        std::cout << "Очередь пуста." << std::endl;
        return;
    }

    FNode* Current = InQ.Head;
    std::cout << "Содержимое очереди: ";
    while (Current != nullptr)
    {
        std::cout << "[" << Current->Data << "] ";
        Current = Current->Next;
    }
    std::cout << std::endl;
}

// Циклически вызывает Dequeue до тех пор, пока очередь не станет пустой
void ClearQueue(FQueue& OutQ)
{
    while (!IsQueueEmpty(OutQ))
    {
        Dequeue(OutQ);
    }
}

/** * Организует выполнение задания: заполнение очереди через Enqueue и
 * извлечение пяти элементов через Dequeue с выводом итоговых адресов Head и Tail.
 */
void SolveQueueTask()
{
    FQueue MyQueue;
    int NumToAdd = 0;

    std::cout << "Введите количество чисел для добавления в очередь (минимум 5): ";
    std::cin >> NumToAdd;

    if (NumToAdd < 5)
    {
        std::cout << "Предупреждение: по условию задачи элементов должно быть не менее 5." << std::endl;
    }

    for (int i = 0; i < NumToAdd; ++i)
    {
        int Value;
        std::cout << "Введите число #" << i + 1 << ": ";
        std::cin >> Value;
        Enqueue(MyQueue, Value);
    }

    std::cout << std::endl << "Исходная очередь:" << std::endl;
    DisplayQueue(MyQueue);

    std::cout << std::endl << "Извлекаем 5 элементов через Dequeue:" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        if (!IsQueueEmpty(MyQueue))
        {
            int Val = Dequeue(MyQueue);
            std::cout << "Извлечено: " << Val << std::endl;
        }
        else
        {
            std::cout << "Очередь опустела раньше времени." << std::endl;
            break;
        }
    }

    std::cout << std::endl << "--- Итоги ---" << std::endl;
    std::cout << "Адрес начала (Head): " << MyQueue.Head << std::endl;
    std::cout << "Адрес конца (Tail): " << MyQueue.Tail << std::endl;

    if (!IsQueueEmpty(MyQueue))
    {
        std::cout << "Значение новой головы: " << MyQueue.Head->Data << std::endl;
    }

    ClearQueue(MyQueue);
}