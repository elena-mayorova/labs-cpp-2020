// lab6.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>


int input(int min, int max)
{
    int input;
    do
    {
        std::cin >> input;
        if (input >= min && input <= max)
        {
             return input;
        }
        else std::cout << "введено некорректное значение"<< std::endl;
    } while (input < min || input > max);
    
}
//------------------------------------------------------------------------------------------------------------------------------

float inputProcessing(int hours, int minutes)
{
    int totalTime = hours * 60 + minutes;
   
    double result = 720.0 / 11.0 * (floor(totalTime / (720.0 / 11.0)) + 1.0) - totalTime;
    //if ((result - int(result)) > 0.5) return result + 1;
    return result;


    // return (int) 720 / 11 * ((int)(totalTime / (720 / 11)) + 1) - totalTime;
    //return floor(720.0 / 11.0 * (floor(totalTime / (720.0 / 11.0)) + 1.0) - totalTime);
    //return 720.0 / 11.0 * ((floor)(totalTime / (720.0 / 11.0)) + 1.0) - totalTime;
}
//------------------------------------------------------------------------------------------------------------------------------

void output(double time)
{
    std::cout << "Наименьшее время, через которое стрелки на циферблате совпадут (в полных минутах) = " << time << std::endl;
}
//------------------------------------------------------------------------------------------------------------------------------

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите два числа: час (от 0 о 11), минуты (от 0 до 59)" << std::endl;
    int hours = input(0, 11);
    int minutes = input(0, 59);
    output(inputProcessing(hours, minutes));
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
