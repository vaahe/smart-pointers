#include "unique_ptr.h"

template <typename T, typename Deleter>
UniquePtr<T, Deleter>::UniquePtr(T *ptr, Deleter deleter) : m_ptr(ptr), m_deleter(deleter) {}

template <typename T, typename Deleter>
UniquePtr<T, Deleter>::~UniquePtr()
{
    if (m_ptr)
    {
        m_deleter(m_ptr);
    }
}

template <typename T, typename Deleter>
UniquePtr<T, Deleter>::UniquePtr(UniquePtr &&other) noexcept : m_ptr(other.m_ptr), m_deleter(std::move(other.m_deleter))
{
    delete other.m_ptr;
    other.m_ptr = nullptr;
}

template <typename T, typename Deleter>
UniquePtr<T, Deleter> &UniquePtr<T, Deleter>::operator=(UniquePtr &&other) noexcept
{
    if (this != &other)
    {
        if (m_ptr)
        {
            m_deleter(m_ptr);
        }

        m_ptr = other.m_ptr;
        m_deleter = std::move(other.m_deleter);

        delete other.m_ptr;
        other.m_ptr = nullptr;
    }

    return *this;
}

template <typename T, typename Deleter>
T *UniquePtr<T, Deleter>::get() const
{
    return m_ptr;
}

template <typename T, typename Deleter>
T &UniquePtr<T, Deleter>::operator*() const
{
    return *m_ptr;
}

template <typename T, typename Deleter>
T *UniquePtr<T, Deleter>::operator->() const
{
    return m_ptr;
}

template <typename T, typename Deleter>
T *UniquePtr<T, Deleter>::release()
{
    T *tmp = m_ptr;
    m_ptr = nullptr;
    return tmp;
}

template <typename T, typename Deleter>
void UniquePtr<T, Deleter>::reset(T *ptr)
{
    if (m_ptr)
    {
        m_deleter(m_ptr);
    }

    m_ptr = ptr;
}
