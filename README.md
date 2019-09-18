# Mutex
A lightweight, basic C++ templates Mutex

### I needed this for a project, but if you feel like this is useful then that's great! ###

```cpp
struct Example {
    void do_something() const {
        std::cout << "Something" << std::endl;
    }
};

int main() {
    Mutex<Example> x{};
    x.acquire()->do_something(); // acquire rights and call do_something()
}
```

# License #
This project is licensed under the MIT License (yay! free software!) - see the [LICENSE](https://github.com/Yuhanun/Mutex/blob/master/LICENSE) file for details.

### Buy me a coffee ;) (BTC) ###
32dcJ31dsxj8BMD5oD3mWKTDFSzpFHuHP1
