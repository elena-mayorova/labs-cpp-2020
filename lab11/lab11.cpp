// ЛАБОРАТОРНАЯ РАБОТА 11
/* 
    1) Сделать копию файла, созданного в лабораторной работе 8
    2) Удалить содержимое функции main
    3) Убедиться, что класс TMyClass содержит конструктор по умолчанию с параметрами, позволяющими инициализировать все поля класса.
       Все поля должны быть объявлены как private
    4) В функции main:
        а) Создать три объекта класса TMyClass: 1-й как обычную переменную с помощью конструктора по умолчанию; 
           2-й - как обычную переменную с помощью конструктора копии; 
           3-й - с помощью указателя
        б) убедиться, что все работает правильно, вызвав для каждого из созданных объектов метод вывода
    5) На базе класса TMyClass с помощью механизма наследования создать дочерний класс TChild. Режим наследования public. 
       Производный класс должен содержать следующие собственные члены (помимо наследуемых):
        а) Поля - double, double*
        б) Конструктор по умолчанию с параметрами и конструктор  копии (конструкторы не наследуются!). 
           При создании объекта с помощью этого конструктора инициализации членов класса будет осуществляться от 
           заданных параметров (количество параметров и их типы должны соответствовать полям класса)
        в) Функцию вывода на экран значений как собственных, так и унаследованных полей. Она должна иметь то же имя,
           что и функция родительского класса
    6) В функции main:
        а) Создать три объекта класса TChild: 1-й - как обычную переменную с помощью конструктора по умолчанию; 
           2-й - как обычную переменную с помощью конструктора копии;
           3-й - с помощью указателя.
        б) Вызвать для каждого из созданных объектов собственных метод вывода
        в) Вызвать для каждого из созданных объектов унаследованный метод вывода
        г) Проверить, наследуется ли дружественная функция
    7) СОХРАНИТЬ ЕЩЕ ПОНАДОБИТСЯ
*/
//----------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>

const int numberInStatic = 5;

class TMyClass
{
    int numberInDynamic;
    double object1;
    double* pointer;
    char staticArray[numberInStatic];
    long int* dynamicArray;

public:
    void input();
    void output();
    double fff(); // ср. ар. отриц. эл-тов в динам. массиве

    TMyClass(int xnumberInDynamic = 5, double xobject1 = 1, double xpointer = 0.789, char xstaticArray = 'w', long int xdynamicArray = 0);
    TMyClass(const TMyClass& object);
    ~TMyClass();

    friend void finput(TMyClass& object);
};
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
TMyClass::TMyClass(int xnumberInDynamic, double xobject1, double xpointer, char xstaticArray, long int xdynamicArray)
{
    numberInDynamic = xnumberInDynamic;
    object1 = xobject1;
    pointer = new double;
    *pointer = xpointer;
    for (int i = 0; i < numberInStatic; i++)
        staticArray[i] = xstaticArray;
    dynamicArray = new long int[numberInDynamic];
    for (int i = 0; i < numberInDynamic; i++)
        dynamicArray[i] = xdynamicArray;
}
//-------------------------------------------------------------------------------------------------------------------------------
TMyClass::TMyClass(const TMyClass& object)
{
    numberInDynamic = object.numberInDynamic;
    object1 = object.object1;
    pointer = new double;
    *pointer = *object.pointer;
    for (int i = 0; i < numberInStatic; i++)
        staticArray[i] = object.staticArray[i];
    dynamicArray = new long int[numberInDynamic];
    for (int i = 0; i < numberInDynamic; i++)
        dynamicArray[i] = object.dynamicArray[i];
}
//-------------------------------------------------------------------------------------------------------------------------------
TMyClass::~TMyClass()
{
    delete pointer;
    delete[] dynamicArray;
}
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
// реализации методов
void TMyClass::input()
{
    delete[] dynamicArray;
    std::cout << "введите кол-во эл-тов в динам. массиве:" << std::endl;
    do
    {
        if ((std::cin >> numberInDynamic).good() && numberInDynamic > 0)
        {
            dynamicArray = new long int[numberInDynamic];
        }
        else
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cout << "ошибка! введите числовое значение" << std::endl;
            }
            else std::cout << "ошибка! введите положительное число" << std::endl;
        std::cin.ignore(100, '\n');
    } while (!(numberInDynamic > 0 && std::cin.good()));

    for (int i = 0; i < numberInDynamic; i++)
    {
        std::cout << "введите эл-т " << i << std::endl;
        while ((std::cin >> dynamicArray[i]).fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "ошибка! введите числовое значение для " << i << std::endl;
        }
    }

    std::cout << "введите значение object1 типа double:" << std::endl;
    while ((std::cin >> object1).fail())
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "ошибка! введите числовое значение" << std::endl;
    }

    std::cout << "введите значение pointer типа double:" << std::endl;
    while ((std::cin >> *pointer).fail())
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "ошибка! введите числовое значение" << std::endl;
    }

    std::cout << "введите значения staticArray:" << std::endl;
    for (int i = 0; i < numberInStatic; i++)
    {
        std::cout << "введите эл-т " << i << std::endl;
        std::cin >> staticArray[i];
    }
}
//-------------------------------------------------------------------------------------------------------------------------------
void TMyClass::output()
{
    std::cout << "кол-во эл-тов в динам. массиве:" << numberInDynamic << std::endl;
    std::cout << "динамический массив:" << std::endl;
    for (int i = 0; i < numberInDynamic; i++)
        std::cout << dynamicArray[i] << " ";
    std::cout << std::endl;
    std::cout << "значение object1:" << object1 << std::endl;
    std::cout << "значение по адресу pointer:" << *pointer << std::endl;
    std::cout << "staticArray:" << staticArray << std::endl;
    for (int i = 0; i < numberInStatic; i++)
        std::cout << staticArray[i] << " ";
    std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------------------------------------
double TMyClass::fff()
{
    double sum = 0;
    int count = 0;
    for (int i = 0; i < numberInDynamic; i++)
    {
        if (dynamicArray[i] < 0)
        {
            sum += (double)dynamicArray[i];
            count++;
        }
    }
    if (count == 0) return 0;
    else return sum / count;
}
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
void finput(TMyClass& object)
{
    delete[] object.dynamicArray;
    std::cout << "введите кол-во эл-тов в динам. массиве:" << std::endl;
    do
    {
        if ((std::cin >> object.numberInDynamic).good() && object.numberInDynamic > 0)
        {
            object.dynamicArray = new long int[object.numberInDynamic];
        }
        else if (std::cin.fail())
        {
            std::cin.clear();
            std::cout << "ошибка! введите числовое значение" << std::endl;
        }
        else std::cout << "ошибка! введите положительное число" << std::endl;
        std::cin.ignore(100, '\n');
    } while (!(object.numberInDynamic > 0 && std::cin.good()));

    for (int i = 0; i < object.numberInDynamic; i++)
    {
        std::cout << "введите эл-т " << i << std::endl;
        while ((std::cin >> object.dynamicArray[i]).fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "ошибка! введите числовое значение для " << i << std::endl;
        }
    }

    std::cout << "введите значение object1 типа double:" << std::endl;
    while ((std::cin >> object.object1).fail())
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "ошибка! введите числовое значение" << std::endl;
    }

    std::cout << "введите значение pointer типа double:" << std::endl;
    while ((std::cin >> *object.pointer).fail())
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "ошибка! введите числовое значение" << std::endl;
    }

    std::cout << "введите значения staticArray:" << std::endl;
    for (int i = 0; i < numberInStatic; i++)
    {
        std::cout << "введите эл-т " << i << std::endl;
        std::cin >> object.staticArray[i];
    }
}
//-------------------------------------------------------------------------------------------------------------------------------
// ДОЧЕРНИЙ КЛАСС
//-------------------------------------------------------------------------------------------------------------------------------
class TChild: public TMyClass
{
    double objectChild;
    double* pointerChild;

public:
    void output();

    TChild(int xnumberInDynamic = 5, double xobject1 = 1, double xpointer = 0.789, char xstaticArray = 'w', 
        long int xdynamicArray = 0, double xobjectChild = 1.222, double xpointerChild = 0.111);
    TChild(const TChild& object);
    ~TChild();
};
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
TChild::TChild(int xnumberInDynamic, double xobject1, double xpointer, char xstaticArray, 
    long int xdynamicArray, double xobjectChild, double xpointerChild):TMyClass(xnumberInDynamic, xobject1, xpointer, xstaticArray, xdynamicArray)
{
    objectChild = xobjectChild;
    pointerChild = new double;
    *pointerChild = xpointerChild;
}
//-------------------------------------------------------------------------------------------------------------------------------
TChild::TChild(const TChild& object):TMyClass(object)
{
    objectChild = object.objectChild;
    pointerChild = new double;
    *pointerChild = *object.pointerChild;
}
//-------------------------------------------------------------------------------------------------------------------------------
TChild::~TChild()
{
    delete pointerChild;
}
//-------------------------------------------------------------------------------------------------------------------------------
// МЕТОДЫ ДОЧЕРНЕГО
//-------------------------------------------------------------------------------------------------------------------------------
void TChild::output()
{
    TMyClass::output();
    std::cout << "Специфические поля: " << std::endl;
    std::cout << "значение objectChild:" << objectChild << std::endl;
    std::cout << "значение по адресу pointerChild:" << *pointerChild << std::endl;
}
//-------------------------------------------------------------------------------------------------------------------------------


int main()
{
    setlocale(LC_ALL, "Russian");


    TMyClass a;
    a.output();
    std::cout << std::endl;

    TMyClass b(a);
    b.output();
    std::cout << std::endl;

    TMyClass* pc = new TMyClass;
    pc->output();
    std::cout << std::endl;

    std::cout <<  std::endl;
    std::cout << "ДОЧЕРНИЙ КЛАСС" << std::endl;
    std::cout << std::endl;

    TChild aChild;
    aChild.output();
    std::cout << std::endl;

    TChild bChild(aChild);
    finput(bChild);
    bChild.output();
    std::cout << std::endl;

    TChild* pChild = new TChild;
    finput(*pChild);
    pChild->output();
    std::cout << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
