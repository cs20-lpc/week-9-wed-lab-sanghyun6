template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    if (i <= 0) {
        throw string("Queue size must be positive.");
    }

    maxSize = i;
    buffer = new T[maxSize];
    this->length = 0;
    frontIndex = 0;
    backIndex = maxSize - 1;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        delete[] buffer;
        buffer = nullptr;
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] buffer;
    buffer = nullptr;
    this->length = 0;
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if (isEmpty()) {
        throw string("Cannot get back from an empty queue.");
    }
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    delete[] buffer;
    buffer = new T[maxSize];
    this->length = 0;
    frontIndex = 0;
    backIndex = maxSize - 1;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;
    this->length = copyObj.length;

    buffer = new T[maxSize];
    for (int i = 0; i < maxSize; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if (isEmpty()) {
        throw string("Cannot dequeue from an empty queue.");
    }

    frontIndex = (frontIndex + 1) % maxSize;
    this->length--;

    if (this->length == 0) {
        frontIndex = 0;
        backIndex = maxSize - 1;
    }
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (isFull()) {
        throw string("Cannot enqueue to a full queue.");
    }

    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem;

    if (this->length == 0) {
        frontIndex = backIndex;
    }

    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if (isEmpty()) {
        throw string("Cannot get front from an empty queue.");
    }
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
