// lab6.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

const int elements = 10;

void staticArrayInput(int array[elements])
{
    for (int i = 0; i < elements; i++)
    {
        std::cout << "введите элемент № " << i << std::endl;
        std::cin >> array[i];
    }
}
//------------------------------------------------------------------------------------------------------------------------------

void staticArrayOutput(int array[elements], int count = 0)
{
    std::cout << "массив: " << std::endl;
    for (int i = 0; i < elements - count; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
//------------------------------------------------------------------------------------------------------------------------------


void inputProcessing(int array[elements])
{
    int count = 0;
    
    for (int i = 0; i < elements - count; i++)
    {
        //int temp = 0;
        for (int j = i + 1; j < elements; j++)
        {
            
            if (array[i] == array[j])
            {
                count++;
                for (int k = j; k < elements; k++)
                {
                    array[k] = array[k + 1];
                }
                /*array[j] = array[j + 1];
                //count++;
                temp++;*/
                j--;
            }
            //else temp = 0;
        }
        /*
        if (temp >= 1)
        {
            i -= temp;
            count++;
        }    */
        
    }
    staticArrayOutput(array, count);
}
//------------------------------------------------------------------------------------------------------------------------------


int main()
{
    setlocale(LC_ALL, "Russian");


    std::cout << "МАССИВ 1" << std::endl;
    int array1[elements];
    staticArrayInput(array1);
    staticArrayOutput(array1);
    inputProcessing(array1);

    std::cout << "МАССИВ 2" << std::endl;
    int array2[elements];
    staticArrayInput(array2);
    staticArrayOutput(array2);
    inputProcessing(array2);

    std::cout << "МАССИВ 3" << std::endl;
    int array3[elements];
    staticArrayInput(array3);
    staticArrayOutput(array3);
    inputProcessing(array3);


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
