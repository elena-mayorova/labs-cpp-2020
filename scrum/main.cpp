#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <limits>

using namespace std;

// Класс Физические лица
class Individual
{
    string _firstname;           // имя
    string _surname;             // фамилия
    string _patronymic;          // отчество
    string _dateOfBirth;         // дата рождения
    string _phoneNumber;         // номер телефона
    string _email;               // е-почта
    string _comment;             // комментарий

public:
    void input();                // Метод ввода
    void output();               // Метод вывода
    void getName();

    string search();             // Метод для поиска по строке, возвращает значение поиска

    Individual(
            string firstname   = "Oleg",
            string surname     = "Vasilev",
            string patronymic  = "Petrovich",
            string dateOfBirth = "01.01.2020",
            string phoneNumber = "89234567890",
            string email       = "eample@expale.example",
            string comment     = "comment"
    );
    ~Individual();
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// реализация конструктора и методов Физических лиц

Individual::
    Individual(
        string firstname,
        string surname,
        string patronymic,
        string dateOfBirth,
        string phoneNumber,
        string email,
        string comment
    ) {
        _firstname   = firstname;
        _surname     = surname;
        _patronymic  = patronymic;
        _dateOfBirth = dateOfBirth;
        _phoneNumber = phoneNumber;
        _email       = email;
        _comment     = comment;
    }

Individual::~Individual()
{

}

void Individual::input()
{
    cout << "Введите имя: ";
    cin >> _firstname;

    cout << "Введите фамилию: ";
    cin >> _surname;

    cout << "Введите отчество: ";
    cin >> _patronymic;

    cout << "Введите дату рождения: ";
    cin >> _dateOfBirth;

    cout << "Введите телефон: ";
    cin >> _phoneNumber;

    cout << "Введите email (опционально, для пропуска введите '-'): ";
    cin >> _email;

    cout << "Введите комментарий (опционально, для пропуска введите '-'): ";
    cin >> _comment;

    cout << endl;
    cout << "Запись добавлена!" << endl;
}

void Individual::getName()
{
    cout << _surname << " " << _firstname << " " << _patronymic << endl;
}

void Individual::output()
{
    cout << "           Имя: " << _firstname << endl;
    cout << "       Фамилия: " << _surname << endl;
    cout << "      Отчество: " << _patronymic << endl;
    cout << " Дата рождения: " << _dateOfBirth << endl;

    cout << "Номер телефона: " << _phoneNumber << endl;
    cout << "         Email: " << _email << endl;

    cout << "   Комментарий: " << _comment << endl;
}

string Individual::search()
{
    return _firstname + _surname + _patronymic;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Класс Экстренные службы
class Emergency
{
    string _phoneNumber;
    string _name;
    string _purpose;

public:
    void input();
    void output();
    void getName();

    string search();             // Метод для поиска по строке, возвращает значение поиска

    Emergency(
            string phoneNumber = "89674883654",
            string name        = "prikol",
            string purpose     = "primer"
    );
    ~Emergency();
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// реализация конструктора и методов Экстренных служб

Emergency::
    Emergency(
        string phoneNumber,
        string name,
        string purpose
    ) {
        _phoneNumber = phoneNumber;
        _name        = name;
        _purpose     = purpose;
    }

//string get_purpose(string _purpose)
//{
//    return _purpose;
//}

void Emergency::input()
{
    cout << "Введите название экстренной службы: ";
    cin >> _name;
    cout << "Введите номер телефона: ";
    cin >> _phoneNumber;
    cout << "Введите назначение службы: ";
    cin >> _purpose;

    cout << endl;
    cout << "Запись добавлена!" << endl;
}

void Emergency::output()
{
    cout << "Название экстренной службы: " << _name << endl;
    cout << "            Номер телефона: " << _phoneNumber << endl;
    cout << "                Назначение: " << _purpose << endl;
}

Emergency::~Emergency()
{

}

void Emergency::getName()
{
    cout << _name << endl;
}

string Emergency::search()
{
    return _purpose;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Класс Юридические лица
class Entity
{

    string _name;
    string _number;
    string _email;
    string _schedule; // время работы
    string _comment;

public:
    void input();
    void output();
    void getName();

    string search();             // Метод для поиска по строке, возвращает значение поиска

    Entity(
            string name     = "Trol",
            string number   = "89164588554",
            string email    = "laky@mail.ru",
            string schedule = "8:00 - 18:00",
            string comment  = "***"
    );
    ~Entity();
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// реализация конструктора и методов Юридических лиц

Entity::
    Entity(
        string name,
        string number,
        string email,
        string schedule,
        string comment
    ) {
        _name     = name;
        _number   = number;
        _email    = email;
        _schedule = schedule;
        _comment  = comment;
    }

Entity::~Entity()
{

}

void  Entity::input()
{
    cout << "Введите название: ";
    cin >> _name;
    cout << "Введите номер телефона: ";
    cin >> _number;
    cout << "Введите почту (опционально, для пропуска введите '-'): ";
    cin >> _email;
    cout << "Введите график работы: ";
    cin >> _schedule;
    cout << "Введите примечание: ";
    cin >> _comment;
}
//-----------------------------------------------
void  Entity::output()
{
    cout << "      Название: " << _name << endl;
    cout << "Номер телефона: " << _number << endl;
    cout << "         Email: " << _email << endl;
    cout << " График работы: " << _schedule << endl;
    cout << "    Примечание: " << _comment << endl;
}

void Entity::getName()
{
    cout << _name << endl;
}

string Entity::search()
{
    return _name;
}

int main()
{
    setlocale (LC_ALL,"RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Обявление векторов для каждого класса
    vector<Individual> Individual_list{Individual("Сергей","Плотников", "Олегович", "01.01.2001", "+7(923)456-78-90", "example@email.com", "комментарий")};
    Individual_list.emplace_back("Арина","Педа", "Сергеевна", "19.05.2001", "+7(923)456-78-90", "example@email.com", "комментарий");
    Individual_list.emplace_back("Анжелика","Басова", "Валерьевна", "01.09.2001", "+7(923)456-78-90", "example@email.com", "комментарий");
    Individual_list.emplace_back("Алексей","Торбин", "Какойтович", "26.11.2001", "+7(923)456-78-90", "example@email.com", "комментарий");

    vector<Entity> Entity_list{Entity("ФГБОУ ВО ГУУ",  "8(495)377-89-14", "info@guu.ru", "09:00 - 18:00", "Лучший вуз страны")};
    Entity_list.emplace_back("Самсунг",  "8(555)555-35-35", "info@samsung.com", "02:00 - 18:00", "примечение");
    Entity_list.emplace_back("ИИС",  "8(495)377-89-14", "iis@guu.ru", "03:00 - 18:00", "Это Выхино, это ЮВАО, это наш ГУУ, любим мы его");

    vector<Emergency> Emergency_list{Emergency("+7(923)456-78-90", "Коменда", "Угнетать")};
    Emergency_list.emplace_back("+7(923)456-78-90", "Охранник", "Ох рано встает охрана");
    Emergency_list.emplace_back("+7(923)456-78-90", "МедКабинет", "Чипирует");


    do {
        cout << "1)   Физические лица - введите 'f'" << endl;
        cout << "2)  Юридические лица - введите 'y'" << endl;
        cout << "3) Экстренные службы - введите 'e'" << endl;
        cout << "введите 'q' для выхода" << endl;
        cout << "Введите букву: ";
        char case_input;
        cin >> case_input;
        system("cls");
        switch ( case_input ) {
            case 'f': {
                do {
                    cout << "  Просмотр записей - введите 'w'" << endl;
                    cout << "    Поиск контакта - введите 's'" << endl;
                    cout << " Добавление записи - введите 'a'" << endl;
                    cout << "Вернуться к списку - введите 'l'" << endl;
                    cin >> case_input;
                    system("cls");
                    switch (case_input) {
                        case 'w': {
                            for (int i = 0; i < Individual_list.size(); i++) {
                                cout << i + 1 << ") ";
                                Individual_list[i].getName();
                            }
                            cout << endl;
                            cout << "Введите номер записи, которую хотите просмотреть" << endl;
                            int record;
                            cin >> record;
                            system("cls");
                            Individual_list[record - 1].output();
                            cout << endl;
                            cout << "Введите 'b', чтобы вернуться назад" << endl;
                            cin >> case_input;
                            system("cls");
                            if (case_input == 'b')
                                break;
                        }
                        case 's': {
                            string search_firstname;
                            string search_secondname;
                            string search_patronymic;
                            cout << "введите имя: ";
                            cin >> search_firstname;
                            cout << "введите фамилию: ";
                            cin >> search_secondname;
                            cout << "введите отчество: ";
                            cin >> search_patronymic;

                            int count = 0;
                            for (int i = 0; i < Individual_list.size(); i++) {
                                if (search_firstname + search_secondname + search_patronymic == Individual_list[i].search()) {
                                    cout << "Номер записи: " << i + 1 << endl;
                                    Individual_list[i].output();
                                } else {
                                    count++;
                                }
                            }
                            if (count == Individual_list.size()) {
                                cout << "Нет совпадений";
                            }
                            cout << endl;
                            cout << "Введите 'b', чтобы вернуться назад" << endl;
                            cin >> case_input;
                            system("cls");
                            if (case_input == 'b')
                                break;
                        }
                        case 'a': {
                            Individual input;
                            input.input();
                            Individual_list.emplace_back(input);
                            cout << endl;
                            cout << "Введите 'b', чтобы вернуться назад" << endl;
                            cin >> case_input;
                            system("cls");
                            if (case_input == 'b')
                                break;
                        }
                        case 'l': {
                            break;
                        }
                        default:
                            cout << "Неверное значение ввода" << endl;
                            break;
                    }
                    if (case_input == 'l') {
                        system("cls");
                        break;
                    }
                } while (true);
                break;
            }
            case 'y': {
                do {
                    cout << "  Просмотр записей - введите 'w'" << endl;
                    cout << "    Поиск контакта - введите 's'" << endl;
                    cout << " Добавление записи - введите 'a'" << endl;
                    cout << "Вернуться к списку - введите 'l'" << endl;
                    cin >>  case_input;
                    system("cls");
                    switch (case_input) {
                        case 'w': {
                            for (int i = 0; i < Entity_list.size(); i++) {
                                cout << i + 1 << ") ";
                                Entity_list[i].getName();
                            }
                            cout << endl;
                            cout << "Введите номер записи, которую хотите просмотреть" << endl;
                            int record;
                            cin >> record;
                            system("cls");
                            Entity_list[record - 1].output();
                            cout << endl;
                            cout << "Введите 'b', чтобы вернуться назад" << endl;
                            cin >> case_input;
                            system("cls");
                            if (case_input == 'b')
                                break;
                        }
                        case 's': {
                            string search_name;
                            cout << "введите имя: ";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(cin, search_name);

                            int count = 0;
                            for (int i = 0; i < Entity_list.size(); i++) {
                                if (search_name == Entity_list[i].search()) {
                                    cout << "Номер записи: " << i + 1 << endl;
                                    Entity_list[i].output();
                                } else {
                                    count++;
                                }
                            }
                            if (count == Entity_list.size()) {
                                cout << "Нет совпадений";
                            }
                            cout << endl;
                            cout << "Введите 'b', чтобы вернуться назад" << endl;
                            cin >> case_input;
                            system("cls");
                            if (case_input == 'b')
                                break;
                        }
                        case 'a':{
                            Entity input;
                            input.input();
                            Entity_list.emplace_back(input);
                            cout << endl;
                            cout << "Введите 'b', чтобы вернуться назад" << endl;
                            cin >> case_input;
                            system("cls");
                            if (case_input == 'b')
                                break;
                        }
                        case 'l': {
                            break;
                        }
                        default:
                            cout << "Неверное значение ввода" << endl;
                            break;
                    }
                    if (case_input == 'l') {
                        system("cls");
                        break;
                    }
                } while (true);
                break;
            }
            case 'e': {
                do {
                    cout << "  Просмотр записей - введите 'w'" << endl;
                    cout << "    Поиск контакта - введите 's'" << endl;
                    cout << " Добавление записи - введите 'a'" << endl;
                    cout << "Вернуться к списку - введите 'l'" << endl;
                    cin >>  case_input;
                    system("cls");
                    switch (case_input) {
                        case 'w': {
                            for (int i = 0; i < Emergency_list.size(); i++) {
                                cout << i + 1 << ") ";
                                Emergency_list[i].getName();
                            }
                            cout << endl;
                            cout << "Введите номер записи, которую хотите просмотреть" << endl;
                            int record;
                            cin >> record;
                            system("cls");
                            Emergency_list[record - 1].output();
                            cout << endl;
                            cout << "Введите 'b', чтобы вернуться назад" << endl;
                            cin >> case_input;
                            system("cls");
                            if (case_input == 'b')
                                break;
                        }
                        case 's': {
                            string search_purpose;
                            cout << "Введите назначение службы: ";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(cin, search_purpose);

                            int count = 0;
                            for (int i = 0; i < Emergency_list.size(); i++) {
                                if (search_purpose == Emergency_list[i].search()) {
                                    cout << "Номер записи: " << i + 1 << endl;
                                    Emergency_list[i].output();
                                } else {
                                    count++;
                                }
                            }
                            if (count == Emergency_list.size()) {
                                cout << "Нет совпадений";
                            }
                            cout << endl;
                            cout << "Введите 'b', чтобы вернуться назад" << endl;
                            cin >> case_input;
                            system("cls");
                            if (case_input == 'b')
                                break;
                        }
                        case 'a':{
                            Emergency input;
                            input.input();
                            Emergency_list.emplace_back(input);
                            cout << endl;
                            cout << "Введите 'b', чтобы вернуться назад" << endl;
                            cin >> case_input;
                            system("cls");
                            if (case_input == 'b')
                                break;
                        }
                        case 'l': {
                            break;
                        }
                        default:
                            cout << "Неверное значение ввода" << endl;
                            break;
                    }
                    if (case_input == 'l') {
                        system("cls");
                        break;
                    }
                } while (true);
                break;
            }
            case 'q': {
                cout << "До встречи!" << endl;
                exit(0);
            }
            default:
                cout << "Неверное значение ввода" << endl;
                break;
        }
    } while (true);
}