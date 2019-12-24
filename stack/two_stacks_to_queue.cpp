//用两个栈实现一个队列
//采用模板

#include <iostream>
#include <stack>
#include <exception>

using namespace std;

template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    
    // 在队列末尾添加一个结点
    void appendTail(const T& node);

    // 删除队列的头结点
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{

}

template <typename T> CQueue<T>::~CQueue(void)
{

}

template<typename T>
void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);
}

template<typename T>
T CQueue<T>::deleteHead()
{
    if (stack2.size() <= 0)
    {
        while (stack1.size() > 0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if (stack2.size() == 0)
    {
        throw new exception("queue is empty");
    }
    
    T head = stack2.top();
    stack2.pop();

    return head;
}

int main()
{
    CQueue<int> queue;
    queue.appendTail(1);
    queue.appendTail(2);
    cout << queue.deleteHead() << endl;
    queue.appendTail(3);
    queue.appendTail(4);
    cout << queue.deleteHead() << endl;
    cout << queue.deleteHead() << endl;
    cout << queue.deleteHead() << endl;
    queue.appendTail(5);
    cout << queue.deleteHead() << endl;
    
    return 0;
}