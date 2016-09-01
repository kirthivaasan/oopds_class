#include <iostream>
#include <set>

namespace kirthi {
	
template <typename T>
graph<T>::graph() : _size(0) {

}

template <typename T>
void graph<T>::removeNode(const T &u) {
	map_iterator it = adj_vec.find(u);
	if (it != adj_vec.end())
		adj_vec.erase(it);
}

template <typename T>
void graph<T>::removeEdge(const T &u, const T &v) {
	map_iterator it = adj_vec.find(u);
	if (it != adj_vec.end()) {
		set_iterator v_it = it->second.find(v);
		if (v_it != it->second.end())
			it->second.erase(v_it);
	}
}

template <typename T>
void graph<T>::addEdge(const T &u, const T &v) {
	map_iterator it = adj_vec.find(u);
	if (it == adj_vec.end()) {
		std::set<T> someset;
		someset.insert(v);
		adj_vec.insert(std::pair<T, std::set<T> >(u, someset));
	} else {
		it->second.insert(v);
	}
}

template <typename T>
void graph<T>::addNode(const T &u) {
	map_iterator it = adj_vec.find(u);
	if (it == adj_vec.end()) {
		std::set<T> someset;
		adj_vec.insert(std::pair<T, std::set<T> >(u, someset));
	}
}

template <typename T>
bool graph<T>::isConnected(const T &u, const T &v) {
	// TODO
}

template <typename T>
void graph<T>::print() {
	set_iterator it;
	map_iterator lookup_it;
	
	for (lookup_it = adj_vec.begin(); lookup_it != adj_vec.end(); lookup_it++) {
		std::cout << "node " << lookup_it->first << " -> ";
		std::set<T> someset = lookup_it->second;
		for (it = someset.begin(); it != someset.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

template <typename T>
graph<T>::~graph() {
	
}

} // end kirthi namespace 