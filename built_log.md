
# Date - 2026-06-23



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



## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 2:00pm to 6:00 pm</span><span>git commit -m <span style="color:forestgreen;font-size:17px;"> "DynamicArray Exception handling in malloc and placement new" </span> </span> </div>

### Implementation and Exception Handling 



- **`std::bad_alloc`**
  - Standard exception class used to indicate memory allocation failure.
  - The `new` operator throws `std::bad_alloc` automatically when it cannot allocate memory.

- **`catch (...)`**
  - The three dots (`...`) represent a catch-all handler.
  - It catches exceptions of any type.
  - Commonly used for cleanup before rethrowing the exception.

- **`if (arr == nullptr) throw std::bad_alloc();`**
  - `malloc()` returns `nullptr` when memory allocation fails.
  - Unlike `new`, `malloc()` does not throw exceptions.
  - Throwing `std::bad_alloc` manually gives `malloc()` behavior similar to `new`.

- **Exceptions from `new (&ptr[i]) T(...)`**
  - Placement new itself does not allocate memory and cannot fail due to lack of memory.
  - Exceptions can come from `T`'s constructor or copy constructor.
  - If construction fails after some elements have already been created, those elements must be destroyed manually and the raw memory must be freed.

- **Destructor access specifier**
  - Destructors are generally declared `public`.
  - A private destructor prevents users from destroying objects normally and is used only in special designs.

- **`if constexpr`**
  - Compile-time conditional introduced in C++17.
  - The branch whose condition evaluates to `false` is discarded during compilation.
  - Useful in templates to avoid compiling invalid code.

- **`std::is_trivially_destructible_v<T>`**
  - Compile-time type trait that checks whether `T` has a trivial destructor.
  - `true` for types like `int`, `char`, `double`.
  - `false` for types like `std::string` and most resource-managing classes.
  - Used to decide whether explicit destructor calls are necessary.

- **Rules for `free()`**
  - `free()` must be called with the exact pointer returned by `malloc()`.
  - Calling `free(&ptr[2])` is undefined behavior because it points inside the allocated block rather than to its beginning.
  - Individual elements are destroyed with destructors; the entire memory block is released with a single `free(ptr)`.



## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 9:30am to 1:00 pm</span><span>git commit -m <span style="color:forestgreen;font-size:17px;"> "DynamicArray - Constructor/Destructor implemented" </span> </span> </div>


### Memory Management Concepts

* Learned how `malloc()` works and how it allocates raw memory on the heap.
* Understood that `malloc()` provides aligned memory but does not call constructors or destructors.
* Explored the problems of using `malloc()` with non-primitive types such as `std::string`.
* Learned that placement new is required to construct objects inside raw memory allocated by `malloc()`.
* Understood the syntax and purpose of placement new:

```cpp
new(address) T(args);
```

* Learned the difference between **primitive** and **non-primitive** types.
* Understood that primitive types do not own resources and therefore do not require destructors.
* Learned that **non-primitive** types may manage resources and **require proper destruction**.
* Explored **padding and alignment** and understood that they are handled automatically by the compiler and allocator.
* Learned about **allocator metadata** and how `free()` is able to release an entire memory block with a single call.
* Understood the difference between object destruction and memory deallocation.
* Learned that `free()` releases **raw memory**, while destructors release **owned resources**.
* Studied `std::is_trivially_destructible_v<T>` and how it allows skipping destructor calls for primitive and trivially destructible types.
* Designed a generic destruction strategy:

```cpp
if constexpr (!std::is_trivially_destructible_v<T>)
{
    for(int i = 0; i < len; i++)
        arr[i].~T();
}

free(arr);
```

* Developed a complete object lifecycle model:

```text
malloc()
    ↓
Raw Memory
    ↓
Placement New
    ↓
Valid Objects
    ↓
Use Objects
    ↓
Destructor
    ↓
free()
```



<div style="height: 2px; background-color: black;"></div> <br>

# Date - 2026-06-22


### Goal 
Finalise Design Proposal and Start Implementation

### Problem Encounterd
After design review, structural changes were adviced. Separate .md files for each Data Structure sounld be maintained.

### What I tried
Separated the single `nilesh_design_proposal.md` file into three separate .md file, `DynamicArray.md`, `LinkedList.md`, and `Hashmap.md`.


## Duration - 2:00 pm to 6:30 pm
