/* 
	@author Kirthivaasan Puniamurthy
*/

#ifndef vector_h
#define vector_h

namespace kirthi
{
	
template <class T>
class vector {
private:
	int _size;
	int _capacity;
	T *array;
	void expand();
public:
	vector();
	~vector();
	void push_back(T data);
	void pop_back();
	void insert(T data, int pos);
	void remove(int pos);
	void clear();
	int size();
	const T& operator[](int i); // read only cannot modify (const)
};

#include "vector.cpp" // to resolve template class. included inside kirthi namespace

} // namespace kirthi
#endif