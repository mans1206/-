#include <iostream>
#include <vector>
#include <algorithm>
#include "Timer.h"
#include <fstream>
#include <string_view>




// The first task
template <typename T>
void Swap(T* a, T* b)
{
    T tmp = *a;
    T tmp2 = *b;
    *b = tmp;
    *a = tmp2;
    // Первоначально я пытался написать данную функцию простейшим способом swap:
    //T* tmp = b;
    //b = a;
    //a = tmp;
    // Данный способ отработал без заминок в функции main, однако в шаблонной функции такой способ не работал. Она просто не выполнялась,
    // разыменованные указатели всегда указывали на одно и то же значение. Затем я попробовал данный способ и заработало. Честно говоря, 
    // я не совсем понимаю, почему этот способ заработал, а предыдущий - нет. Очевидно, что тут дело в областях видимости, но я не понимаю
    // логики. Объясните, пожалуйста, в комментарии к дз, если вам не трудно(( я потратил удивительно много времени на это задание

}



//The second task

template <typename T>
void SortPointers (std::vector<T*> pvec)
{
    std::sort(pvec.begin(), pvec.end(), [](int* a, int* b) -> bool {return *a < *b; });
    // Данный алгоритм, как в случае с предыдущим заданием, прекрасно себя показал в функции main, однако в шаблонной функции он отказывается
    // выполняться. Я так и не возьму в толк, почему это происходит. Прошу разъяснить решение в комментарии.
}


void printPVec(std::vector<int*> pvec)
{
    std::vector<int*>::iterator iter;
    {
        for (iter = pvec.begin(); iter != pvec.end(); iter++)
        {
            std::cout << *(*iter) << " " ;
        }
        std::cout << std::endl;
    }
}

bool comp (char a)
{
    if (a == 'a')
    // При указании такого условия, функция count_if, по сути, выводит количество символов в строке. Любых символов. 
    // Надеюсь на ваше терпение и понимание, но я не улавливаю, почему не выполняется простейшее условие.
    // Надеюсь на то, что вы покажете решение данной задачи
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
     std::cout << " The first task" << std::endl;
     std::cout << "====================================================================" << std::endl;
     int test1 = 25;
     int test2 = 37;

     int* ptr1 = &test1;
     int* ptr2 = &test2;
     std::cout << "*ptr1: "<< *ptr1 << '\n' << "*ptr2: "<< * ptr2 << std::endl;

     std::cout << "--------------------------------------------------------------------" << std::endl;
     std::cout << "Swapped" << std::endl;
     std::cout << "--------------------------------------------------------------------" << std::endl;

     Swap(ptr1, ptr2);

     std::cout << "*ptr1: " << *ptr1 << '\n' << "*ptr2: " << *ptr2 << std::endl;

     std::cout << "====================================================================" << std::endl;
     std::cout << " The second task" << std::endl;
     std::cout << "====================================================================" << std::endl;

     int a1 = 1;
     int* p1 = &a1;
     int a2 = 2;
     int* p2 = &a2;
     int a3 = 3;
     int* p3 = &a3;
     int a4 = 4;
     int* p4 = &a4;
     int a5 = 5;
     int* p5 = &a5;

     std::vector<int*> pvec;
     pvec.push_back(p5);
     pvec.push_back(p2);
     pvec.push_back(p4);
     pvec.push_back(p3);
     pvec.push_back(p1);

     printPVec(pvec);
     SortPointers(pvec);
     std::cout << "Sorted" << std::endl;
     std::sort(pvec.begin(), pvec.end(), [](int* a, int* b) -> bool {return *a < *b; });
     // Прописал лямбда-функцию здесь дополнительно, чтобы доказать, что я действительно опробовал данный способ.
     printPVec(pvec);

     std::cout << "====================================================================" << std::endl;
     std::cout << " The third task" << std::endl;
     std::cout << "====================================================================" << std::endl;

     ifstream fin;
     Timer timer;
     fin.open("war and peace.txt");
     /*timer.start("with cout_if");
     size_t count2 = 0;
     while (!fin.eof())
        {
             string buf;
             getline(fin, buf);
             count2 += count_if(buf.begin(), buf.end(), comp);
            
        }
     fin.close();
     timer.print();
     cout << "The number is: " << count2 << endl;*/
     //===================================================================================
     /*timer.start("with find");
     size_t count = 0;
     while (!fin.eof())
     {
         string buf;
         getline(fin, buf);
         buf.find('a');
         buf.find('o');
         buf.find('u');
         buf.find('i');
         buf.find('e');
         buf.find('y');
         if (buf.find('a') != string::npos)
         {
             count++;
         }
         else if (buf.find('o') != string::npos)
         {
             count++;
         }
         else if (buf.find('u') != string::npos)
         {
             count++;
         }
         else if (buf.find('i') != string::npos)
         {
             count++;
         }
         else if (buf.find('e') != string::npos)
         {
             count++;
         }
         else if (buf.find('y') != string::npos)
         {
             count++;
         }
     }
     fin.close();
     timer.print();
     cout << "The number is: " << count << endl;*/

     //===================================================================================
     //Огромная просьба показать решение данных заданий, потому что кажется, что решение или сама идея выполнения
     // задания довольно проста, но увы, неуловима на данном этапе обучения, учитывая, что я - новичок в данной сфере.
     return 0;

}

