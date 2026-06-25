# Date - 2026-06-23 (Session 2)

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


