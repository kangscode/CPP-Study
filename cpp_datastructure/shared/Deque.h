#pragma once

#include "Queue.h"

#include <cassert>
#include <iostream>
#include <iomanip>

// Double Ended Queue (덱, dequeue와 구분)
template<typename T>
class Deque : public Queue<T>
{

	typedef Queue<T> Base;

public:
	Deque(int capacity)
		: Queue<T>(capacity)
	{
	}

	T& Front()
	{
		return Base::Front();
	}

	T& Back()
	{
		return this->Rear();
	}

	void PushFront(const T& item)
	{
		if (Base::IsFull())
			Base::Resize();

		// TODO: this->queue로도 가능
		Base::queue_[this->front_] = item;
		Base::front_ = (Base::front_ - 1 + Base::capacity_) % Base::capacity_;
	}

	void PushBack(const T& item)
	{
		Base::Enqueue(item);
	}

	void PopFront()
	{
		Base::Dequeue();
	}

	void PopBack()
	{
		assert(!Base::IsEmpty());

		// TODO:
		rear_ = (rear_ - 1 + Base::capacity_) % Base::capacity_;
	}

private:
	// Queue와 동일
	int& rear_ = Base::rear_; // 이렇게 참조연산자로도 가능.
};
