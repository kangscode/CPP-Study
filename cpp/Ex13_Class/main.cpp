#include <iostream>
#include <cstring>

using namespace std;

// public, private 접근 권한 확인

class MyClass
{
public:
    MyClass()
    {
        // 호출 시점 확인
        cout << "MyClass()" << endl;
        cout << "this " << this << endl;
    }

    MyClass(int number)
    {
        cout << "MyClass(int number)" << endl;

        // this pointer 소개
        this->number_ = number;
        cout << "this " << this << endl;
    }

    ~MyClass()
    {
        // 호출 시점 확인
        cout << "~MyClass()" << endl;
    }

    void Increment(int a)
    {
        number_ += a;
    }

    //은닉
    void Print()
    {
        cout << number_ << endl;
    }

private:
    int number_ = 0; // 초기값
};

int main()
{
    MyClass my_class1;
    MyClass my_class2(123);

    cout << &my_class1 << endl;
    cout << &my_class2 << endl;

    my_class1.Print(); // 0 
    my_class2.Print(); //123

    my_class1.Increment(1); 
    my_class1.Print(); // 1

    // 배열 사용 가능
    // 포인터 사용 가능 등 안내
    // 기본 자료형과 비교

    return 0;
}
