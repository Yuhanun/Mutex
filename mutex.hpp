

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60

#include <mutex>
#include <iostream>

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