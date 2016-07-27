/* 
	@author Kirthivaasan Puniamurthy
*/

// -------------- NODE CLASS -----------------------
#ifndef node_h
#define node_h

namespace kirthi {

template<class T>
class Node {
public:
	Node<T> *next;
	T data;
	Node(T data, Node<T> *next) : data(data) , next(next) {}
};

} // end namespace kirthi
#endif

// --------------- END OF NODE CLASS----------------

#ifndef list_h
#define list_h

namespace kirthi
{
	
template <class T>
class list {
private:
	int _size;
	Node<T> *head;
public:
	list();
	~list();
	void push_front(T data);
	void insert(T data, int index);
	void remove(int index);
	int size();
	void print();
};

#include "list.cpp" // to resolve template class. included inside kirthi namespace

} // namespace kirthi
#endif