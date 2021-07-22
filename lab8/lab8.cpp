// lab8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
1) Определить класс TMyClass, задав поля согласно варианту (см. таблицу 1). Размер статического массива - 5-6 элементов. Предусмотреть
в определении класса конструктор по умолчанию, конструктор копии, деструктор, а также функции-члены класса: ввода, вывода и fff.
2) Прописать реализации конструкторов, деструктора и функций-членов класса. Метод ввода должн давать возможность вводить с клавиатуры занчения для
всех полей, вклчая количество элементов в динамиическом массиве. Метод выводы должен предусматривать  отображение на экране всех полей класса с
соответствующими пояснениями (имена выводимых полей). Метод fff - см. таблицу 1.
3) Добавить в определение клсса прототип внешней дружественной функции ввода значений с клавиатуры. Прописать её реализацию.
4) составить программу (функцию main), в которой создать объекты класса указанные в таблице 2. Объекты a и b созаются как обычные переменные,
px и py - посредством указателей. Обеспечить инициалилзацию объектов класса способами, указанными в индивидуальном задании (см. таблицу 2). Значения
полей должны отражать их тип.
5) обеспечить вывод на экран значений полей всех созданных объектов класса.
6) вызвать для каждого объекта метод fff
7) отладить и сохранить!

данные из таблицы 1:
переменна double, указатель double, статический массив char, динамический массив long int, метод класса fff возвращает среднее арифметическое
отрицательных элементов в динамическом массиве

данные из таблицы 2:
px - конструктор по умолчанию
a - функция ввода-член класса
py - внешняя функция ввода
b(a) - конструктор копии (оригинал)
*/

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
    TMyClass(const TMyClass & object);
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
   // strcpy(staticArray, xstaticArray);
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
//-------------------------------------------------------------------------------------------------------------------------------

int main()
{
    setlocale(LC_ALL, "Russian");

    TMyClass* px = new TMyClass;
    px->output();
    std::cout << px->fff() << std::endl;

    TMyClass* py = new TMyClass;
    finput(*py);
    py->output();
    std::cout << "среднее арифм. отриц. чисел в динам. массиве: " << py->fff() << std::endl;
    
    TMyClass a;
    a.input();
    a.output();
    std::cout << "среднее арифм. отриц. чисел в динам. массиве: " << a.fff() << std::endl;

    TMyClass b(a);
    b.output();
    std::cout << "среднее арифм. отриц. чисел в динам. массиве: " << b.fff() << std::endl;
    
    delete px;
    delete py;
    system("pause");
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
