// lab5.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    
    // const int n = 12;
    // int array[n] = {6, 8, 1, 3, 4, 2, 5, 9, 3, 6, 7, 9};
   
    int numberOfElements;

    std::cout << "введите кол-во элементов массива: " << std::endl;
    std::cin >> numberOfElements;

    int* array = new int[numberOfElements +1];

    for (int i = 0; i < numberOfElements; i++)
    {
        std::cout << "введите элемент № " << i << std::endl;
        std::cin >> array[i];
    }
    
    std::cout << "введенный массив: " << std::endl;
    for (int i = 0; i < numberOfElements; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    int count = 0;
    
    for (int i = 0; i < numberOfElements - count; i++)
    {
        if (array[i] % 3 == 0)
        {
            count++;
            for (int j = i; j < numberOfElements; j++)
            {
                array[j] = array[j + 1];
            } 
            i--;  
        }
    }

    std::cout << "уплотненный массив:" << std::endl;
    for (int i = 0; i < numberOfElements - count; i++)
    {
        std::cout << array[i] << " ";
    }

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
