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
	Node<T> *right;
	Node<T> *left;
	T data;
	Node(T data, Node<T> *left, Node<T> *right) : data(data),left(left),right(right) {}
};

} // end namespace kirthi
#endif

// --------------- END OF NODE CLASS----------------

#ifndef bst_h
#define bst_h

namespace kirthi
{
	
template <class T>
class bst {
private:
	int _size;
	Node<T> *root;
	void insertHelper(const T &data, Node<T>* &current);
	void print(Node<T>* &current);
	bool searchHelper(const T &data, Node<T>* &current);
	T min(Node<T>* &current);
	void remove(const T &data, Node<T>* &current);
	void clearHelper(Node<T>* &current);
public:
	bst();
	~bst();
	T min();
	void insert(const T &data);
	void remove(const T &data);
	bool search(const T &data);
	int size();
	void clear();
	void print();
};
} // namespace kirthi

#include "bst.cpp" // to resolve template class. included inside kirthi namespace

#endif