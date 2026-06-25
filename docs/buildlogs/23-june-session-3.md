# Date - 2026-06-23 (Session 3)



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


