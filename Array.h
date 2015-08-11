#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>
class Array
{
private:
        size_t m_size;
        int m_curInd;
        T *m_arr;
        T* allocate(size_t amount);
        void construct(T *data, T value);
        void destroy(T* data);
        void deallocate(T* data);
public:
        Array(size_t m_size);
        Array(const Array &Right);
        void resize(size_t new_size);
        ~Array();
        void push_back(T back_dig);
        T operator[](T digital) const;
        T & operator[](T digital);
        void Show();
};

template <typename T>
T Array<T>::operator[](T digital)
{
    if (digital >= m_size)
        throw std::invalid_argument ("Out of range");
    return m_arr[digital];
}

template <typename T>
T& Array<T>::operator[](T digital)
{
    if (digital >= m_size)
        throw std::invalid_argument ("Out of range");
    return m_arr[digital];
}

template<typename T>
Array<T>::Array(size_t size):m_size(size), m_curInd(0)
{
    cout << "==================C of array==================" << endl;
    m_arr = allocate(size);
    for (int i = 0; i < size; ++i)  {
        construct(&m_arr[i], T());
    }
}

template<typename T>
T* Array<T>::allocate(size_t amount)
{
    uint8_t *tmp = new uint8_t[amount*sizeof(T)];
    return reinterpret_cast<T *> (tmp);
}

template<typename T>
void Array<T>::construct(T* data, T value)
{
    new(data) T(value);
}

template<typename T>
void Array<T>::deallocate(T* data)
{
    uint8_t *temp = reinterpret_cast<uint8_t *>(data);
    delete[] temp;
}

template<typename T>
void Array<T>::destroy(T* data)
{
    data->~T();
}

template<typename T>
void Array<T>::push_back(T back_dig)
{
    m_size += 1;
    T* tmp = allocate(m_size);
    for (size_t i = 0; i < m_size-1; ++i)    {
        construct(&tmp[i], m_arr[i]);
        destroy(&m_arr[i]);
    }
    construct(&tmp[m_size-1], back_dig);
    deallocate(m_arr);
    m_arr = tmp;
}

template<typename T>
void Array<T>::resize(size_t new_size)
{
    if (m_size == new_size) {
        cout << "New size is the same." << endl;
        return;
    }
    cout << "Current size: " << m_size << endl;
    T* tmp = allocate(new_size);
    if (m_size < new_size)  {
        for (size_t i = 0; i < m_size; ++i)    {
            construct(&tmp[i], m_arr[i]);
            destroy(&m_arr[i]);
        }
        for (size_t i = min_size+1; i < new_size; ++i)   {
            construct(&tmp[i], T());
        }
    }
    else if (m_size > new_size) {
        for (size_t i = 0; i < new_size; ++i)
            construct(&tmp[i], m_arr[i]);
        for (size_t i = 0; i < m_size; ++i)
            destroy(&m_arr[i]);
    }
    deallocate(m_arr);
    m_size = new_size;
    m_arr = tmp;
    cout << "New array size: " << m_size << endl;
}

template<typename T>
Array<T>::~Array()
{
    cout << "==================D of array==================" << endl;
    for (size_t i = 0; i < m_size; ++i) {
        destroy(&m_arr[i]);
    }
    deallocate(m_arr);
}

template<typename T>
void Array<T>::Show()
{
    for (int i = 0; i < m_size; ++i)
        cout << m_arr[i] << endl;
}
#endif // ARRAY_H
