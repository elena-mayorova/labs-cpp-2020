// lab5.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
Задача коммивояжера. Рекламному агенту фирмы необходимо посетить N городов (не менее 10),
расстояния между которыми известны. Каждый город нужно посетить только один раз. Города представлены номерами.
Маршрут начинается и завершается в короде К. Из еще не посещавшихся городов к качестве следующего агент
выбирает ближайший к тому, где он в данный момент находится. Необходимо напечатать все города маршрута,
протяженность каждого этапа и общуюю длину пути агента. Значения N и К вводятся пользователем с клавиатуры.
Таблицу расстояний между городами вывести на экран; для их задания рекомендуется использовать датчик случайных
чисел. Массивы динамические.
*/

#include <iostream>
#include <iomanip>
#include <ctime>

int main()
{
    setlocale(LC_ALL, "Russian");

    srand((unsigned int)time(0));

    int numberOfCities;
    std::cout << "введите количество городов: \n";
    std::cin >> numberOfCities;

    int start;
    std::cout << "введите номер начального города: \n";
    std::cin >> start;
   
    int** tableOfRoads = new int*[numberOfCities];

    for (int i = 0; i < numberOfCities; i++)
        tableOfRoads[i] = new int[numberOfCities];
    
    for (int i = 0; i < numberOfCities; i++ )
        for (int j = i; j < numberOfCities; j++)
        {
            if (i == j)
            {
                tableOfRoads[i][j] = 0;
            }
            else
            {
                tableOfRoads[i][j] = int((double)rand()/((double)RAND_MAX + 1) * 21 + 1); // случайное число между 1 и 21
                tableOfRoads[j][i] = tableOfRoads[i][j];
            }         
        }
    int* array = new int[numberOfCities];
    for (int i = 0; i < numberOfCities; i++)
        array[i] = tableOfRoads[i][start];
    
    for (int i = 0; i < numberOfCities; i++)
    {
        for (int j = 0; j < numberOfCities; j++)
            std::cout << std::setw(4) << tableOfRoads[i][j];
        std::cout << std::endl;
    }

    int currentCity = start;
    int temp;
    int min = 22;

    int* length = new int[numberOfCities]; // хранение длины маршрута
    int* cities = new int[numberOfCities + 1]; // хранение городов маршрута

    cities[0] = currentCity;
    
    int count = 0;

    while (true)
    {
        for (int j = 0; j < numberOfCities; j++)
        {
            if (tableOfRoads[currentCity][j] < min && tableOfRoads[currentCity][j] != 0)
            {
                min = tableOfRoads[currentCity][j];
                temp = j;
            }
            tableOfRoads[currentCity][j] = 0;
            tableOfRoads[j][currentCity] = 0;
        }

        length[count] = min;
        cities[count + 1] = temp;
        currentCity = temp;
        min = 32768;
        count++;
        
        if (count == numberOfCities - 1) break;
    }

    length[numberOfCities - 1] = array[temp];
    cities[numberOfCities] = start;
    
    std::cout << std::endl;

    std::cout << "маршрут:" << std::endl;

    for (int i = 0; i < numberOfCities + 1; i++)
    {
        std::cout << cities[i] << " ";
    }
    
    std::cout << std::endl;
    std::cout << "длины дорог между городами: " << std::endl;
    for (int i = 0; i < numberOfCities; i++)
    {
        std::cout << length[i] << " ";
    }

    int totalLength = 0;
    for (int i = 0; i < numberOfCities; i++)
    {
        totalLength += length[i];
    }
    std::cout << std::endl;
    std::cout << "пройденный путь: " << totalLength << std::endl;
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
