#include "UniquePointer.h"

using namespace SoftwarePorting;

template <typename T>
UniquePointer<T>::UniquePointer(T* raw_pointer) : m_raw_pointer(raw_pointer) {}

template <typename T>
UniquePointer<T>::~UniquePointer() {
    delete m_raw_pointer;
}

template <typename T>
UniquePointer<T>::UniquePointer(UniquePointer &&other) : m_raw_pointer(other.m_raw_pointer) {
    other.m_raw_pointer = nullptr;
}

template <typename T>
UniquePointer<T>& UniquePointer<T>::operator=(UniquePointer&& moved) {
    if (this != &moved) {
        delete m_raw_pointer;
        m_raw_pointer = moved.m_raw_pointer;
        moved.m_raw_pointer = nullptr;
    }
    return *this;
}

template <typename T>
T& UniquePointer<T>::operator*() {
    return *m_raw_pointer;
}

template <typename T>
T* UniquePointer<T>::operator->() {
    return m_raw_pointer;
}

template <typename T>
T* UniquePointer<T>::getRaw() {
    return m_raw_pointer;
}
