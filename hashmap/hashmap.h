/* 
	@author Kirthivaasan Puniamurthy
*/

#ifndef hashmap_h
#define hashmap_h

#include <set>

namespace kirthi
{
	
template <class T, class Z>
class hashmap {
	typedef typename std::set<std::pair<T, Z> >::iterator set_iterator;
	typedef std::set<std::pair<T, Z> > chain_type;
private:
	chain_type * array;
	size_t size;
	size_t capacity;
	int findHash(int key);
	int findHash(std::string key);
	void printSet(chain_type &someset);
public:
	hashmap();
	hashmap(size_t size);
	~hashmap();
	void insert(const T &key, const Z &value);
	void remove(const T &key);
	Z find(const T &key);
	void print();
	
};
} // namespace kirthi

#include "hashmap.cpp"
#endif