# Build Log - 2026-06-30 (Session 1)

## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 9:00 am to 11:00 am </span><span> git commit -m <span style="color:forestgreen;font-size:17px;"> "LinkeList testing complet" </span> </span> </div>

  
**Objective:** Validate the correctness and reliability of the custom `LinkedList` implementation using the Google Test framework.

---

## Work Completed

During this session, a complete unit testing suite was created for the `LinkedList` container. Individual test files were organized according to each public operation so that every functionality could be tested independently.

### Test Suites Created

- `InsertHeadTests.cpp`
- `InsertTests.cpp`
- `AppendTests.cpp`
- `PopTests.cpp`
- `RemoveTests.cpp`
- `ReverseTests.cpp`
- `LengthTests.cpp`
- `ExistsTests.cpp`
- `AssignmentOperatorTests.cpp`
- `EqualityOperatorTests.cpp`

---

## Test Cases Covered

### Insert Head
- Insertion into an empty list
- Multiple head insertions
- Verification of element ordering

### Insert at Position
- Insert at beginning
- Insert at middle
- Insert at end
- Invalid index handling

### Append
- Append to an empty list
- Append multiple elements
- Verify insertion order

### Pop
- Pop from a single-element list
- Pop from a multi-element list
- Pop until the list becomes empty
- Underflow condition

### Remove
- Remove head node
- Remove middle node
- Remove last node
- Remove non-existing element
- Remove from an empty list

### Reverse
- Reverse an empty list
- Reverse a single-element list
- Reverse a list containing multiple elements

### Length
- Verify initial length
- Verify length after insertion
- Verify length after deletion
- Verify length after clearing the list

### Exists
- Existing element lookup
- Non-existing element lookup
- Lookup in an empty list

### Copy Assignment Operator
- Self-assignment
- Assignment between different lists
- Deep copy verification

### Equality Operator
- Equal lists
- Different lists
- Different sizes
- Empty list comparison

---

## Google Test Integration

- Added all LinkedList test files to the CMake build.
- Built the complete testing executable successfully.
- Executed all LinkedList test suites using Google Test and CTest.
- Verified that all implemented LinkedList operations behaved as expected.

---

## Issues Faced

### 1. Constructor Initialization Issues
Initially, some tests failed because the LinkedList constructor was not initializing `head`, `tail`, and `size` correctly.

**Resolution**
- Properly initialized:
  - `head = nullptr`
  - `tail = nullptr`
  - `size = 0`

---

### 2. Copy Assignment Logic
The assignment operator initially did not clear existing nodes before copying from another list, which could lead to incorrect list contents.

**Resolution**
- Added self-assignment check.
- Cleared the current list before copying.
- Performed a deep copy by appending each node individually.

---

### 3. Remove Operation Edge Cases
The remove implementation had to correctly handle:
- Removing the head node
- Removing the tail node
- Removing the only node in the list
- Attempting to remove an element that does not exist

**Resolution**
- Added dedicated handling for each case.
- Verified behaviour through separate unit tests.

---

### 4. Reverse Operation
Special attention was required for:
- Empty list
- Single-node list
- Updating both `head` and `tail` after reversal

**Resolution**
- Implemented pointer reversal correctly.
- Updated both `head` and `tail` after completion.

---

## Outcome

Successfully completed comprehensive testing for the custom `LinkedList` implementation. The testing suite now validates all major operations, edge cases, copy semantics, and comparison operators, providing confidence in the correctness and stability of the container before integrating it into higher-level components such as `HashMap` and `Redis_lite`.