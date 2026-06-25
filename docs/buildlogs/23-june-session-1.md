# Date - 2026-06-23  (Session 1)
## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 8:00pm to 2:00 am</span><span>git commit -m <span style="color:forestgreen;font-size:17px;"> "DynamicArray: operator overloading" </span> </span> </div>


### Methods implemented on DynamicArray:
private methods will be used as helper methods which cannot be accessed by user
```cpp
private:
    void resize();
    void destroyAndFree(T * arr,int count);
    void destroyHalf(T*array,int i);
    void del(int val);
```


```cpp
public:
    DynamicArray();
    DynamicArray(int cap,T val);
    DynamicArray(const DynamicArray& other); //Copy Constructor
    T& operator [](int index); // operator [] 
    const T& operator [](int index) const; // const operator []
    ~DynamicArray(); //Destructor
    void push_back(const T& value); //Add value at last
    void insert(int index, T value); //Add value at given index
    void remove(int index);// Delete value by index
    void pop_back(); // Delete last element
    int size() const; // return number of elements inserted
    int capacity()const;// returns total capacity of array

```
### DynamicArray Updates

- Added bounds-checked `operator[]` overloads (const and non-const).
- Improved `push_back()` parameter passing from `T` to `const T&` to avoid unnecessary copies.
- Added underflow protection in `pop_back()`.
- Added exception handling using `std::out_of_range` and `std::underflow_error`.
- Improved memory management for non-trivial types with explicit destructor calls.
- Added groundwork for Rule of Three implementation (copy constructor in progress).


