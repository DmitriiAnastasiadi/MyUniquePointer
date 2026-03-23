#ifndef MY_UNIQUE_POINTER_H
#define MY_UNIQUE_POINTER_H

namespace SoftwarePorting {

template<typename T>
class UniquePointer;

template<class T, class... Args> UniquePointer<T> make_unique(Args&&... args) {
    return UniquePointer<T>(new T(std::forward<Args>(args)...));
}

template<typename T>
class UniquePointer {
public:
    UniquePointer(T* raw_pointer);
    ~UniquePointer();
    UniquePointer(UniquePointer &&moved);
    UniquePointer& operator=(UniquePointer&& moved);
    UniquePointer(const UniquePointer &other) = delete;
    UniquePointer& operator=(const UniquePointer& other) = delete;
    
    T& operator*();
    T* operator->();
    T* getRaw();
    
private:
    T *m_raw_pointer = nullptr;
};

#include "UniquePointer.tpp"

} // namespace SoftwarePorting
#endif // MY_UNIQUE_POINTER_H