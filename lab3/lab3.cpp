// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class TMyCl
{
    int x;
    float a, b, c;
    double m, n;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    double* pd, * ppd;  pd = new double;
    float* pf, * ppf;   pf = new float;
    int* pi, * ppi;     pi = new int;
    TMyCl* po;          po = new TMyCl;

    std::cout << "ЭТАП А. Определение количества памяти, занимаемой ук-лями на пременные разного типа" << std::endl;
    std::cout << "Результат операции sizeof - px, *px, type*, type " << std::endl;

    std::cout << "double: " << sizeof(pd) << " " << sizeof(*pd) << " " << sizeof(double*) << " " << sizeof(double) << std::endl;
    std::cout << "float: " << sizeof(pf) << " " << sizeof(*pf) << " " << sizeof(float*) << " " << sizeof(float) << std::endl;
    std::cout << "int: " << sizeof(pi) << " " << sizeof(*pi) << " " << sizeof(int*) << " " << sizeof(int) << std::endl;
    std::cout << "TMyCl: " << sizeof(po) << " " << sizeof(*po) << " " << sizeof(TMyCl*) << " " << sizeof(TMyCl) << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "ЭТАП B. Операция разименования указателя" << std::endl;
    std::cout << "(определение значения, хранящегося в ОП по заданному адресу)" << std::endl;

    *pd = 0.00001; *pf = 7.6; *pi = 10;

    std::cout << "Указатель: адрес в ОП и значение - px, *px" << std::endl;

    std::cout << "double: " << pd << " " << *pd << std::endl;
    std::cout << "float: " << pf << " " << *pf << std::endl;
    std::cout << "int: " << pi << " " << *pi << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "ЭТАП C. Присваивание значения ранее инициализированного указателя другому указателю" << std::endl;

    ppd = pd; ppf = pf; ppi = pi;

    std::cout << "Указатель: адрес в ОП и значение - ppx, *ppx" << std::endl;
    std::cout << "double: " << ppd << " " << *ppd << std::endl;
    std::cout << "float: " << ppf << " " << *ppf << std::endl;
    std::cout << "int: " << ppi << " " << *ppi << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "ЭТАП D. Освобождение памяти и обнуление указателей" << std::endl;

    delete pd, pf, pi;
    pd = NULL; pf = NULL; pi = NULL; ppf = NULL; ppi = NULL; ppd = NULL;

    std::cout << "Освобождение памяти - px, ppx" << std::endl;

    std::cout << "Указатель: адрес в ОП и значение - ppx, *ppx" << std::endl;
    std::cout << "double: " << pd << " " << ppd << std::endl;
    std::cout << "float: " << pf << " " << ppf << std::endl;
    std::cout << "int: " << pi << " " << ppi << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "Нажмите любую клавишу для продолжения" << std::endl; system("pause");

    std::cout << "ЭТАП E. Определение адреса, по которому хранится переменная (операция взятия адреса)" << std::endl;
    double d = 141.3908, dd;
    float f = -5.986, ff;
    int i = 273, ii;

    std::cout << "Переменная, её значение и адрес в ОП - x, &x" << std::endl;
    std::cout << "double: " << d << " " << &d << std::endl;
    std::cout << "float: " << f << " " << &f << std::endl;
    std::cout << "int: " << i << " " << &i << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "ЭТАП F. Присваивание указателю адреса, по которому хранится некоторая переменная" << std::endl;
    pd = &d; pf = &f; pi = &i;

    std::cout << "Указатель: адрес в ОП и значение - px, *px" << std::endl;
    std::cout << "double: " << pd << " " << *pd << std::endl;
    std::cout << "float: " << pf << " " << *pf << std::endl;
    std::cout << "int: " << pi << " " << *pi << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "ЭТАП G. Присваивание переменной значения, хранящегося в области памяти, с которой связан указатель" << std::endl;
    dd = *pd; ff = *pf; ii = *pi;

    std::cout << "Переменная, её значение и адрес в ОП - xx, &xx" << std::endl;
    std::cout << "double: " << dd << " " << &dd << std::endl;
    std::cout << "float: " << ff << " " << &ff << std::endl;
    std::cout << "int: " << ii << " " << &ii << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;


    std::cout << "ЭТАП H. НЕЛЬЗЯ ЗАПИСЫВАТЬ ЧТО-ЛИБО В НЕВЫДЕЛЕННУЮ ПАМЯТЬ!!!!!!!!!!!" << std::endl;

    double z = 5.9, * px;
    // *px = 54;
     // px = new double; *px = 54;     std::cout << px << " " << *px << std::endl;
    // *px = z;
     px = new double; *px = z;      std::cout << px <<  " " << *px <<  " " << &z << " " << z << std::endl;

    system("pause");


    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "ЭТАП I. Арифметические операции при работе с указателями" << std::endl;

    float* r = new float;

    std::cout << "r равно " << r << std::endl;
    r++;
    std::cout << "r++ равно " << r << std::endl;

    double* dx = new double;
    std::cout << "d равно  " << dx << std::endl;
    dx += 5;
    std::cout << "d+=5 равно  " << dx << std::endl;

    float* a, * b;
    a = new float; b = a;
    std::cout << "a равно  " << a << "b равно: "<< b << std::endl;
    b = a - 3;
    std::cout << "a равно  " << a << "b= a - 3 равно: " << b << std::endl;

    system("pause");


    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

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
