#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <list>
#include <array>
#include <cmath>
#include <ctime>
#include <numeric>

using namespace std;

//template<typename U>
//void insert_sorted_vector(vector <U>& vec, U n)
//{
//    sort(vec.begin(), vec.end());
//    for (auto iter = 0; iter < vec.size(); iter++)
//    {
//        if (vec[iter] > n)
//        {
//            vec.insert(vec.begin() + iter, n);
//            break;
//        }
//    }
//}

template <class Container, typename T>
void insert_sorted(Container &cont, T n)
{
    typename Container::iterator up = upper_bound(cont.begin(), cont.end(), n);
    cont.insert(up, n);
}

int main()
{
    
    cout << "The first task" << endl;
    cout << "===============================================================================" << endl;
    vector<int> v{ 90, 87, 12, -8, 43, 78, 0, 56 ,-123, 87643, 54, -78923 };
    insert_sorted(v, 55);
    copy(v.begin(), v.end(), ostream_iterator <int> {cout, " "});
    cout << endl;
    
    list <int> l{ 4, -5, 2319, -4324234, 0, 3, 7, 19 };
    l.sort();
    insert_sorted(l, 2);
    copy(l.begin(), l.end(), ostream_iterator <int> {cout, " "});
    cout << endl;
    deque<int> d{ 0, 100, 43, -321, -4, 5 };
    sort(d.begin(), d.end());
    insert_sorted(d, 2);
    copy(d.begin(), d.end(), ostream_iterator <int> {cout, " "});
    cout << endl;
    cout << "===============================================================================" << endl;
    cout << "The second task" << endl;
    cout << "===============================================================================" << endl;

    srand(time(NULL));
    vector <double> a (100);
    generate(a.begin(), a.end(), []() {return static_cast<double> (rand() % 10000) / 10; });
    
    vector <int> b(100);
    copy(a.begin(), a.end(), b.begin());
    

    cout << "The first analog vector: ";
    copy(a.begin(), a.end(), ostream_iterator <double> {cout, " "});
    cout << endl;
    cout << endl <<  "The second digital vector:";
    copy(b.begin(), b.end(), ostream_iterator <double> {cout, " "});
    cout << endl;

    vector<double> e(100);
    auto sum = [](double i, double j)
    {
        return pow((i - j), 2);
    };
    transform(a.begin(), a.end(), b.begin(), back_inserter(e), sum);
    cout << "Your mistake between analog and digital signals is: " << accumulate(begin(e), end(e), decltype(e)::value_type(0.0)) << endl;
    return 0;
}