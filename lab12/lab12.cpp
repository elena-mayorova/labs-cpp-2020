// lab12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <iomanip>

class TProduct
{
    friend class TList;
    std::string name;
    int price;
    int numberOfItems;
    TProduct* next;
public:
    TProduct();
};
//---------------------------------------------------------------------------------------------------------
TProduct::TProduct()
{
    next = NULL;
}
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
class TList
{
    TProduct* first;
    TProduct* current;
    int numberOfProducts;
public:
    TList();
    void create();
    void print();
    void deleteFirst();
    void deleteLast();
    void printExpensive();
    void deleteList();
};
//---------------------------------------------------------------------------------------------------------
TList::TList()
{
    first = current = NULL;
    numberOfProducts = 0;
}
//---------------------------------------------------------------------------------------------------------
void TList::create()
{
    std::cout << "СОЗДАНИЕ СПИСКА" << std::endl;
    if (numberOfProducts > 0)
    {
        std::cout << "Список уже есть, ну алё" << std::endl;
        return;
    }
    std::string currentName;
    int currentPrice;
    int currentNumberOfItems;
    TProduct* last;
    last = first;

    int count;
    std::cout << "Введите количество товаров для ввода: " << std::endl;
    std::cin >> count;
    if (count > 0)
    {
        do {
            std::cout << "Имя товара: ";
            std::cin >> currentName;
            std::cout << "Цена товара: ";
            std::cin >> currentPrice;
            std::cout << "Количество товара: ";
            std::cin >> currentNumberOfItems;

            current = last;
            last = new TProduct;
            numberOfProducts++;
            last->name = currentName;
            last->price = currentPrice;
            last->numberOfItems = currentNumberOfItems;
            last->next = NULL;
            if (numberOfProducts == 1) first = last;
            else current->next = last;

            count--;
        } while (count != 0);
    }
    else {
        std::cout << "Значение не может быть меньше или равно 0, список не создан" << std::endl;
        return;
    }
    std::cout << "Список создан! УРАААААААА" << std::endl;
}
//---------------------------------------------------------------------------------------------------------
void TList::print()
{
    std::cout << "ПЕЧАТЬ СПИСКА" << std::endl;
    if (numberOfProducts == 0)
    {
        std::cout << "Списка нет ещё, ну алё" << std::endl;
        return;
    }
    current = first;
    while (current->next != NULL)
    {
        std::cout << std::setw(20) << "Имя товара: " << current->name << std::endl;
        std::cout << std::setw(20) << "Цена товара: " << current->price << std::endl;
        std::cout << std::setw(20) << "Количество товара: " << current->numberOfItems << std::endl;
        std::cout << std::endl;
        current = current->next;
    }
    std::cout << std::setw(20) << "Имя товара: " << current->name << std::endl;
    std::cout << std::setw(20) << "Цена товара: " << current->price << std::endl;
    std::cout << std::setw(20) << "Количество товара: " << current->numberOfItems << std::endl;
    std::cout << std::endl;

}
//---------------------------------------------------------------------------------------------------------
void TList::deleteFirst()
{
    std::cout << "УДАЛЕНИЕ ПЕРВОГО ЭЛЕМЕНТА СПИСКА" << std::endl;
    if (numberOfProducts == 0)
    {
        std::cout << "Списка нет ещё, так что и удалять нечего" << std::endl;
        return;
    }
    TProduct* deleteProduct;
    deleteProduct = first;
    current = first;
    first = current->next;
    deleteProduct = NULL;
    delete deleteProduct;
    numberOfProducts--;
    std::cout << "Первый товар удален!" << std::endl;
    std::cout << "Число оставшихся товаров: " << numberOfProducts << std::endl;
}
//---------------------------------------------------------------------------------------------------------
void TList::deleteLast()
{
    std::cout << "УДАЛЕНИЕ ПОСЛЕДНЕГО ЭЛЕМЕНТА СПИСКА" << std::endl;
    if (numberOfProducts == 0)
    {
        std::cout << "Списка нет ещё, так что и удалять нечего" << std::endl;
        return;
    }
    TProduct* last;
    last = first;
    current = first;
    while (last->next != NULL)
    {
        current = last;
        // std::cout << "Цикл работает" << std::endl;
        last = current->next;
    }

    // std::cout << "Имя товара current: " << current->name << std::endl;
    // std::cout << "Имя товара last: " << last->name << std::endl;

    // last = NULL;
    // numberOfProducts--;
    current->next = NULL;
    delete last;
    numberOfProducts--;
    std::cout << "Последний товар удален!" << std::endl;
    std::cout << "Число оставшихся товаров: " << numberOfProducts << std::endl;
}
//---------------------------------------------------------------------------------------------------------
void TList::printExpensive()
{
    std::cout << "ИНФОРМАЦИЯ О ТОВАРАХ, СТОИМОСТЬ КОТОРЫХ ВЫШЕ СРЕДНЕЙ" << std::endl;
    if (numberOfProducts == 0)
    {
        std::cout << "Списка нет ещё, ну алё" << std::endl;
        return;
    }
    int sum = 0;
    current = first;
    while (current->next != NULL)
    {
        sum += current->price;
        current = current->next;
    }
    sum += current->price;
    double average = (double)sum / (double)numberOfProducts;
    std::cout << std::setw(20) << "Средняя цена: " << average << std::endl;
    std::cout << std::endl;

    current = first;

    while (current->next != NULL)
    {
        if (current->price > average)
        {
            std::cout << std::setw(20) << "Имя товара: " << current->name << std::endl;
            std::cout << std::setw(20) << "Цена товара: " << current->price << std::endl;
            std::cout << std::setw(20) << "Количество товара: " << current->numberOfItems << std::endl;
            std::cout <<  std::endl;
        }
        
        current = current->next;
    }
    if (current->price > average)
    {
        std::cout << std::setw(20) << "Имя товара: " << current->name << std::endl;
        std::cout << std::setw(20) << "Цена товара: " << current->price << std::endl;
        std::cout << std::setw(20) << "Количество товара: " << current->numberOfItems << std::endl;
        std::cout << std::endl;
    }

}
//---------------------------------------------------------------------------------------------------------
void TList::deleteList()
{
    std::cout << "УДАЛЕНИЕ СПИСКА, ОСВОБОЖДЕНИЕ ПАМЯТИ" << std::endl;
    
    if (numberOfProducts == 0)
    {
        std::cout << "Списка нет ещё, ну алё" << std::endl;
        return;
    }
    current = first;
    TProduct* deleteProduct;
    deleteProduct = first;
    while (current->next != NULL)
    {
        current = first;
        deleteProduct = first;
        first = current->next;
        deleteProduct = NULL;
        delete deleteProduct;
        numberOfProducts--;
    }
    current = first;
    deleteProduct = first;
    first = NULL;
    deleteProduct = NULL;
    delete deleteProduct;
    if (numberOfProducts > 0) numberOfProducts--;
    //numberOfProducts--;
    //current = first;
    //first = current->next;
    //current = NULL;
    //delete first;
    //numberOfProducts--;
    std::cout << "Число оставшихся товаров: " << numberOfProducts << std::endl;
    std::cout << "Товары удалены! надеюсь" << std::endl;
}
//---------------------------------------------------------------------------------------------------------


int main()
{
    setlocale(LC_ALL, "Russian");
    TList myList;

    int n;

    do {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1 - создать список" << std::endl;
        std::cout << "2 - напечатать список" << std::endl;
        std::cout << "3 - удалить первый элемент списка" << std::endl;
        std::cout << "4 - удалить последний элемент списка" << std::endl;
        std::cout << "5 - напечатать информацию о товарах, стоимость которых выше средней" << std::endl;
        std::cout << "6 - удалить список" << std::endl;

        std::cout << "0 - выход из меню" << std::endl;

        std::cin >> n;

        switch (n)
        {
        case 1: myList.create(); break;
        case 2: myList.print(); break;
        case 3: myList.deleteFirst(); break;
        case 4: myList.deleteLast(); break;
        case 5: myList.printExpensive(); break;
        case 6: myList.deleteList(); break;

        default: if (n!=0) std::cout << "Некорректный ввод" << std::endl;
            break;
        }

    } while (n!=0);
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
