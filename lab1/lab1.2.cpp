// lab1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{

    setlocale(LC_ALL, "Russian");
    std::cout << "Часть 2" << std::endl;

    /*

    char c;
    int i;
    float f, rez;
    double d;

    std::cout << "Введите c (char), i (int), f (float), d (double): " << std::endl;
    std::cin >> c >> i >> f >> d;

    std::cout << "Размер выражения c+i: " << sizeof(c + i) << "      ";
    rez = c + i;
    std::cout << "Размер переменно rez: " << sizeof(rez) << std::endl;

    std::cout << "Размер выражения c+i+d: " << sizeof(c + i + d) << "      ";
    rez = c + i + d;
    std::cout << "Размер переменно rez: " << sizeof(rez) << std::endl;

    std::cout << "Размер выражения i*30000: " << sizeof(i * 30000) << std::endl;
    std::cout << "Размер выражения i*70000: " << sizeof(i * 70000) << std::endl;
    std::cout << "Размер выражения i*f: " << sizeof(i * f) << std::endl;
    std::cout << "Размер выражения i*4.5: " << sizeof(i * 4.5) << std::endl;
    std::cout << "Размер выражения c: " << sizeof(c) << std::endl;
    std::cout << "Размер выражения c+c: " << sizeof(c+c) << std::endl;
    */
    /*
    std::cout << std::endl;
    std::cout << "Часть 3" << std::endl;

    int x, y;
    float a, b, c, d;

    std::cout << "Введите x (int), y (int)" << std::endl;
    std::cin >> x >> y;

    a = x / y; std::cout << "a = " << a << std::endl;
    b = float(x) / y; std::cout << "b = " << b << std::endl;
    c = (float) x / y; std::cout << "c = " << c << std::endl;
    d = float (x / y); std::cout << "d = " << d << std::endl; // сначала вычисляем интовые x/y, а потом уже преобр данные к float
    */

    std::cout << "Часть 3" << std::endl;

    double a = 0.99;
    double b = -5;
    float c = 109.55;

    int x = 32767, y = 13, z = 13;

    std::cout << "Задание 4а: " << (a == b) << std::endl; //false 0
    std::cout << "Задание 4б: " << (b < x) << std::endl; // true 1
    std::cout << "Задание 4в: " << (a != 13) << std::endl; // true 1
    std::cout << "Задание 4г: " << (x >= c) << std::endl; //true 1
    std::cout << "Задание 4д: " << (!x) << std::endl; //false 0
    std::cout << "Задание 4е: " << ((x == a) && (c < x)) << std::endl; // false 0
    std::cout << "Задание 4ж: " << ((x >= a) && (b < x)) << std::endl; // true 1
    std::cout << "Задание 4з: " << ((x == a) && (c < x)) << std::endl; // false 0
    std::cout << "Задание 4и: " << ((x >= a)+(b < x)) << std::endl; // 2
    std::cout << "Задание 4к: " << ((x >= a) + (b < x)) << std::endl; // 2
    std::cout << "Задание 4л: " << (x || 0) << std::endl; // 1
    std::cout << "Задание 4м: " << (!x||0) << std::endl; // 0
    std::cout << "Задание 4н: " << (y++) << std::endl; // 13
    std::cout << "Задание 4о: " << (++z) << std::endl; // 14
    std::cout << "Задание 4п: " << y << std::endl; // 14
    std::cout << "Задание 4р: " << z << std::endl; // 14
    std::cout << "Задание 4с: " << (z % 5) << std::endl; // 4
    std::cout << "Задание 4т: " << (5 % z) << std::endl; // 5

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
