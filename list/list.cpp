#include <iostream>
#include <list>
#include <algorithm>
#include "List.h"
#include "DList.h"
using namespace std;
bool isNeg(int a)
{
    return a < 0;
}
int main()
{
    /*myList::Node<int> first(34);
    myList::Node<int> second(17);
    first.next = &second;
    myList::Node<int> third(24);
    second.next = &third;
    myList::Node<int> fourth(1);
    third.next = &fourth;
    myList::Node<int>* p = &first;
    while (p != nullptr)
    {
        cout << "Item: " << p << "\n";
        p->show();
        cout << endl;
        p = p->next;
    }
    return 0;*/
    /*myList::List<int> p22;
    p22.push_back(8);
    p22.push_back(911);
    p22.push_back(1488);
    p22.push_back(21);
    p22.show();*/
    /*MyList::DNode<int> first(34);
    MyList::DNode<int> second(17);
    MyList::DNode<int> third(24);
    MyList::DNode<int> fourth(1);
    first.next = &second;
    second.prev = &first;

    second.next = &third;
    third.prev = &second;

    third.next = &fourth;
    fourth.prev = &third;
    MyList::DNode<int>* p = &first;
    cout << "1)\n";
    while (p != nullptr)
    {
        cout << "Item: " << p << "\n";
        p->show();
        cout << endl;
        p = p->next;
    }
    cout << "2)\n";
    MyList::DNode<int>* p2 = &fourth;
    while (p2 != nullptr)
    {
        cout << "Item: " << p2 << "\n";
        p2->show();
        cout << endl;
        p2 = p2->prev;
    }*/
    /*MyList::DList<int> p22;
    p22.push_back(8);
    p22.push_back(911);
    p22.push_back(1488);
    p22.push_back(21);
    //p22.show();
    cout << "----------------\n";
    //p22.show_reverse();

    if (p22.search(-12) == nullptr)
    {
        cout << "-12 is not found\n";
    }
    if (p22.search(21) != nullptr)
    {
        p22.search(21)->show();
    }*/
    list<int> p22;
    p22.push_back(8);
    p22.push_back(911);
    p22.push_back(-1488);
    p22.push_back(21);
    for (int& item : p22)
    {
        cout << item << " ";
    }
    cout << endl;
    for (auto item : p22)
    {
        cout << item << " ";
    }
    cout << endl;
    cout << "================================\n";
    list<int>::iterator p;
    for (p = p22.begin(); p != p22.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
    cout << "================================\n";
    cout << "Max: " << *max_element(p22.begin(), p22.end()) << endl;
    cout << "Min: " << *min_element(p22.begin(), p22.end()) << endl;
    cout << "================================\n";
    replace_if(p22.begin(), p22.end(), isNeg, 0);
    for (p = p22.begin(); p != p22.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
    cout << "================================\n";
    int max = *max_element(p22.begin(), p22.end());
    for (p = p22.begin(); p != p22.end(); p++)
    {
        *p += max;
        cout << *p << " ";
    }
    cout << endl;
    cout << "================================\n";
    int k = 932;
    for (p = p22.begin(); p != p22.end(); p++)
    {
        if (*p == k)
        {
            p22.erase(p);
            break;
        }
        cout << *p << " ";
    }
    cout << endl;
    cout << "================================\n";
    int after = 1822;
    int n = 222;
    for (p = p22.begin(); p != p22.end(); p++)
    {
        if (*p == after)
        {
            p22.insert(p, n);
            break;
        }
    }
    for (p = p22.begin(); p != p22.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
    cout << "================================\n";
}
