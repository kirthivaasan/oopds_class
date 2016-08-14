#include <iostream>

namespace kirthi {
	
template <typename T>
bst<T>::bst() : _size(0), root(nullptr) {

}

template <typename T>
void bst<T>::insertHelper(const T &data, Node<T>* &current) {
	if (current == nullptr) {
		current = new Node<T>(data, nullptr, nullptr);
		_size++;
	} else if  (data < current->data) {
		insertHelper(data, current->left);
	} else if (data > current->data) {
		insertHelper(data, current->right);
	}
}

template <typename T>
T bst<T>::min(Node<T>* &current) {
	if (current->left == nullptr)
		return current->data;
	return min(current->left);
}

template <typename T>
T bst<T>::min() {
	return min(root);
}

template <typename T>
void bst<T>::insert(const T &data) {
	insertHelper(data, root);
}

template <typename T>
void bst<T>::remove(const T &data, Node<T>* &current) {
	if (current->data == data) {
		if (current->left == nullptr && current->right == nullptr) {
			// easy case, delete terminal node / leaf 
			delete current;
			current = nullptr;
			_size--;
		} else if (current->left == nullptr) {
			delete current;
			current = current->right;
			_size--;
		} else if (current->right == nullptr) {
			delete current;
			current = current->left;
			_size--;
		} else {
			// node with both children
			// 1. find the minimum of current node's subtree.
			T minimum = min(current);
			// 2. remove the minimum node, because we are copying it later into the current node.
			remove(minimum, current);
			// 3. set the current node to minimum
			current->data = minimum;
		}
	} else if (data > current->data) {
		remove(data, current->right);
	} else if (data < current->data) {
		remove(data, current->left);
	}
}

template <typename T>
void bst<T>::remove(const T &data) {
	remove(data, root);
}

template <typename T>
void bst<T>::clearHelper(Node<T>* &current) {
	if (current == nullptr) {
		// if current is a nullptr IGNORE
	} else if (current->left == nullptr && current->right == nullptr) {
		//std::cout << "Deleting leaf node " << current->data << std::endl
		delete current;
		current = nullptr;
	} else {
		//std::cout << "Not leaf node " << current->data << std::endl;
		clearHelper(current->left);
		clearHelper(current->right);
		//std::cout << "Deleting leaf node " << current->data << std::endl;
		delete current;
		current = nullptr;
	}
}
	
template <typename T>
void bst<T>::clear() {
	clearHelper(root);
	_size = 0;
}

template <typename T>
int bst<T>::size() {
	return _size;
}
template <typename T>
bool bst<T>::searchHelper(const T &data, Node<T>* &current) {
	if (current != nullptr) {
		if (current->data == data) return true;
		searchHelper(data, current->right);
		searchHelper(data, current->left);
	} else {
		return false;
	}
}
template <typename T>
bool bst<T>::search(const T &data) {
	searchHelper(data, root);
}


template <typename T>
void bst<T>::print(Node<T>* &current) {
	if (current != nullptr) {
		print(current->left);
		std::cout << current->data << " ";
		print(current->right);
	}
}

template <typename T>
void bst<T>::print() {
	print(root);
	std::cout << std::endl;
}

template <typename T>
bst<T>::~bst() {
	clear();
}

} // end kirthi namespace 