#include "header.h"

// Установка начального состояния указателя
FDoublyLinkedList::FDoublyLinkedList() : Head(nullptr) {}

// Очистка при разрушении объекта
FDoublyLinkedList::~FDoublyLinkedList()
{
    Clear();
}

// Создает узел и связывает его с концом списка
void FDoublyLinkedList::Add(int InValue)
{
    FDoublyNode* NewNode = new FDoublyNode(InValue);
    if (Head == nullptr)
    {
        Head = NewNode;
    }
    else
    {
        FDoublyNode* Current = Head;
        while (Current->Next != nullptr)
        {
            Current = Current->Next;
        }
        Current->Next = NewNode;
        NewNode->Prev = Current;
    }
}

// Печатает данные всех узлов по порядку
void FDoublyLinkedList::Print() const
{
    FDoublyNode* Current = Head;
    while (Current != nullptr)
    {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    }
    std::cout << std::endl;
}

// Линейный поиск узлов с экстремальными значениями
void FDoublyLinkedList::FindMinMax(FDoublyNode*& OutMin, FDoublyNode*& OutMax)
{
    if (!Head) return;

    OutMin = Head;
    OutMax = Head;
    FDoublyNode* Current = Head->Next;

    while (Current != nullptr)
    {
        if (Current->Data < OutMin->Data) OutMin = Current;
        if (Current->Data > OutMax->Data) OutMax = Current;
        Current = Current->Next;
    }
}

// FIX_ME: Использование громоздких имен, сложная логика проверки порядка, отсутствие PascalCase
/*
void VivodMezhduMinMax() {
    Uzel* Min = nullptr;
    Uzel* Max = nullptr;
    PoiskMinMax(Min, Max);

    if (Min == nullptr || Max == nullptr || Min == Max) {
        cout << "Нет элементов для вывода!" << endl;
        return;
    }

    bool MinPerviy = ProverkaPoryadka(Min, Max);
    Uzel* Start = MinPerviy ? Min : Max;
    Uzel* End = MinPerviy ? Max : Min;

    cout << "Элементы между " << Min->Znachenie << " и " << Max->Znachenie << ": ";
    Uzel* Tekushiy = Start->Sleduyushiy;
    bool EstElementy = false;

    while (Tekushiy != nullptr && Tekushiy != End) {
        cout << Tekushiy->Znachenie << " ";
        EstElementy = true;
        Tekushiy = Tekushiy->Sleduyushiy;
    }

    if (!EstElementy) cout << "Отсутствуют";
    cout << endl;
}
*/
// Определяет границы и выводит данные узлов, лежащих строго между ними
void FDoublyLinkedList::DisplayBetweenMinMax()
{
    FDoublyNode* MinNode = nullptr;
    FDoublyNode* MaxNode = nullptr;
    FindMinMax(MinNode, MaxNode);

    if (!MinNode || !MaxNode || MinNode == MaxNode)
    {
        std::cout << "Элементы между Min и Max отсутствуют." << std::endl;
        return;
    }

    // Определяем, кто из них стоит в списке раньше
    FDoublyNode* Start = nullptr;
    FDoublyNode* End = nullptr;
    FDoublyNode* Current = Head;

    while (Current != nullptr)
    {
        if (Current == MinNode || Current == MaxNode)
        {
            if (!Start) Start = Current;
            else { End = Current; break; }
        }
        Current = Current->Next;
    }

    std::cout << "Элементы между " << MinNode->Data << " и " << MaxNode->Data << ": ";
    bool bFound = false;
    Current = Start->Next;
    while (Current != End)
    {
        std::cout << Current->Data << " ";
        bFound = true;
        Current = Current->Next;
    }

    if (!bFound) std::cout << "пусто";
    std::cout << std::endl;
}

// Удаляет узлы, двигаясь от головы списка
void FDoublyLinkedList::Clear()
{
    while (Head != nullptr)
    {
        FDoublyNode* Temp = Head;
        Head = Head->Next;
        delete Temp;
    }
}

// Реализует ввод количества, элементов и вызов логики поиска
void SolveDoublyListTask()
{
    FDoublyLinkedList List;
    int N;

    std::cout << "Введите количество элементов: ";
    if (!(std::cin >> N) || N <= 0) return;

    std::cout << "Вводите числа:" << std::endl;
    for (int i = 0; i < N; ++i)
    {
        int Value;
        std::cin >> Value;
        List.Add(Value);
    }

    std::cout << "Ваш список: ";
    List.Print();

    List.DisplayBetweenMinMax();
}