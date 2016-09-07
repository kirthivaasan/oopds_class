#include <iostream>
#include <string>
#include <set>
namespace kirthi 
{

template <typename T, typename Z>
hashmap<T, Z>::hashmap() : size(0), capacity(177) {
	// default constructor
	array = new chain_type[capacity];
}

template <typename T, typename Z>
hashmap<T, Z>::hashmap(size_t size) : size(0), capacity(177) {
	array = new chain_type[size + capacity];
}
template <typename T, typename Z>
int hashmap<T, Z>::findHash(int key) {
	return key % capacity; // simple identity + wrap around (modulo) hash function.
}

template <typename T, typename Z>
int hashmap<T, Z>::findHash(std::string key) {
	int total = 0;
	for (int i = 0; i < key.length(); i++) {
		total += (int)key[i];
	}
	return total % capacity;
}
	
template <typename T, typename Z>
void hashmap<T, Z>::insert(const T &key, const Z &value) {
	// 1. create tuple
	std::pair<T, Z> tuple(key, value);
	// 2. calculate hash based on key.
	int hash = findHash(key);
	// 3. Use hash computed as index in array.
	array[hash].insert(tuple);
	//array[hash].insert();
	size++;
}

template <typename T, typename Z>
void hashmap<T, Z>::remove(const T &key) {
	int hash = findHash(key);
	chain_type& collisions = array[hash];
	for (set_iterator it = collisions.begin(); it != collisions.end(); it++) {
		if (it->first == key) {
			collisions.erase(it);
			break;
		}
	}
}

template <typename T, typename Z>
Z hashmap<T, Z>::find(const T &key) {
	int hash = findHash(key);
	chain_type& collisions = array[hash];
	for (set_iterator it = collisions.begin(); it != collisions.end(); it++)
	{
		if (it->first == key) {
			return it->second;
		}
	}
	// should throw KeyNotFoundException error
	throw 98;
}

template <typename T, typename Z>
void hashmap<T, Z>::printSet(chain_type &someset) {
	for (set_iterator it = someset.begin(); it != someset.end(); it++) {
		std::cout << it->first << "\t\t" << it->second << std::endl;
	}
}

template <typename T, typename Z>
void hashmap<T, Z>::print() {
std::cout << "KEYS\t\tVALUES" << std::endl;
std::cout << "====\t\t======" << std::endl;
	for (int i = 0; i < capacity; i++) {
		printSet(array[i]);
	}
}

template <typename T, typename Z>
hashmap<T, Z>::~hashmap() {

}

} // end namespace kirthi