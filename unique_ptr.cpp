  #include <iostream>
#include <memory>


template <typename T>
class unique_ptr {
public:
  unique_ptr(ptr) : ptr(ptr) {}
  unique_ptr(unique_ptr&& oth) {
    ptr = std::exchange(oth.ptr, nullptr);
  }
  unique_ptr& operator=(unique_ptr&& oth) {
    if (this != &oth) {
      delete ptr;
      ptr = std::exchange(oth.ptr, nullptr);
    }
    return *this;
  }
  ~unique_ptr() {
    delete ptr;
  }
  T* get() {
    return ptr;
  }
  T& operator*() {
    return *ptr;
  }
  T* operator->() {
    return ptr;
  }
  T* reset(T* pt) {
    ptr = pt;
    delete pt;
  }
  T* release() {
    T* tmp = ptr;
    ptr = nullptr;
    return tmp;
  }
   swap(T* pt) {
    std::swap(ptr, pt.ptr);
  }
private:
  T* ptr = nullptr;
};
