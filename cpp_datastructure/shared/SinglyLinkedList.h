#pragma once

#include <cassert>
#include <stdint.h>

template<typename T>
class SinglyLinkedList
{
public:
	struct Node	// 멤버 타입
	{
		T item = T(); // 초기화 버튼
		Node* next = nullptr;
	};

	SinglyLinkedList()
	{
	}

	SinglyLinkedList(const SinglyLinkedList& list)
	{
		// TODO: 연결 리스트 복사
		Node* current = list.first_;
		while (current) {
			PushBack(current->item);
			current = current->next;
		}
	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO: 모두 삭제
		while (first_)
			PopFront();
	}

	bool IsEmpty()
	{
		return (first_ == nullptr);
	}

	int Size()
	{
		int size = 0;

		// TODO: size를 하나하나 세어서 반환
		Node* current = first_;
		while (current) {
			size++;
			current = current->next;
		}

		return size;
	}

	T Front()
	{
		assert(first_);

		return first_->item; // TODO: 수정
	}

	T Back()
	{
		assert(first_);

		Node* current = first_;
		while (current->next) {
			current = current->next;
		}

		return current->item; // TODO: 수정
	}

	Node* Find(T item)
	{
		// TODO: item이 동일한 노드 포인터 반환
		Node* current = first_;

		while(current) {
			if (current->item == item) {
				return current;
			}
			current = current->next;
		}
		return nullptr;
		
	}

	void InsertBack(Node* node, T item)
	{
		// TODO:
		Node* temp = new Node;
		temp->item = item;
		temp->next = node->next;
		node->next = temp;
	}

	void Remove(Node* n)
	{
		assert(first_);

		// 하나 앞의 노드를 찾아야 합니다.
		// TODO:
		if (first_ == n) {
			first_ = first_->next;
			delete n;
			return;
		}

		Node* prev = first_;
		while (prev->next) {

			if (prev->next == n) {
				break;
			}
			prev = prev->next;
		}

		prev->next = n->next;
		delete n;
	}

	void PushFront(T item)
	{
		// first_가 nullptr인 경우와 아닌 경우 나눠서 생각해보기 (결국은 두 경우를 하나로 합칠 수 있음)

		// 새로운 노드 만들기
		// TODO:
		Node* temp = new Node(); // O(1)
		temp->item = item;

		// 연결 관계 정리
		// TODO:
		temp->next = first_;
		first_ = temp;
	}

	void PushBack(T item)
	{

		if (first_)
		{
			// TODO:
			Node* current = first_;
			while(current->next) {
				current = current->next;
			}

			Node* new_Node = new Node();
			new_Node->item = item;

			current->next = new_Node;
		}
		else
		{
			// TODO:
			PushFront(item);
		}
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);

		// TODO: 메모리 삭제
		Node* temp = first_->next;
		delete first_;
		first_ = temp;
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		// 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.
		// 하나 앞의 노드를 찾아야 합니다.
		// TODO:
		if (Size() == 1) {
			delete first_;
			first_ = nullptr;
			return;
		}


		Node* current = first_;
		while(current->next->next != nullptr) {
			current = current->next;
		}

		assert(first_);

		// TODO: 메모리 삭제
		delete current->next;
		current->next = nullptr;
	}

	void Reverse()
	{
		// TODO: 
		if (IsEmpty())
			return;

		Node* current = first_;
		Node* previous = nullptr;
		
		while (current) {
			Node* temp = previous;
			previous = current;
			current = current->next;
			previous->next = temp;
		}
		
		first_ = previous;
	}

	void SetPrintDebug(bool flag)
	{
		print_debug_ = flag;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << " ";

			while (current)
			{
				if (print_debug_)
				{
					//cout << "[" << current << ", " << current->item << ", " << current->next << "]";

					// 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
					cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
						<< current->item << ", "
						<< reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
				}
				else
				{
					cout << current->item;
				}

				if (current->next)
					cout << " -> ";
				else
					cout << " -> NULL";

				current = current->next;
			}
			cout << endl;
		}
	}

protected:
	Node* first_ = nullptr;

	bool print_debug_ = false;
};