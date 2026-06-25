# Date - 2026-06-24 (Session 1)

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
