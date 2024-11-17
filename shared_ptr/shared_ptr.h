#ifndef SHARED_PTR_H
#define SHARED_PTR_H

typedef unsigned int uint;

#include <iostream>

template <typename T>
class SharedPtr
{
public:
    explicit SharedPtr(T *ptr = nullptr);
    SharedPtr(const SharedPtr<T> &other);
    SharedPtr(SharedPtr<T> &&other) noexcept;
    ~SharedPtr();

public:
    T *get() const;
    void reset(T *ptr = nullptr);

    // accessors
    T &operator*() const;
    T *operator->() const;

    // operators
    SharedPtr &operator=(const SharedPtr<T> &other);
    SharedPtr &operator=(SharedPtr<T> &&other);

    // utilities
    uint use_count() const;

private:
    void release();

private:
    T *m_ptr;
    uint *m_ref_count;
};

#include "shared_ptr.tpp"

#endif // !SHARED_PTR_H