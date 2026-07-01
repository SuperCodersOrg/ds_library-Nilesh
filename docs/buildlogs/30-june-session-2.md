# Build Log - 2026-06-30 (Session 2)

## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 02:00 pm to 04:00 pm</span><span>git commit -m <span style="color:forestgreen;font-size:17px;"> "HashMap testing complete" </span> </span> </div>

 
**Objective:** Validate the correctness, reliability, and robustness of the custom `HashMap` implementation using the Google Test framework.

---

## Work Completed

During this session, a complete testing suite was created for the custom `HashMap` container. Individual test files were organized according to each public operation to keep the test structure modular and maintainable.

### Test Suites Created

- `ConstructorTests.cpp`
- `InsertTests.cpp`
- `RemoveTests.cpp`
- `ExistsTests.cpp`
- `GetTests.cpp`
- `SizeTests.cpp`
- `CapacityTests.cpp`
- `LoadFactorTests.cpp`
- `ClearTests.cpp`
- `RehashTests.cpp`

---

## Test Cases Covered

### Constructor
- Default constructor
- Initial size verification
- Initial capacity verification
- Initial load factor verification
- Empty map validation

### Insert
- Insert single key-value pair
- Insert multiple elements
- Insert duplicate keys
- Value update on duplicate key
- Negative key insertion
- Zero key insertion
- String key insertion
- Large number of insertions
- Data integrity after multiple insertions

### Remove
- Remove existing key
- Remove first inserted element
- Remove middle element
- Remove last element
- Remove negative key
- Remove zero key
- Remove non-existing key
- Remove from empty map
- Remove all elements

### Exists
- Existing key lookup
- Non-existing key lookup
- Empty map lookup
- Lookup after removal
- Multiple element lookup
- String key lookup

### Get
- Retrieve existing value
- Retrieve multiple values
- Retrieve updated value
- Retrieve negative key
- Retrieve zero key
- Retrieve string key
- Exception handling for missing keys
- Retrieval after deletion

### Size
- Initial size
- Size after insertion
- Size after multiple insertions
- Size after duplicate insertion
- Size after deletion
- Size after clearing the map

### Capacity
- Default capacity verification
- Custom capacity verification
- Capacity before rehash
- Capacity after automatic rehash

### Load Factor
- Initial load factor
- Load factor after insertion
- Load factor after multiple insertions
- Load factor after duplicate insertion
- Load factor after deletion
- Load factor after clearing

### Clear
- Clear empty map
- Clear populated map
- Insert after clear
- Verify all keys are removed
- Capacity remains unchanged after clear

### Rehash
- Automatic rehash on load factor threshold
- Capacity doubling verification
- Data preservation after rehash
- Multiple consecutive rehashes
- Load factor verification after rehash

---

## Google Test Integration

- Added all HashMap test files to the CMake build configuration.
- Successfully integrated the test suites with Google Test.
- Executed the tests using both the test executable and CTest.
- Verified correctness of all public HashMap operations.

---

## Issues Faced

### 1. Duplicate Key Handling

Initially, duplicate key insertion could incorrectly increase the element count.

**Resolution**
- Modified the insert logic to update the existing value instead of inserting a new pair.
- Increased `elementCount` only when a new key was inserted.

---

### 2. Remove Operation

Special attention was required while removing keys from buckets implemented using separate chaining.

**Resolution**
- Traversed the corresponding linked list.
- Removed the matching node safely.
- Decremented the element count only after successful deletion.

---

### 3. Rehash Validation

After implementing automatic rehashing, it was necessary to verify that no data was lost during bucket expansion.

**Resolution**
- Added dedicated tests to verify:
  - Capacity doubling
  - Correct reinsertion of existing elements
  - Preservation of all key-value pairs
  - Correct load factor after rehash

---

### 4. Multiple Definition Linker Error

While adding multiple HashMap test files, the build failed with:

```
multiple definition of `i'
```

**Cause**

A global variable:

```cpp
size_t i = 0;
```

was accidentally declared inside `MyHash.h`.

Since the header was included by multiple test files, every translation unit generated its own definition of `i`, causing a linker error.

**Resolution**

- Removed the unnecessary global variable from the header.
- Rebuilt the project successfully.
- All HashMap test files linked correctly after the fix.

---

### 5. Test Organization

As the number of test cases increased, maintaining a single large test file became difficult.

**Resolution**
- Divided the tests into feature-specific files.
- Improved readability and maintainability of the testing suite.

---

## Outcome

Successfully completed a comprehensive testing suite for the custom `HashMap` implementation. The tests validate constructor behavior, insertion, deletion, lookup, retrieval, size tracking, capacity management, load factor calculation, clearing, and automatic rehashing.

The HashMap implementation is now thoroughly verified and provides a stable foundation for higher-level components such as the custom Redis-like key-value store.