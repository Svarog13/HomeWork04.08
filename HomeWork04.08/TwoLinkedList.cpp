#include<iostream>

template<typename T>
class DoublyLinkedList
{
private:
	class Node 
	{
	public:
		Node* next;
		Node* prev;
		T value;

		Node(T value, Node* next = nullptr, Node* prev = nullptr) : value{ value }, next{ next }, prev{ prev }{}
	};
	Node* head;
	Node* tail;
	int size;

public:
	DoublyLinkedList() : size{ 0 }, head{ nullptr },tail{nullptr}{}

	~DoublyLinkedList()
	{
		DeleteAll();
	}

	void AddToHead(T value)
	{
		Node* newNode = new Node(value, head, nullptr);
		if (head)
		{
			head->prev = newNode;
		}
		else
		{
			tail = newNode;
		}
		head = newNode;
		size++;
	}
	void AddToTail(T value)
	{
		Node* newNode = new Node(value, nullptr, tail);
		if (tail)
		{
			tail->next = newNode;
		}
		else
		{
			head = newNode;
		}
		tail = newNode;
		size++;
	}
	void DeleteFromHead()
	{
		if (head!=nullptr)
		{
			Node* current = head;
			head = head->next;
		}
		if (head == nullptr)
		{
			tail == nullptr;
		}
		else
		{
			head->prev = nullptr;
		}
		delete current;
		size--;
	}
	void DeleteFromTail()
	{
		if (tail == nullptr)
		{
			return;
		}
		if (tail ->prev == nullptr)
		{
			delete tail;
			head = nullptr;
			tail = nullptr;
			size--;
			return;
		}
		Node* current = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete current;
		size--;
	}
	void DeleteAll()
	{
		while (head != nullptr)
		{
			Node* current = head;
			head = head->next;
			delete current;
		}
		tail = nullptr;
		size = 0;
	}
	void Show()const
	{
		Node* current = head;
		while (current != nullptr)
		{
			std::cout << current->value << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
};
int main()
{
	DoublyLinkedList<int>list;
	list.AddToTail(1);
	list.AddToTail(2);
	list.AddToTail(3);
	list.AddToTail(4);

	list.Show();

	list.DeleteFromHead();
	list.DeleteFromTail();

	list.Show();

	list.DeleteAll();
	list.Show();

	return 0;
}
//Створіть шаблонний клас двозв’язного списку для роботи з цілими значеннями.Потрібно створити реалізації
//для типових операцій над елементами :
//■ AddToHead — додавання елемента до голови списку;
//■ AddToTail — додавання елемента до хвоста списку;
//■ DeleteFromHead — видалення елемента з голови списку;
//■ DeleteFromTail — видалення елемента з хвоста списку;
//■ DeleteAll — видалення всіх елементів;
//■ Show — виведення всіх елементів списку на екран