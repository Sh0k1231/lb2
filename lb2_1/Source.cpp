#include "header.h"

// конструктор инициализирует указатель Top значением nullptr, обозначая пустой стек
FStack::FStack()
    : Top(nullptr)
    , Count(0)
{
}


// деструктор автоматически вызывается при выходе из области видимости, последовательно освобождая память каждого узла
FStack::~FStack()
{
    // Очистка памяти при удалении объекта
    while (!IsEmpty())
    {
        FStackNode* Temp = Top;
        Top = Top->Next;
        delete Temp;
    }
}

//Выполняет добавление нового узла на вершину стека
void FStack::Push(int InValue)
{
    FStackNode* NewNode = new FStackNode(InValue);
    NewNode->Next = Top;
    Top = NewNode;
    Count++;
}

// FIX_ME: Некорректное имя метода, отсутствие возвращаемого адреса P2 согласно условию, отсутствие std::
/*
void topdel() { //извлечение 1 элемента и его удаление
    Node* temp = p1;
    cout << "Первый элемент стека:" << endl;
    cout << p1->d << endl;
    if (p1->next == nullptr) {
      p1 = nullptr;
    }
    else {
      p1 = p1->next;
    }
    cout << "Адрес новой вершины p1 после извлечения 1 элемента: " << p1 << endl; // Вывод адреса новой вершины
    if (p1 != nullptr) {
        cout << "Значение новой вершины p1: " << p1->d << endl; // Вывод значения новой вершины
    }
    delete temp;
    cnt--;
}
*/

//Извлекает верхний элемент (P1), выводит его значение D и адрес следующего элемента (P2).
void FStack::PopAndDisplay()
{
    if (IsEmpty())
    {
        std::cout << "Ошибка: Попытка извлечь элемент из пустого стека." << std::endl;
        return;
    }

    FStackNode* Temp = Top;

    // Значение D извлекаемого элемента
    int ExtractedData = Temp->Data;

    // Новая вершина P2
    Top = Top->Next;
    FStackNode* NewTopAddress = Top;

    std::cout << "--- Извлечение элемента ---" << std::endl;
    std::cout << "Извлеченное значение D: " << ExtractedData << std::endl;
    std::cout << "Адрес новой вершины P2: " << NewTopAddress << std::endl;

    if (NewTopAddress == nullptr)
    {
        std::cout << "Стек теперь пуст." << std::endl;
    }
    else
    {
        std::cout << "Значение новой вершины: " << NewTopAddress->Data << std::endl;
    }

    delete Temp;
    Count--;
}

//Осуществляет визуализацию стека путем последовательного обхода всех связанных узлов
void FStack::Display() const
{
    if (IsEmpty())
    {
        std::cout << "Стек пуст." << std::endl;
        return;
    }

    FStackNode* Current = Top;
    std::cout << "Текущее состояние стека (от вершины):" << std::endl;
    while (Current != nullptr)
    {
        std::cout << "[ " << Current->Data << " ] -> адрес: " << Current << std::endl;
        Current = Current->Next;
    }
}

//Проверяет логическое состояние стека
bool FStack::IsEmpty() const
{
    return Top == nullptr;
}

//Координирует выполнение задачи: отвечает за инициализацию стека
void SolveStackTask()
{
    FStack MyStack;
    int ElementsCount = 0;

    std::cout << "Введите количество элементов для добавления в стек: ";
    if (!(std::cin >> ElementsCount) || ElementsCount < 0)
    {
        std::cout << "Ошибка: Некорректное количество элементов." << std::endl;
        return;
    }

    for (int i = 0; i < ElementsCount; ++i)
    {
        int Value;
        std::cout << "Введите значение для элемента #" << i + 1 << ": ";
        if (std::cin >> Value)
        {
            MyStack.Push(Value);
        }
    }

    MyStack.Display();
    std::cout << std::endl;

    if (!MyStack.IsEmpty())
    {
        MyStack.PopAndDisplay();
    }

    std::cout << std::endl;
    MyStack.Display();
}