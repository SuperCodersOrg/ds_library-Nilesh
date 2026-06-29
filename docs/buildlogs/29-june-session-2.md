# Build Log - 2026-06-29 (Session 2)

## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 9:00am to 1:00 pm</span><span>git commit -m <span style="color:forestgreen;font-size:17px;"> "DynamicArray testing complete" </span> </span> </div>



**Objective:** Integrate GoogleTest into the STL Library project, establish an automated testing framework, and validate the `DynamicArray` implementation through comprehensive unit testing.

---

# Overview

The primary focus of this session was to introduce automated testing into the STL Library project using **GoogleTest**. Along with setting up the testing framework, the build system was updated to support test executables through **CMake**. After successfully configuring the environment, a complete unit test suite was written for the `DynamicArray` implementation and executed to verify correctness.

---

# Work Completed

## 1. Studied GoogleTest Framework

Learned the fundamentals of automated testing in C++.

Topics covered:

* Difference between manual testing and automated testing.
* Purpose of unit testing.
* Structure of a GoogleTest test file.
* Difference between `TEST()` and `TEST_F()`.
* Role of test fixtures and the `SetUp()` function.
* Assertion macros including:

  * `EXPECT_EQ`
  * `EXPECT_GT`
  * `EXPECT_THROW`

Also understood how `RUN_ALL_TESTS()` automatically discovers and executes every registered test.

---

## 2. Integrated GoogleTest into the Project

Added GoogleTest as an external dependency.

Updated the project structure:

```text
external/
    googletest/

tests/
    main.cpp
    DynamicArray/
```

Configured the project to build GoogleTest along with the STL Library using CMake.

---

## 3. Learned CMake for Automated Testing

Studied the purpose of important CMake commands used while integrating GoogleTest.

Covered:

* `add_subdirectory()`
* `add_executable()`
* `target_include_directories()`
* `target_link_libraries()`
* `enable_testing()`
* `gtest_discover_tests()`

Also learned the complete build pipeline:

```text
CMakeLists.txt
        ↓
cmake ..
        ↓
Generate Build Files
        ↓
cmake --build .
        ↓
DynamicArrayTests.exe
```

Understood why GoogleTest projects are built using CMake instead of manually compiling individual source files.

---

## 4. Build Environment Configuration

Resolved several environment and build issues during integration.

Problems encountered:

* Incorrect build generator (`nmake`) selected by CMake.
* Missing `mingw32-make`.
* Compiler detection issues.
* Incorrect source file paths inside `CMakeLists.txt`.
* Linking issues while compiling GoogleTest manually.

Resolution:

* Installed and configured `mingw32-make`.
* Configured CMake with the **MinGW Makefiles** generator.
* Corrected project paths.
* Successfully generated the testing executable through CMake.

---

## 5. DynamicArray Unit Testing

Created a complete testing suite for the current `DynamicArray` implementation.

### Insert()

Tested:

* Insert at beginning
* Insert at middle
* Insert at end
* Insert into empty array
* Automatic resize during insertion
* Invalid negative index
* Invalid index beyond current size
* Large dataset insertion

---

### Remove()

Tested:

* Remove from beginning
* Remove from middle
* Remove from end
* Remove only element
* Remove from empty array
* Invalid negative index
* Invalid index beyond current size
* Large dataset removal

---

### Push Back

Tested:

* Single insertion
* Multiple insertions
* Automatic resize
* Large dataset insertion

---

### Pop Back

Tested:

* Remove last element
* Remove all elements
* Empty container exception handling

---

## 6. Executed Test Suite

Successfully executed the complete DynamicArray test suite.

### Test Result

```text
Total Tests : 23
Passed      : 22
Failed      : 1
```

The only failed test was caused by an exception type mismatch.

Expected:

```cpp
std::out_of_range
```

Actual implementation:

```cpp
std::underflow_error
```

This was identified as a design choice rather than a logical implementation error.

---

## Challenges Faced

* Understanding how GoogleTest executes test cases.
* Learning the purpose of `TEST` and `TEST_F`.
* Configuring GoogleTest with CMake.
* Resolving compiler, linker, and build tool configuration issues.
* Understanding the difference between compile-time errors, linker errors, and runtime test failures.

---

## Key Learnings

* Modern C++ unit testing using GoogleTest.
* Test fixtures using `TEST_F`.
* Writing independent and reusable unit tests.
* Exception validation using `EXPECT_THROW`.
* Integrating third-party libraries with CMake.
* Building multiple executables from a single project.
* Organizing test files for scalability and maintainability.
* Validating container behavior through automated testing.

---

# Outcome

By the end of the session:

* GoogleTest was successfully integrated into the STL Library project.
* CMake was configured to build dedicated testing executables.
* A reusable testing framework was established for future data structures.
* The `DynamicArray` implementation was validated through automated unit testing.
* The testing infrastructure is now ready to be extended for upcoming implementations such as `LinkedList`, `HashMap`, `Stack`, `Queue`, and future STL components.
