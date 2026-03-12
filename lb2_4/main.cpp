//Дан двусвязный линейный список и указатель первый элемент этого
//списка.Все элементы списка хранят различные между собой значения.Необходимо
//вывести значения элементов списка, которые находятся между наименьшим и
//наибольшим элементами списка, в том порядке, в каком они находятся в исходном
//списке.Использовать процедуры.
//
//Все динамические структуры данных реализовывать через классы.Не использовать STL.
//Для каждой динамической структуры должен быть предусмотрен
//стандартный набор методов - добавления / удаления / вывода элементов.
//Во всех задачах обязательно наличие дружественного интерфейса.Ввод данных с клавиатуры.

#include "header.h"

// FIX_ME: Отсутствие локали Windows, выполнение всей логики внутри main, отсутствие PascalCase
/*
int main() {
    setlocale(LC_ALL, "Russian");
    Spisok Spisok;
    Spisok.Initsializatsiya();

    cout << "Введите количество элементов: ";
    int N;
    cin >> N;

    if (N <= 0) {
        cout << "Некорректное число!" << endl;
        return 0;
    }

    cout << "Вводите элементы:" << endl;
    for (int i = 0; i < N; i++) {
        int Chislo;
        if (!(cin >> Chislo)) {
            cout << "Ошибка ввода!" << endl;
            return 0;
        }
        Spisok.DobavitElement(Chislo);
    }

    cout << "Список: ";
    Spisok.VivodSpiska();
    Spisok.VivodMezhduMinMax();
    Spisok.Ochistka();

    return 0;
}
*/
// Настраивает окружение и запускает SolveDoublyListTask
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SolveDoublyListTask();

    std::cout << std::endl;
    system("pause");
    return 0;
}