#include <iostream>
#include <string>
using namespace std;


template<class V>
struct Array {
    using value_type = V;
    using value_ref = V &;
    using value_temp_ref = V &&;
    using const_value_ref = const V &;
    using size_t = unsigned long;

public:

    explicit Array() = default; // costruttore senza parametri

    explicit Array(size_t size, const_value_ref value = V{}) :
            __v{new V *[size]}, __size{size}, __capacity{size} { // costruttore con parametri
        for (size_t i = 0; i < size; ++i)
            __v[i] = new V{value}; // copy constructor
        cout << "costruttore con parametri\n";
    }

    Array(const Array &other) :
            __v{nullptr}, __size{0}, __capacity{0} { // costruttore di copia
        *this = other;
        cout << "costruttore di copia\n";
    }

    Array(Array &&other) noexcept :
            __v{nullptr}, __size{0}, __capacity{0} { // costruttore di move
        *this = move(other);
        cout << "costruttore di move\n";
    }

    Array &operator=(const Array &other) { // operatore di assegnazione di copia
        delete_all();
        __size = other.__size;
        __capacity = other.__capacity;
        __v = new V *[__capacity];
        for (size_t i = 0; i < __size; ++i)
            __v[i] = new V{other[i]}; // copy constructor
        return *this;
    }

    Array &operator=(Array &&other) noexcept { // operatore di assegnazione di move
        delete_all();
        __size = other.__size;
        __capacity = other.__capacity;
        __v = other.__v;
        other.__size = 0;
        other.__capacity = 0;
        other.__v = nullptr;
        return *this;
    }

    value_ref operator[](size_t index) {
        if (index >= __size)
            throw std::runtime_error{"OutOfBoundException"};
        return *__v[index];
    }

    inline const_value_ref operator[](size_t index) const {
        if (index >= __size)
            throw std::runtime_error{"OutOfBoundException"};
        return *__v[index];
    }

    void operator<<(const_value_ref new_elem) {
        reallocate_if_needed();
        __v[__size++] = new V{new_elem};
    }

    void operator<<(value_temp_ref new_elem) {
        reallocate_if_needed();
        __v[__size++] = new V{move(new_elem)};
    }

    inline void for_each(std::function<void(const_value_ref)> &&f) const {
        for (size_t i = 0; i < __size; ++i)
            f(*__v[i]);
    }

    void reserve(size_t capacity) {
        if (__capacity >= capacity) // se ho ancora spazio inutilizzato non faccio niente
            return;
        auto **new_v = new V *[capacity]; // alloco il nuovo spazio
        for (size_t i = 0; i < __size; ++i) // copio tutti gli elementi presenti (solo i puntatori! no deep copy)
            new_v[i] = __v[i]; // copia superficiale puntatore
        delete[] __v; // dealloco l'array precedente di puntatori (ma non i puntatori!)
        __v = new_v; // assegno a __v il nuovo spazio
        __capacity = capacity;
    }

    Array join(const Array &other) {
        Array result;
        size_t new_size = __size + other.__size;
        result.reserve(new_size);
        for (size_t i = 0; i < __size; ++i)
            result << *__v[i];
        for (size_t i = 0; i < other.__size; ++i)
            result << other[i];
        return result;
    }

    bool is_empty() const { return __size == 0; }

    auto size() const { return __size; }

    auto capacity() const { return __capacity; }

    inline virtual ~Array() { delete_all(); }

private:
    value_type **__v{nullptr}; // Actual elements container.
    size_t __size{0}; // Number of elements.
    size_t __capacity{0}; // Available (allocated) space. __capacity >= __size ALWAYS.

    inline void reallocate_if_needed() { reserve(__size + 1); }

    void delete_all() {
        for (size_t i = 0; i < __size; ++i)
            delete __v[i];
        delete[] __v;
    }
};

int main() {
    Array<int> a; // costruttore di default
    Array<int> b{99, 0}; // costruttore coi parametri
    Array<int> c{b}; // costruttore di copia
    Array<int> d{move(b.join(
            Array<int>{}))}; // costruttore di move (e prima viene invocato quello di default per Array<int>{})
    return 0;
}