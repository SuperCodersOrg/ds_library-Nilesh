
# Date - 2026-06-24
## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 1:00pm to 6:00 pm</span><span>git commit -m <span style="color:forestgreen;font-size:17px;"> "Hashmap: implemented all methods" </span> </span> </div>

## HashMap Implementation


### Concepts Learned

## Knuth's Multiplicative Hash Constant

* Learned about Knuth's multiplicative hashing constant:

  ```cpp
  2654435761u
  ```
* Used for hashing integer keys.
* Helps distribute keys more uniformly across buckets.
* Reduces the probability of collisions.

## Accessing Nested Template Types

* Used:

  ```cpp
  typename LinkedList<Pair>::Node* curr = bucket.head;
  ```
* Learned that `typename` is required when referring to a nested type inside a template class.
* Without `typename`, the compiler cannot determine whether `Node` is a type or a member variable.

## Functor

* Learned how to create function-like objects by overloading `operator()`.
* Example:

  ```cpp
  struct MyHash<int> {
      size_t operator()(int key) const {
          return key * 2654435761u;
      }
  };
  ```
* Functors are commonly used in STL containers and algorithms.

## Function vs Functor

### Function

* Standalone callable entity.
* Cannot maintain internal state.
* Example:

  ```cpp
  int add(int a, int b);
  ```

### Functor

* Object that behaves like a function.
* Can store internal state and configuration.
* Invoked using `operator()`.
* Extensively used in generic programming and STL.

## String Hashing

* Implemented string hashing using:

  ```cpp
  hashValue = hashValue * 31 + static_cast<unsigned char>(ch);
  ```
### Why is 31 used in String Hashing?

String hashing was implemented using:

```cpp
hashValue = hashValue * 31 + static_cast<unsigned char>(ch);
```

While any integer greater than 1 can technically be used, `31` is commonly chosen because it provides a good balance between hash quality and computational efficiency.

#### Why not use smaller numbers?

* If the multiplier is too small (e.g., 1, 2, 3), character positions have very little influence on the final hash.
* This increases the chance of collisions.
* Example:

  ```text
  "abc"
  "acb"
  ```

  may produce very similar hash values.

#### Why not use larger numbers?

* Very large multipliers can cause hash values to grow extremely fast.
* This may lead to more overflow and less predictable distribution.
* Computation can also become slightly more expensive.

#### Why specifically 31?

* 31 is a prime number.
* Prime multipliers generally produce better key distribution.
* It helps reduce patterns and clustering in hash values.
* Historically, many programming languages (including Java's `String.hashCode()`) use 31 because it has shown good practical performance.

#### Performance Advantage

Since:

```cpp
31 = 32 - 1
```

Multiplication by 31 can be optimized as:

```cpp
hashValue * 31
=
(hashValue << 5) - hashValue
```

which is faster on some architectures than a general multiplication.

#### Can Other Numbers Be Used?

Yes. Common alternatives include:

```text
33
37
53
131
257
```

Many modern hash functions use different constants.

The important requirement is that the multiplier should:

* Be greater than 1.
* Preferably be prime.
* Produce a good distribution of hash values.
* Minimize collisions for common inputs.

#### Key Takeaway

31 is not mathematically mandatory. It is a practical choice that offers:

* Good distribution,
* Low collision rates,
* Fast computation,
* Proven performance in real-world systems.


## Working with References

* Used:

  ```cpp
  LinkedList<Pair>& bucket = buckets[index];
  ```
* Learned that a reference avoids copying the entire linked list.
* Any modification through `bucket` directly modifies `buckets[index]`.
* Improves both performance and memory efficiency.

---

## Challenges Faced

* Understanding why `typename` is required for nested template types.
* Differentiating between normal functions and functors.
* Understanding the role of the multiplier `31` in string hashing.
* Learning how references help avoid unnecessary object copies.

---

## Outcome

* Improved understanding of hashing techniques.
* Learned STL-style functor implementation.
* Strengthened knowledge of templates and references.
* Gained deeper insight into hash table internals.
* Built the foundation required for implementing a generic `HashMap<K, V>`.



## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 12:00pm to 1:15 pm</span><span>git commit -m <span style="color:forestgreen;font-size:17px;"> "LinkledList: clear() method bug fixed" </span> </span> </div>

### LinkedList

* Implemented copy assignment 
* clear()

### bug encountered 
``` cpp
template<typename T> void LinkedList<T>:: clear(){
    
    while(head){ 
        Node*temp=head; 
        temp=temp->next;  // head is never updating
        delete head; // wrong delete
    }
    head=nullptr;
    tail=nullptr;
    size=0;
}
```
Corrected version

```cpp
template<typename T> void LinkedList<T>:: clear(){
    
    while(head){
        Node*temp=head;
        head=head->next;
        delete temp;
    }
    head=nullptr;
    tail=nullptr;
    size=0;
}

```


## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 9:30pm to 12:00 pm</span><span>git commit -m <span style="color:forestgreen;font-size:17px;"> "DynamicArray: finalised" </span> </span> </div>

## Features Implemented

* Implemented `clear()`
* Implemented `remove()`
* Implemented Copy Assignment Operator

```cpp
DynamicArray& operator=(const DynamicArray& other);
```

* Modified `insert()`
* Modified Copy Constructor
* Added exception-safe deep copy logic
* Completed Rule of Three

```cpp
~DynamicArray();
DynamicArray(const DynamicArray&);
DynamicArray& operator=(const DynamicArray&);
```

---

## Concepts

### 1. Difference Between

```cpp
DynamicArray& operator=(const DynamicArray& other);
```

- Copies one DynamicArray object into another.
- Returns `DynamicArray&`.
- Example: `arr1 = arr2;`

```cpp
T& operator[](int index);
```

- Accesses a specific element in the array.
- Returns `T&`.
- Example: `arr[0] = 10;`




#### Assignment Operator


DynamicArray& operator=(const DynamicArray& other);


Returns reference to the current `DynamicArray` object.

Used for:

```cpp
a = b = c;
```

#### Subscript Operator

```cpp
T& operator[](int index);
```

Returns reference to an element stored inside the array.

Used for:

```cpp
arr[0] = 100;
```

---

### 2 Internal Working of `new` and `delete`

```cpp
new     = operator new() + constructor
delete  = destructor + operator delete()
```

- `operator new()` allocates raw memory.
- Constructor initializes the object in that memory.
- Destructor destroys the object.
- `operator delete()` releases the allocated memory.

---

### 3. Memory Allocation vs Object Creation

#### malloc()

```cpp
malloc()
```

* Allocates raw memory.
* Does not create objects.
* Does not call constructors.

#### Placement New

```cpp
new(&arr[i]) T(val);
```

* Uses already allocated memory.
* Constructs an object at a specific memory location.
* Does not allocate memory.

#### Destructor

```cpp
arr[i].~T();
```

* Destroys the object.
* Does not free memory.

#### free()

```cpp
free(ptr);
```

* Releases memory.
* Does not call destructors.

---


### 4. Object Lifetime vs Memory Lifetime

Object destruction and memory deallocation are separate operations.

```cpp
malloc  -> allocate memory
free    -> deallocate memory

placement new -> construct object
~T()          -> destroy object
```

---

### 5. Why `pop_back()` Cannot Be Just `len--`

Wrong:

```cpp
len--;
```

Reason:

* Object remains alive.
* Next `push_back()` may construct a new object over an existing live object.
* Leads to Undefined Behavior.

Correct:

```cpp
arr[len-1].~T();
len--;
```

---

### 6. Capacity vs Size

Example:

```cpp
capacity = 8
size = 5
```

Memory Layout:

```text
[ obj ][ obj ][ obj ][ obj ][ obj ][ raw ][ raw ][ raw ]
```

After pop:

```text
[ obj ][ obj ][ obj ][ obj ][ dead ][ raw ][ raw ][ raw ]
```

* Capacity remains unchanged.
* Memory remains allocated.
* Only object lifetime ends.


---

### 7. Key Learning

Using:

```cpp
malloc + placement new
```

means manually managing:

* Memory Allocation
* Memory Deallocation
* Object Construction
* Object Destruction
* Copy Semantics
* Exception Safety

Essentially implementing the behavior normally provided automatically by:

```cpp
new
delete
```

for a custom container.

<div style="height: 2px; background-color: black;"></div> <br>


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
