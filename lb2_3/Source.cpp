#include "header.h"

// Конструктор: зануляет указатель на голову
FLinkedList::FLinkedList() : Head(nullptr) {}

// Деструктор: вызывает метод очистки памяти
FLinkedList::~FLinkedList()
{
    Clear();
}

// Создает узел и присоединяет его к концу цепочки
void FLinkedList::Add(int InValue)
{
    FNode* NewNode = new FNode(InValue);
    if (Head == nullptr)
    {
        Head = NewNode;
    }
    else
    {
        FNode* Current = Head;
        while (Current->Next != nullptr)
        {
            Current = Current->Next;
        }
        Current->Next = NewNode;
    }
}

// FIX_ME: Использование count и оператора %, некорректные имена, отсутствие PascalCase
/*
void insertBeforeEverySecond(int M) {
    Node* current = head;
    int count = 1;

    while (current != nullptr && current->next != nullptr) {
        if (count % 2 == 1) {
            Node* newNode = new Node(M);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }
        else {
            current = current->next;
        }
        count++;
    }
}
*/
// Вставляет новый узел M, перестраивая связи указателей каждые два шага
void FLinkedList::InsertMBeforeEverySecond(int InM)
{
    FNode* Current = Head;

    while (Current != nullptr && Current->Next != nullptr)
    {
        FNode* NewNode = new FNode(InM);
        NewNode->Next = Current->Next;
        Current->Next = NewNode;

        Current = NewNode->Next->Next;
    }
}

// Проходит по списку и печатает данные каждого узла
void FLinkedList::Print() const
{
    FNode* Current = Head;
    while (Current != nullptr)
    {
        std::cout << Current->Data << " ";
        Current = Current->Next;
    }
    std::cout << std::endl;
}

// Ищет узел, у которого поле Next равно nullptr
FNode* FLinkedList::GetLastNode() const
{
    if (Head == nullptr) return nullptr;

    FNode* Current = Head;
    while (Current->Next != nullptr)
    {
        Current = Current->Next;
    }
    return Current;
}

// Удаляет текущую голову списка, пока цепочка не станет пустой
void FLinkedList::Clear()
{
    while (Head != nullptr)
    {
        FNode* Temp = Head;
        Head = Head->Next;
        delete Temp;
    }
}

// Реализует дружественный интерфейс для взаимодействия с пользователем
void SolveListTask()
{
    FLinkedList List;
    int ElementsCount, MValue;

    std::cout << "Введите количество элементов списка: ";
    std::cin >> ElementsCount;

    std::cout << "Введите элементы: ";
    for (int i = 0; i < ElementsCount; ++i)
    {
        int Val;
        std::cin >> Val;
        List.Add(Val);
    }

    std::cout << "Введите значение M для вставки: ";
    std::cin >> MValue;

    List.InsertMBeforeEverySecond(MValue);

    std::cout << "Результирующий список: ";
    List.Print();

    FNode* Last = List.GetLastNode();
    if (Last)
    {
        std::cout << "Ссылка на последний элемент (P2): " << Last << std::endl;
        std::cout << "Значение последнего элемента: " << Last->Data << std::endl;
    }
}