#pragma once
#include <iostream>
using namespace std;

namespace myList {
	template <typename T>
	class Node {
	public:
		T info;
		Node* next;
		Node(T value) { info = value; next = nullptr; }
		void show()const {
			cout << "Info: " << info << endl;
			cout << "\t next: " << next << endl;
		}
	};
	template <typename TypeList>
	class List {
		Node<TypeList>* head;
		Node<TypeList>* tail;
	public:
		List()
		{
			head = tail = nullptr;
		}
		~List()
		{

		}
		void push_back(TypeList value)
		{
			Node<TypeList>* el = new Node<TypeList>(value);
			if (head == nullptr)
			{
				head = tail = el;
			}
			else {//if elements exist in list
				tail->next = el;
				tail = el;
			}
		}
		void show()const {
			Node<TypeList>* p = head;
			while (p != nullptr)
			{
				cout << "Item: " << p << endl;
				p->show();
				cout << endl;
				p = p->next;
			}
		}
	};
}