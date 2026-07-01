# Build Log - 2026-06-30 (Session 3)

## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 04:00 pm to 06:00 pm</span><span>git commit -m <span style="color:forestgreen;font-size:17px;"> "Redis-lite testing complete" </span> </span> </div>

  
**Objective:** Validate the correctness of the Redis Lite interface by testing all publicly exposed database operations built on top of the custom `HashMap` implementation.

---

## Work Completed

During this session, unit tests were created for the Redis Lite implementation. The primary objective was to verify that every Redis-like command correctly interacted with the underlying `HashMap` and produced the expected behaviour.

### Test Suites Created

- `ConstructorTests.cpp`
- `SetTests.cpp`
- `GetTests.cpp`
- `DeleteTests.cpp`
- `ExistsTests.cpp`
- `ClearTests.cpp`
- `SizeTests.cpp`
- `ToLowerTests.cpp`

---

## Test Cases Covered

### Constructor
- Default object creation
- Verify initial database size

### SET Command
- Insert a single key-value pair
- Insert multiple key-value pairs
- Update an existing key
- Verify size after insertion
- Verify inserted key exists

### GET Command
- Retrieve an existing key
- Attempt to retrieve a non-existing key
- Validate returned status

### DEL Command
- Delete an existing key
- Delete a non-existing key
- Verify key removal
- Verify database size after deletion

### EXISTS Command
- Existing key lookup
- Non-existing key lookup
- Verify lookup after insertion
- Verify lookup after deletion

### CLEAR Command
- Clear an empty database
- Clear a populated database
- Verify database becomes empty
- Verify subsequent insertions work correctly

### SIZE Command
- Initial database size
- Size after insertion
- Size after deletion
- Size after clearing the database

### To_lower Utility
- Convert uppercase commands
- Convert mixed-case commands
- Verify already lowercase strings remain unchanged

---

## Google Test Integration

- Added all Redis Lite test files to the CMake build configuration.
- Integrated the test suites with the existing Google Test framework.
- Verified successful compilation of the Redis Lite test executable.
- Executed Redis Lite unit tests using Google Test.

---

## Issues Faced

### 1. Interactive CLI During Testing

Initially, the Redis Lite constructor invoked the `run()` method automatically.

Since `run()` continuously waited for user input through the command-line interface, the Google Test execution appeared to hang during the constructor test.

**Resolution**

- Temporarily disabled the `run()` call inside the constructor.
- Allowed the constructor to perform only object initialization.
- This enabled automated unit tests to execute without waiting for console input.

---

### 2. Testing Private Member Functions

Initially, most Redis Lite operations (`set`, `get`, `del`, `exists`, `clear`, `size`) were declared as private members, preventing direct unit testing.

**Resolution**

- Changed the database operation methods to `public`.
- Kept only the CLI-specific functionality separate.
- Enabled direct testing of every Redis Lite operation.

---

### 3. Command Validation

Special attention was given to verifying that each Redis command correctly delegated its operation to the underlying `HashMap`.

**Resolution**

- Verified successful insertion through `SET`.
- Verified lookup using `GET` and `EXISTS`.
- Verified deletion through `DEL`.
- Verified clearing the database using `CLEAR`.
- Verified database size using `SIZE`.

---

### 4. Command Normalization

Redis commands should be accepted regardless of letter casing.

**Resolution**

- Added dedicated tests for the `To_lower()` helper.
- Verified uppercase, lowercase, and mixed-case command conversion.

---

## Outcome

Successfully completed unit testing for the Redis Lite interface. The testing suite validates all exposed database operations, command processing utilities, and interactions with the underlying `HashMap`.

This completes the testing phase for the current CLI-based Redis Lite implementation and provides a stable foundation for the next phase of development, where the command-line interface will be converted into a socket-based network server capable of handling client requests over TCP.