#include <mutex>

template <typename T>
class MutexGuard {
    T& val;
    std::mutex _mtx;
    std::lock_guard<std::mutex> _guard;

public:
    MutexGuard(T& val)
        : val{ val }, _guard{ _mtx }
    {}

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
    template <typename = std::enable_if<std::is_default_constructible_v<T>>>
    Mutex()
        : _val{}
    {}

    Mutex(T const& val)
        : _val{ val }
    {}

    MutexGuard<T> acquire() {
        return MutexGuard(_val);
    }

    MutexGuard<T> acquire() const {
        return MutexGuard(_val);
    }
};

/*
    Example usage:
    struct Example {
        void do_something() const {
            std::cout << "Something" << std::endl;
        }
    };

    int main() {
        Mutex<Example> x{};
        x.acquire()->do_something();
    } 
*/