template <class T>
class LinkedListStack
{
public:
    LinkedListStack();
    ~LinkedListStack();

    void push(const T &data); //入栈
    T peek();
    T pop();
    int size() const;

private:
    int count; //存放栈的大小
    struct LinkedNode
    {
        T data;
        LinkedNode *next;
    };
    LinkedNode *head; //单链表的头指针
};