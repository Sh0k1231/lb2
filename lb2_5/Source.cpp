#include "header.h"

// FIX_ME: Использование циклов вместо одного вызова insert, отсутствие std::, некорректная работа с итераторами
/*
void Insert(deque<int>& D, list<int>& L)//Вставка перед 5 с конца элемента списка последних 5 элементов дека в обратном порядке
{
    list<int>::iterator it = L.end();
    for (int i = 0; i < 5;i++)
        --it;
    for (int i = 4; i >= 0; i--)
        it = L.insert(it, D[D.size() - 1 - i]);
}
*/
// Находит нужную позицию в списке и вставляет диапазон через обратные итераторы дека
void ExecuteTask(std::deque<int>& OutDeque, std::list<int>& OutList)
{
    if (OutDeque.size() < 5 || OutList.size() < 5) return;

    // Находим позицию: 5-й с конца элемент списка
    auto ListIt = OutList.end();
    std::advance(ListIt, -5);

    // Определяем диапазон дека: последние 5 элементов в обратном порядке
    // Используем rbegin() для начала отсчета с конца
    auto DequeStart = OutDeque.rbegin();
    auto DequeEnd = OutDeque.rbegin();
    std::advance(DequeEnd, 5);

    // Вставляем одним вызовом функции-члена insert
    OutList.insert(ListIt, DequeStart, DequeEnd);
}

// Реализует выбор метода заполнения и валидацию размера
template <typename Container>
void FillContainer(Container& OutContainer, int InSize)
{
    if (InSize < 5)
    {
        std::cout << "Ошибка: размер должен быть не менее 5." << std::endl;
        return;
    }

    std::cout << "Способ заполнения:\n1) Клавиатура\n2) Рандом\n3) Файл\nВыбор: ";
    int Choice;
    std::cin >> Choice;

    if (Choice == 1)
    {
        for (int i = 0; i < InSize; ++i)
        {
            int Val;
            std::cout << "Элемент [" << i << "]: ";
            std::cin >> Val;
            OutContainer.push_back(Val);
        }
    }
    else if (Choice == 2)
    {
        for (int i = 0; i < InSize; ++i)
        {
            OutContainer.push_back(std::rand() % 100);
        }
    }
    else if (Choice == 3)
    {
        std::ifstream File("data.txt");
        if (File.is_open())
        {
            int Val;
            for (int i = 0; i < InSize && File >> Val; ++i)
            {
                OutContainer.push_back(Val);
            }
            File.close();
        }
    }
}

// Проходит по контейнеру от begin до end через константный итератор
template <typename Container>
void PrintContainer(const Container& InContainer)
{
    for (auto It = InContainer.begin(); It != InContainer.end(); ++It)
    {
        std::cout << *It << " ";
    }
    std::cout << std::endl;
}

// Запрашивает данные у пользователя и выводит результат манипуляций
void SolveContainerTask()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::deque<int> MyDeque;
    std::list<int> MyList;
    int SizeD, SizeL;

    std::cout << "Введите размер дека (>=5): ";
    std::cin >> SizeD;
    FillContainer(MyDeque, SizeD);

    std::cout << "Введите размер списка (>=5): ";
    std::cin >> SizeL;
    FillContainer(MyList, SizeL);

    std::cout << "\nИсходный дек: ";
    PrintContainer(MyDeque);
    std::cout << "Исходный список: ";
    PrintContainer(MyList);

    ExecuteTask(MyDeque, MyList);

    std::cout << "\nРезультат вставки в список: ";
    PrintContainer(MyList);
}