#include <iostream>

template <typename T>
list<T>::list() : _size(0), head(NULL) {

}

template <typename T>
void list<T>::push_front(T data) { 
	insert(data, 0);
}

template <typename T>
void list<T>::insert(T data, int index) {
	if (head == NULL || index == 0) {
		head = new Node<T>(data, head);
		_size++;
	} else { 
		int pos = 0;
		index--; // to stop one index before the actual position we are interested in.
		for (Node<T> *current = head; current != NULL; current = current->next) {
			if (index == pos) {
				Node<T> *old_next = current->next;
				current->next = new Node<T>(data, old_next);
				_size++;
				break;
			}
			pos++;
		}
	}
}

template <typename T>
void list<T>::remove(int index) {
	if (head != NULL && index == 0) {
		Node<T> *head_next = head->next;
		delete head;
		head = head_next;
		_size--;
	} else { 
		int pos = 0;
		index--; // to stop one index before the actual position we are interested in.
		for (Node<T> *current = head; current->next != NULL; current = current->next) {
			if (index == pos) {
				Node<T> *old_next = current->next;
				current->next = current->next->next;
				delete old_next;
				_size--;
				break;
			}
			pos++;
		}
	}
}

template <typename T>
int list<T>::size() {
	return _size;
}

template <typename T>
void list<T>::print() {
	for (Node<T> *current = head; 
		current != NULL; current = current->next)
		std::cout << current->data << " ";
}

template <typename T>
list<T>::~list() {
	while (_size > 0)
		remove(0);
}