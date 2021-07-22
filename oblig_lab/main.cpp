#include <iostream>
#include <string>
#include <limits>

class Harbinger
{
private:
    std::string h_name;
    int         h_age;
    std::string h_catchPhrase;

public:
    Harbinger(std::string name = "", int age = 0, std::string CatchPhrase = "");

    std::string getName() const;
    int         getAge() const;
    std::string getCatchPhrase() const;

    void        setName();
    void        setAge();
    void        setCatchPhrase();
};
//----------------------------------------------------------------------------------------
// Реализация методов и конструктора класса

Harbinger::Harbinger(std::string name, int age, std::string CatchPhrase) {
    h_name        = name;
    h_age         = age;
    h_catchPhrase = CatchPhrase;
}

// геттеры--------------------------------------------------------------------------------
std::string Harbinger::getName() const {
    return h_name;
}

int Harbinger::getAge() const {
    return h_age;
}

std::string Harbinger::getCatchPhrase() const {
    return h_catchPhrase;
}

// сеттеры--------------------------------------------------------------------------------
void Harbinger::setName() {
    std::cout << "Введите имя Предвестника: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, h_name);
}

// ввод возраста с проверкой того, что введено неотрицательное число
void Harbinger::setAge() {

    std::cout << "Введите возраст Предвестника: ";
    do
    {
        if ((std::cin >> h_age).good() && h_age > 0) break;

        else
            if (std::cin.fail()) {
                std::cin.clear();
                std::cout << "Ошибка! введите числовое значение" << std::endl;
                std::cout << "Введите возраст Предвестника: ";
            }
            else {
                std::cout << "Ошибка! Возраст не может быть отрицательным" << std::endl;
                std::cout << "Введите возраст Предвестника: ";
            }

        std::cin.ignore(100, '\n');
    } while (!(h_age > 0 && std::cin.good()));
}

void Harbinger::setCatchPhrase() {
    std::cout << "Введите девиз Предвестника: ";
    getline(std::cin, h_catchPhrase);
}


//----------------------------------------------------------------------------------------
// Первое наследование -------------------------------------------------------------------
class Prophet: public Harbinger
{
    std::string ph_magnumOpus[3];
    std::string ph_name;
    int         ph_age;
    std::string ph_call;

public:

    Prophet(std::string magnumOpus = "11", std::string name = "", int age = 0, std::string call = "");

    std::string* getMagnumOpus();
    std::string  getName() const;
    int          getAge() const;
    std::string  getCall() const;
    int          getIndex(Prophet &object);

    void         setMagnumOpus();
    void         setName();
    void         setAge();
    void         setCall();

};
//----------------------------------------------------------------------------------------
// Реализация методов и конструктора класса

Prophet::Prophet(std::string magnumOpus, std::string name, int age, std::string call) {
    for (auto & ph_magnumOpu : ph_magnumOpus) ph_magnumOpu = magnumOpus;
    ph_name = name;
    ph_age  = age;
    ph_call = call;
}

// геттеры--------------------------------------------------------------------------------
std::string* Prophet::getMagnumOpus() {
    return &ph_magnumOpus[0];
}

std::string Prophet::getName() const {
    return ph_name;
}

int Prophet::getAge() const {
    return ph_age;
}

std::string Prophet::getCall() const {
    return ph_call;
}

int Prophet::getIndex(Prophet &object) {
    object.ph_call = "";
    int index = -1;
    for (int i = 0; i < 3; i++) {
        if (object.ph_magnumOpus[i].length() > object.ph_call.length()) {
            object.ph_call = object.ph_magnumOpus[i];
            index = i;
        }
    }
    return index;
}

// сеттеры--------------------------------------------------------------------------------
void Prophet::setMagnumOpus() {
    std::cout << "Введите Магнум Опус Пророка (3 строки через Enter, не более 25 символов каждая): \n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (auto & ph_magnumOpu : ph_magnumOpus) {
        do {
            // ввод с проверкой на соответствие длине. с киррилицей работает неточно из-за особенностей кодировки
            getline(std::cin, ph_magnumOpu);
            if (ph_magnumOpu.length() > 25) {
                std::cout<<"Ошибка! Строка должна содержать не более 25 символов, повторите попытку:\n";
                ph_magnumOpu.clear();
            }
            else
                break;
        } while (true);
    }
    setCall(); // для автоматической записи в ph_call новой строки из Магнум Опус
}

void Prophet::setName() {
    std::cout << "Введите имя Пророка: ";
    getline(std::cin, ph_name);
}

// ввод возраста с проверкой того, что введено неотрицательное число
void Prophet::setAge() {

    std::cout << "Введите возраст Пророка: ";
    do
    {
        if ((std::cin >> ph_age).good() && ph_age > 0) break;

        else
            if (std::cin.fail()) {
                std::cin.clear();
                std::cout << "Ошибка! введите числовое значение" << std::endl;
                std::cout << "Введите возраст Пророка: ";
            }
            else {
                std::cout << "Ошибка! Возраст не может быть отрицательным" << std::endl;
                std::cout << "Введите возраст Пророка: ";
            }

        std::cin.ignore(100, '\n');
    } while (!(ph_age > 0 && std::cin.good()));
}

void Prophet::setCall() {
    ph_call = "";
    for (auto & ph_magnumOpu : ph_magnumOpus) {
        if (ph_magnumOpu.length() > ph_call.length()) {
            ph_call = ph_magnumOpu;
        }
    }
}


//----------------------------------------------------------------------------------------
// Второе наследование -------------------------------------------------------------------
class DeusEx: public Prophet
{
    std::string gd_name;
    int         gd_year;

public:
    DeusEx(std::string name = "Староста", int year = 2021);

    void story(Prophet &prophetObj, Harbinger &harbingerObj);

    std::string getName();
    int         getYear();
};
//----------------------------------------------------------------------------------------
// Реализация метода и конструктора класса
DeusEx::DeusEx(std::string name, int year) {
    gd_name = name;
    gd_year = year;
}

void DeusEx::story(Prophet &prophetObj, Harbinger &harbingerObj) {
    std::cout << harbingerObj.getName() << " в возрасте " << harbingerObj.getAge()
              << " говорил, что " << harbingerObj.getCatchPhrase() << "." << std::endl;

    std::string* array;
    array = prophetObj.getMagnumOpus();

    // определение индексов двух других элементов массива, которые не самые длинные
    int index = Prophet::getIndex(prophetObj);
    int first = abs(3 - index - 2);

    std::cout << "Первое пророчество: " << array[first] << std::endl;
    std::cout << "Второе пророчество: " << array[3 - index - first] << std::endl;
    std::cout << "Главное пророчество: " << prophetObj.getCall() << std::endl;

    std::cout << "Так говорил " << prophetObj.getName() << " в возрасте " << prophetObj.getAge() << std::endl;

    std::cout << "В год " << gd_year << " пришёл " << gd_name << ", которого предрекали "
              << harbingerObj.getName() << " и " << prophetObj.getName() << std::endl;
}

// геттеры--------------------------------------------------------------------------------
std::string DeusEx::getName() {
    return gd_name;
}

int DeusEx::getYear() {
    return gd_year;
}

//----------------------------------------------------------------------------------------
// Последнее наследование -------------------------------------------------------------------
class Believer: private DeusEx
{
    std::string bv_name;
    int         bv_age;

public:
    Believer(std::string name, int age);

    void pray(Believer &believerObj, Prophet &prophetObj, DeusEx &deusExObj);
};
//----------------------------------------------------------------------------------------
// Реализация метода и конструктора класса
Believer::Believer(std::string name, int age) {
    bv_name = name;
    bv_age  = age;
}

void Believer::pray(Believer &believerObj, Prophet &prophetObj, DeusEx &deusExObj) {
    std::cout << "Верующий " << believerObj.bv_name << " молится " << deusExObj.getName() << " именем "
              << prophetObj.getName() << ". C " << deusExObj.getYear() << " и по сей день." << std::endl;
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
int main() {
//  проверка работоспособности Harbinger
    Harbinger a;
    a.setAge();
    a.setName();
    a.setCatchPhrase();
    std::cout << a.getName() << std::endl;
    std::cout << a.getAge() << std::endl;
    std::cout << a.getCatchPhrase() << std::endl;


//  проверка работоспособности Prophet
    Prophet b;
    b.setName();
    b.setAge();
    b.setMagnumOpus();

    std::string* array;
    array = b.getMagnumOpus();

    std::cout << "Вывод всего Магнум опус:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << array[i] << std::endl;
    }
    std::cout << "\n";

    std::cout << "ph_call: ";
    std::cout << b.getCall() << std::endl;

    std::cout << "\n";

//    b.setMagnumOpus();
//    std::cout << "новый ph_call после переопределение Магнум Опус: ";
//    std::cout << b.getCall() << std::endl;

//  проверка работоспособности DeusEx
    DeusEx c;
    c.story(b, a);

    std::cout << "\n";

//  проверка работоспособности Believer
    Believer d("Верующий", 20);
    d.pray(d, b, c);

    delete[] array;
}