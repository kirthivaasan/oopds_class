template <typename T>
vector<T>::vector() {
	_size = 0;
	_capacity = 10;
	array = new T[_capacity];
}

template <typename T>
void vector<T>::push_back(T data) { 
	insert(data, _size);
}

template <typename T>
void vector<T>::pop_back() { 
	remove(_size - 1);
}

template <typename T>
void vector<T>::insert(T data, int pos) {
	if (pos > _size - 1 || pos < 0) return;
	if (_size + 5 == _capacity) {
		expand();
	}
	for (int i = _size - 1; i > pos; i--) 
		array[i + 1] = array[i];
	array[pos] = data;
	_size++;
}

template <typename T>
void vector<T>::remove(int pos) {
	if (pos > _size - 1|| pos < 0) return;
	for (int i = pos; i < _size + 1; i++) 
		array[i] = array[i + 1];
	_size--;
}

template <typename T>
const T& vector<T>::operator[](int i) {
	if (!(i > _size - 1 || i < 0)) return array[i];
}

template <typename T>
int vector<T>::size() {
	return _size;
}

template <typename T>
void vector<T>::clear() {
	_size = 0;
}

template <typename T>
void vector<T>::expand() {
	_capacity = _capacity * 2;
	T *newArray = new T[_capacity];
	for (int i = 0; i < _size; i++) {
		newArray[i] = array[i];
	}
	delete[] array;
	array = newArray;
}

template <typename T>
vector<T>::~vector() {
	delete[] array;
}