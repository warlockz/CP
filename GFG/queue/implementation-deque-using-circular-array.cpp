#include <isotream>
#define MAX 100
using namespace std;


class Dequeue
{
	int arr[MAX];
	int front;
	int rear;
	int size;
public:
	Dequeue(int size)
	{
		front = -1;
		rear = 0;
		this->size =size;;
	}
	void  insertfront(int key);
    void  insertrear(int key);
    void  deletefront();
    void  deleterear();
    bool  isFull();
    bool  isEmpty();
    int  getFront();
    int  getRear();
};

void Dequeue::insertrear(int key)
{


}

void Dequeue::insertfront(int key)
{

	
}

void  Dequeue::deletefront()
{

}

void  Dequeue::deleterear()
{
	
}

bool  Dequeue::isFull()
{

}

bool Dequeue::isEmpty()
{

}

int  Dequeue::getFront()
{

}

int Dequeue::getRear()
{
	
}

int main(int argc, char const *argv[])
{
	
	return 0;
}