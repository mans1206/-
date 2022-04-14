#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <deque>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime>
#include <future>

using namespace std;
mutex mut;

class pcout
{

public:

    pcout()
    {}
    lock_guard<mutex> lg { mut };
    template <typename T>
    pcout& operator<< (const T& a)
    {
        cout << a;
        return *this;
    }

};

void print(int number)
{
    pcout() << "Started thread " << number << " in the thread: " << this_thread::get_id() << "\n";
    pcout() << "Thread " << number << " ended" << '\n';
}

bool isSimple(int & num)
{
    int del = 0;
    int i = 1;
    while (i <= num)
    {
        if (num % i == 0)
        {
            del++;
        }
        i++;

        if (del == 3)
        {
            break;
        }
    }
    if (del > 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void getProst(int& num)
{
    
    int count = 0;
    int k = 1;
    deque<int> nums;
    for (int i = 0; i < 10000; i++)
    {
        if (isSimple(k) == true)
        {
            nums.push_back(k);
            count++;
        }
        k++;
    }
    cout << "Second Thread" << endl;
    cout << "Ваше число: " << nums[num - 1] << endl;
    
}

void hostFunc(vector <int> & vec)
{
    //cout << "Host Thread" << endl;
    this_thread::sleep_for(1s);
    srand(time(0));
    vec.push_back(rand() % 1000);
    
}

void thiefFunc(vector <int>& vec)
{
    //cout << "Thief thread" << endl;
    this_thread::sleep_for(500ms);
    int max = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > max)
        {
            max = vec[i];
        }
    }
    auto it = find(vec.begin(), vec.end(), max);
    vec.erase(it);   
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Первое задание" << endl;
    cout << "===========================================================================" << endl;
    thread th1(print, 1);
    thread th2(print, 2);
    thread th3(print, 3);
    th1.join();
    th2.join();
    th3.join();
    cout << "===========================================================================" << endl;
    cout << "Второе задание" << endl;
    cout << "===========================================================================" << endl;
    int num;
    cout << "Main thread" << endl;
    cout << "Введите порядковое число: ";
    cin >> num;
  
    thread prost(getProst, ref(num));
    prost.join();
    cout << "===========================================================================" << endl;
    cout << "Третье задание" << endl;
    cout << "===========================================================================" << endl;

    once_flag callflag;
    vector<int> house {54, 23, 234};
    
    
    while (house.size() > 1)
    {
        /*auto host(async(launch::async, hostFunc, ref(house)));
        auto thief(async(launch::async, thiefFunc, ref(house)));*/
        thread thief(thiefFunc, ref(house));
        thread host(hostFunc, ref(house));
        host.join();
        thief.join();
       
        
        for (auto k : house)
        {
            cout << k << " ";
        }
        cout << endl;

        if (house.size() == 1)
            break;
    }
    

    return 0;

}


