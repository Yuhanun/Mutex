#ifndef _MUTEX_TEMPLATE_H_
#define _MUTEX_TEMPLATE_H_
#include <mutex>

template <typename T>
class MutexGuard {
    T& val;
    std::mutex _mtx;
    std::lock_guard<std::mutex> _guard;

public:
    MutexGuard(T& val)
        : val{ val }, _guard{ _mtx } {
    }

    MutexGuard& operator=(MutexGuard&&) = default;
    MutexGuard& operator=(MutexGuard const&) = delete;

    MutexGuard(MutexGuard&& other)
        : val{ other.val }, _guard{ _mtx } {
    }

    MutexGuard(const MutexGuard&) = delete;

    T& get() {
        return val;
    }

    T& get() const {
        return val;
    }

    T* operator->() {
        return &val;
    }

    T* operator->() const {
        return &val;
    }

    T& operator*() {
        return val;
    }

    T& operator*() const {
        return val;
    }
};

template <typename T>
class Mutex {
    T _val;

public:
    Mutex()
        : _val{} {
    }

    Mutex(T const& val)
        : _val{ val } {
    }

    MutexGuard<T> acquire() {
        return { _val };
    }

    MutexGuard<T> acquire() const {
        return { _val };
    }
};

#endif
