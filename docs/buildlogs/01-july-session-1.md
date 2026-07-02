# Date - 2026-07-01 (Session 1)

## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 10:00am to 1:00 pm</span>

## Finalising the proejct 01

1. Updated the design proposal with current implementation strcuture.
2. Updated the daily journals pending for few days.
3. Updated the build logs format.
4. Improved code quality by removing bugs in the redis-lite

## Bug 1 : set() method

### set method is taking only one word as value

#### Before :
```cpp
redis > set name nilesh sahu
OK
redis > get name 
nilesh
```

#### After :
```cpp
redis > set name nilesh sahu
OK
redis > get name 
nilesh sahu
```
---
## Bug 2 : Spacing in values 

### set method is not preserving spaces

#### Before :
```cpp
redis > set name Nilesh Sahu
OK
redis > get name 
nileshsahu
```

#### After :
```cpp
redis > set name Nilesh Sahu
OK
redis > get name 
nilesh nahu
```
## Bug 3 : get() method

### get returns the value in lowercase

#### Before :
```cpp
redis > set name Nilesh Sahu
OK
redis > get name 
nilesh sahu
```

#### After :
```cpp
redis > set name Nilesh Sahu
OK
redis > get name 
Nilesh Sahu
```