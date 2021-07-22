/*
а). Использование шаблонов функций. Построить шаблон, позволяющий при помощи единой функции определять дробную
часть вводимого с клавиатуры вещественного числа. Продемонстрировать использование
на примерах чисел типа: float, double, long double.
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>


template <class T>
void func(T number, int amount)
{ /*
    int whole = (int)number;
    float remainder = number - whole;
    long long int x = long long int(remainder * 10000000000000000000);
    for (int i = 0; i <= 20; i++)
        if () */

    /*int whole = (int)number;
    int count = 0;*/
    
        /*while (whole != 0)
    {
        whole /= 10;
        count++;
    }*/
    

    /*float temp = number - whole;
    std::cout << temp << std::endl;

    float what = temp;
    int test = 0;
    while (temp > 0.001)
    {
        whole = temp*10;
        std::cout << "temp*10 "<< temp << std::endl;
        count++;
        what = temp;
        test = int(what);
        temp = (float)what - test;
        std::cout << "temp - test " << temp << std::endl;
        //test = (int)temp;
    }
    std::cout << temp << std::endl;*/
    

    /*temp = number - whole;
    int b = (int)temp * pow(10, count);

    char str[20];
    sprintf_s(str, "%d", b);

    std::cout << 0;
    for (int i = 0; i < 20; i++)
        std::cout << str[i];
    std::cout << std::endl;*/


    /*temp = number - whole;
    std::cout << count << std::endl;
    std::cout << std::setprecision(count) << temp;*/
    //int count = 0;
    //std::cout << "number " << std::setprecision(amount) << number << "\n";
    long int whole = (long int)number;
    //std::cout << whole << "\n";
    T temp = number - whole;
   // while (whole != 0)
    //{
  //      whole /= 10;
    //    count++;
  //  }
    
    /* while (number - (int)number > 0.1)
    {
        number *= 10.0;
        std::cout << "number * 10 " << number << "\n";
    }*/
   
    //for (int i =0; i<amount; i++)
   // {
   //     temp *= 10.0;
        //std::cout << "number * 10 " << std::setprecision(amount) << temp << "\n";
   // }
    
    //std::cout << number << "\n";
    //whole = (int)round(temp);
    //std::cout << whole;
    std::cout << "Дробная часть введенного числа = " << std::setprecision(amount) << temp << "\n";
    //std::string s = std::to_string(temp);
    //std::cout << s.length()<<"\n";
    //std::cout<< std::setprecision(20) << s.substr(count);
    //std::cout << s;
}

int main()
{
    //long double n = 0.12345678912345678912345678912345678;
    //std::cout.setf(std::ios::fixed);
    //std::cout << sizeof(long double);

    setlocale(LC_ALL, "Russian");

    float numberf = 12365.133;
    func(numberf, 3);

    double numberd = 657.555555555555;
    func(numberd, 12);

    long double numberl = 10.2387563856123443;
    func(numberl, 16);

    /*int count;
    std::cout << "введите число и количество цифр дробной части\n";
    std::cin >> number >> count;
    func(number, count);*/
    
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
