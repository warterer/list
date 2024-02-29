#pragma once
#include <iostream>
using namespace std;
namespace MyList {
	template <typename T>
	class DNode {
	public:
		T info;
		DNode* prev;
		DNode* next;

		DNode(T value) { info = value; next = prev = nullptr; }
		void show()const {
			cout << "Info: " << info << endl;
			cout << "\tPrev: " << prev << endl;
			cout << "\tNext: " << next << endl;
		}
	};
	template <typename TypeList>
	class DList {
		DNode<TypeList>* head;
		DNode<TypeList>* tail;
	public:
		DList() { head = nullptr;  tail = nullptr; }
		~DList() {
			DNode<TypeList>* p = head;
			DNode<TypeList>* tmp = head;

			while (p != nullptr)
			{
				tmp = p;
				p = p->next;
				cout << "Delete: " << tmp->info << endl;
				delete tmp;
			}
		}
		void push_back(TypeList value) {
			DNode<TypeList>* el = new DNode<TypeList>(value);
			if (head == nullptr)
			{
				head = tail = el;
			}
			else {
				tail->next = el;
				el->prev = tail;

				tail = el;
			}
		}
		void show()const {
			DNode<TypeList>* p = head;
			while (p != nullptr)
			{
				p->show();
				p = p->next;
			}
		}
		void show_reverse()const {
			DNode<TypeList>* p = tail;
			while (p != nullptr)
			{
				p->show();
				p = p->prev;
			}
		}
		DNode<TypeList>* search(TypeList item) {
			DNode<TypeList>* p = head;
			while (p != nullptr)
			{
				if (p->info == item)
				{
					return p;
				}
				p = p->next;
			}
			return nullptr;
		}
		void push_front(TypeList value) {
			DNode<TypeList>* el = new DNode<TypeList>(value);
			if (head == nullptr) 
			{
				head = tail = el;
			}
			else 
			{
				el->next = head;
				head->prev = el;
				head = el;
			}
		}
		void insertBefore(TypeList before, TypeList value) {
			DNode<TypeList>* el = new DNode<TypeList>(value);
			DNode<TypeList>* p = search(before);
			if (p != nullptr) 
			{
				if (p->prev == nullptr) 
				{
					el->next = head;
					head->prev = el;
					head = el;
				}
				else 
				{
					el->prev = p->prev;
					el->next = p;
					p->prev->next = el;
					p->prev = el;
				}
			}
		}
		void insertAfter(TypeList after, TypeList value) {
			DNode<TypeList>* el = new DNode<TypeList>(value);
			DNode<TypeList>* p = search(after);
			if (p != nullptr) 
			{
				el->prev = p;
				el->next = p->next;
				if (p->next == nullptr) 
				{
					tail = el;
				}
				else 
				{
					p->next->prev = el;
				}
				p->next = el;
			}
		}
		void erase(TypeList value) {
			DNode<TypeList>* p = search(value);
			if (p != nullptr) 
			{
				if (p->prev != nullptr)
				{
					p->prev->next = p->next;
				}
				else 
				{
					head = p->next;
					if (head != nullptr) 
					{
						head->prev = nullptr;
					}
				}
				if (p->next != nullptr) 
				{
					p->next->prev = p->prev;
				}
				else 
				{
					tail = p->prev;
					if (tail != nullptr) 
					{
						tail->next = nullptr;
					}
				}
				delete p;
			}
		}
	};

}