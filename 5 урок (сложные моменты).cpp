#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;

template <typename IT>
void unilist(IT begin, IT end)
{
    set<string>Uword;
    copy(begin, end, inserter(Uword, Uword.begin()));
    cout << endl;
    for (auto iter = Uword.begin(); iter != Uword.end(); iter++)
    {
        cout << *iter << " ";
    }
}



int main()
{
    cout << "The first task" << endl;
    cout << "=============================================================================" << endl;
    vector <string> multistr = {"hello", "what", "tony", "soprano", 
                            "buddy", "apple", "crocodile", "hello", "apple", "banana",
                            "cowboy", "house", "vector", "house", "banana", "soprano"};
    sort(multistr.begin(), multistr.end());
    unilist(multistr.begin(), multistr.end());

    list<string> list(multistr.begin(), multistr.end());
    unilist(list.begin(), list.end());

    deque<string> d(list.begin(), list.end());
    unilist(d.begin(), d.end());
    cout << endl << "=============================================================================" << endl;
    cout << "The second task" << endl;
    cout << "=============================================================================" << endl;

    string text;
    getline(cin, text);
    multimap <size_t, string> sentences;
    string ends = ".!?";
    string temp;
    for (auto iter = text.begin(); iter != text.end(); iter++)
    {
        auto find = find_first_of(iter, text.end(), ends.begin(), ends.end());
        if (find != text.end())
        {
            auto Sbegin = distance(text.begin(), iter);
            auto Send = distance (text.begin(), find);
            temp = text.substr(Sbegin, Send - Sbegin + 1);
            iter = find;
            if (temp[0] == ' ')
            {
                temp = temp.substr(1);
            }
            sentences.emplace(temp.size(), temp);   
        }
    };
    cout << endl << "Sorted sentences are: " << endl;
    for (const auto& n : sentences)
    {
        cout << n.second << endl;
    }
    return 0;
}