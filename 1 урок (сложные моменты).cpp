#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <tuple>
#include <iomanip>
#include <optional>
#include <vector>
#include <algorithm>
using namespace std;

//Первое задание
//==============================================================================================================
struct Person
{
    string name;
    string surname;
    optional <string> patron;
};
ostream& operator << (ostream& out, const Person& a)
{
    out << a.surname << "\t";
    out << a.name;
    if (a.patron.has_value())
    {
        out << "\t" << a.patron.value() << '\t';
    }
    return out;
}
bool operator < (const Person& p1, const Person& p2)
{
    return tie(p1.surname, p1.name, p1.patron) < tie(p2.surname, p2.name, p2.patron);
}
bool operator == (const Person& p1, const Person& p2)
{
    return tie(p1.surname, p1.name, p1.patron) == tie(p2.surname, p2.name, p2.patron);
}

//Второе задание
//==============================================================================================================

struct PhoneNumber
{
    int country;
    int city;
    string number;
    optional <int> dopnum;
};

 ostream& operator << (ostream& o, const PhoneNumber& b)
{
    o << "+" << b.country << "(" << b.city << ")" << b.number;
    if (b.dopnum.has_value())
    {
        o << " " << b.dopnum.value();
    }
    return o;
}
 bool operator < (const PhoneNumber& n1, const PhoneNumber& n2)
{
    return tie(n1.country, n1.city, n1.number, n1.dopnum) < tie(n2.country, n2.city, n2.number, n2.dopnum);
}
 bool operator == (const PhoneNumber& n1, const PhoneNumber& n2)
{
    return tie(n1.country, n1.city, n1.number, n1.dopnum) == tie(n2.country, n2.city, n2.number, n2.dopnum);
}

//Третье задание
//==============================================================================================================

class PhoneBook
{
private:
    vector<pair<Person, PhoneNumber>> Num_Base;

public:
    PhoneBook(ifstream& fin)
    {
        const size_t Substr = 7;
        string row;
        while (!fin.eof())
        {
            getline(fin, row, '\n');
            vector<string> Rows;
            size_t start = 0;
            for (size_t i = 0; i < Substr; i++)
            {
                size_t del = row.find(',', start);
                string subrow = row.substr(start, del - start);
                if (subrow.empty())
                {
                    subrow = "";
                }
                Rows.push_back(subrow);
                start = del + 1;
            }

            Person rPers;
            rPers.surname = Rows[0];
            rPers.name = Rows[1];
            rPers.patron = Rows[2];

            PhoneNumber phone;
            phone.country = stoi(Rows[3]);
            phone.city = stoi(Rows[4]);
            phone.number = Rows[5];

            stringstream m;
            int addnum;
            m << Rows[6];
            m >> addnum;
            if (addnum < 0)
            {
                phone.dopnum = nullopt;
            }
            else
            {
                phone.dopnum = addnum;
            }
            this->Num_Base.push_back(pair<Person, PhoneNumber>(rPers, phone));
        }
    }


    friend ostream& operator<< (ostream& out, const PhoneBook& pb)
    {
        out << endl;
        for (size_t i = 0; i < pb.Num_Base.size(); i++)
        {
            Person pers = pb.Num_Base[i].first;
            PhoneNumber num = pb.Num_Base[i].second;
            
            out << pers;
            out << num << endl;
            
        }
        out << endl;
        return out;
    }
    void SortByName()
    {
        sort(Num_Base.begin(), Num_Base.end(), [](const pair<Person, PhoneNumber> p1, const pair<Person, PhoneNumber> p2)
            {return p1.first < p2.first; });
    }
    void SortByPhone()
    {
        sort(Num_Base.begin(), Num_Base.end(), [](const pair<Person, PhoneNumber> p1, const pair<Person, PhoneNumber> p2)
        {return p1.second < p2.second; });
    }

    tuple <string, PhoneNumber> GetPhoneNumber(string find)
    {
        size_t count = 0;
        string soobsh;
        PhoneNumber numb;
        for (const auto& [name, number] : Num_Base)
        {
            if (name.surname == find)
            {
                count++;
                numb = number;
            }
        }
        if (count == 1)
        {
            soobsh.clear();
        }
        else if (count > 1)
        {
            soobsh = "Found more than 1";
        }
        else
        {
            soobsh = "Not found";
        }
        return { soobsh, numb };
    }

    void ChangePhoneNumber(Person find, PhoneNumber numb)
    {
        for (auto& [name, number] : Num_Base)
        {
            if (name == find)
            {
                number = numb;
            }
           
        }
    }
    
};


int main()
{
    ifstream file;
    file.open("Phonebook1.txt");
    PhoneBook book(file);
    cout << book;
    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;
    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;
    cout << "-----GetPhoneNumber-----" << endl;

    auto print_phone_number = [&book](const string& surname) 
    {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;
    };

    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
        PhoneNumber{ 7, 123, "15344458", nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
        PhoneNumber{ 16, 465, "9155448", 13 });
    cout << book;

    return 0;
}

