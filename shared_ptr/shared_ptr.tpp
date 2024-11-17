#include "shared_ptr.h"

template <typename T>
SharedPtr<T>::SharedPtr(T *ptr) : m_ptr(ptr), m_ref_count(new uint(ptr ? 1 : 0))
{
    std::cout << "SharedPtr is created" << std::endl;
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &other) : m_ptr(other.m_ptr), m_ref_count(other.m_ref_count)
{
    if (m_ref_count)
    {
        ++(*m_ref_count);
    }

    std::cout << "SharedPtr copy ctor" << std::endl;
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T> &&other) noexcept : m_ptr(other.m_ptr), m_ref_count(other.m_ref_count)
{
    other.m_ptr = nullptr;
    other.m_ref_count = nullptr;

    std::cout << "SharedPtr move ctor" << std::endl;
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
    std::cout << "SharedPtr is destroyed" << std::endl;
    release();
}

template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr &other)
{
    if (this != &other)
    {
        release();
        m_ptr = other.m_ptr;
        m_ref_count = other.m_ref_count;

        if (m_ref_count)
        {
            ++(*m_ref_count);
        }
    }

    return *this;
}

template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(SharedPtr &&other)
{
    if (this != &other)
    {
        release();
        
        m_ptr = other.m_ptr;
        m_ref_count = other.m_ref_count;

        other.m_ptr = nullptr;
        other.m_ref_count = nullptr;
    }

    return *this;
}

template <typename T>
void SharedPtr<T>::release()
{
    if (m_ref_count && --(*m_ref_count) == 0)
    {
        delete m_ptr;
        delete m_ref_count;

        m_ptr = nullptr;
        m_ref_count = nullptr;
    }
}

template <typename T>
T &SharedPtr<T>::operator*() const
{
    return *m_ptr;
}

template <typename T>
T *SharedPtr<T>::operator->() const
{
    return m_ptr;
}

template <typename T>
T *SharedPtr<T>::get() const
{
    return m_ptr;
}

template <typename T>
void SharedPtr<T>::reset(T *ptr)
{
    release();

    m_ptr = nullptr;
    m_ref_count = new uint(ptr ? 1 : 0);
}

template <typename T>
uint SharedPtr<T>::use_count() const
{
    return m_ref_count ? *m_ref_count : 0;
}