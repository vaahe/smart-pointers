#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <memory>

template <typename T, typename Deleter = std::default_delete<T>>
class UniquePtr
{
public:
    explicit UniquePtr(T *ptr = nullptr, Deleter deleter = Deleter());
    UniquePtr(UniquePtr &&other) noexcept;
    ~UniquePtr();

    UniquePtr &operator=(UniquePtr &&other) noexcept;
    T *get() const;
    T &operator*() const;
    T *operator->() const;
    T *release();
    void reset(T *ptr = nullptr);

private:
    UniquePtr(const UniquePtr &other) = delete;
    UniquePtr &operator=(const UniquePtr &other) = delete;

    T *m_ptr;
    Deleter m_deleter;
};

#include "unique_ptr.tpp"

#endif // !UNIQUE_PTR_H