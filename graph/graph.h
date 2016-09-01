/* 

	@author Kirthivaasan Puniamurthy
*/

#ifndef graph_h
#define graph_h

#include <vector>
#include <map>
#include <set>

namespace kirthi
{
	
template <class T>
class graph {
	typedef typename std::map<T, std::set<T> >::iterator map_iterator;
	typedef typename std::set<T>::iterator set_iterator;
private:
	std::map<T, std::set<T> > adj_vec;
	int _size;
public:
	graph();
	~graph();
	T min();
	void addNode(const T &u);
	void addEdge(const T &u, const T &v);
	void removeEdge(const T &u, const T &v);
	void removeNode(const T &u);
	bool isConnected(const T &u, const T &v);
	void print();
};
} // namespace kirthi

#include "graph.cpp" // to resolve template class. included inside kirthi namespace

#endif