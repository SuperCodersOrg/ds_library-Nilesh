# Build Log - 2026-06-25 (Session 1)
## <div style="display:flex; justify-content:space-between;"> <span style="color:forestgreen;">Duration - 9:00pm to 1:00 pm</span><span>git commit -m <span style="color:forestgreen;font-size:17px;"> "buildlog formated and file structure updated" </span> </span> </div>


## Objective

Refactored the STL Library project structure to improve maintainability, scalability, and prepare the project for CMake-based builds.

---

## Work Completed

### 1. Project Structure Refactoring

Reorganized the project into a cleaner and more maintainable directory structure.

* Moved all public header files into the `include/` directory.
* Organized template implementation files (`.tpp`) inside dedicated folders under `src/`.
* Introduced a single root-level `main.cpp` to serve as the common testing entry point for all data structures.

### New Project Structure

```text
STL-Library/
│
├── include/
│   ├── DynamicArray.h
│   ├── LinkedList.h
│   ├── HashMap.h
│   └── MyHash.h
│
├── src/
│   ├── DynamicArray/
│   │   └── DynamicArray.tpp
│   ├── LinkedList/
│   │   └── LinkedList.tpp
│   └── HashMap/
│       └── HashMap.tpp
│
├── main.cpp
├── CMakeLists.txt
└── README.md
```

---

## 2. Build Log Organization

Previously, development progress for all data structures was maintained in a single combined build log.

Today, the documentation was reorganized by:

* Splitting the combined build log into separate build log files.
* Creating individual progress logs for each session.
* Organizing daily work so that future updates remain specific to the component being developed.

This restructuring improves documentation readability and makes it easier to track the development history of each module independently.

---

## 3. Updated Header Dependencies

Updated each header file to include its corresponding implementation file.

Example:

```cpp
#include "../src/DynamicArray/DynamicArray.tpp"
```

This keeps declarations inside header files while implementations remain inside `.tpp` files.

---

## 4. Fixed Include Paths

After restructuring, several include paths became invalid.

Completed the following:

* Corrected relative include paths.
* Fixed incorrect folder references.
* Corrected spelling mistakes in include directories.
* Ensured every header correctly references its implementation file.

---

## 5. Centralized Testing

Evaluated two approaches:

* Separate `main.cpp` for each data structure
* Single common `main.cpp`

Decided to use a **single root-level `main.cpp`** to test all STL components.

Benefits:

* Cleaner project organization
* Easier maintenance
* Single executable for testing
* Similar to professional C++ library projects

---

## 6. CMake Configuration

Created a CMake build configuration for the project.

Configured:

* C++17 standard
* Single executable target
* Include directory configuration
* Build settings for the reorganized project structure

---

## 7. IntelliSense Troubleshooting

Investigated multiple VS Code include errors.

Resolved issues related to:

* Broken include paths
* Incorrect directory references
* IntelliSense include configuration
* Incorrect CMake file naming
* Header lookup configuration

---

# Problems Faced

## Problem 1

Project restructuring caused multiple broken include paths.

### Resolution

Updated every relative include according to the new directory hierarchy.

---

## Problem 2

VS Code IntelliSense reported:

```text
cannot open source file
include errors detected
```

### Resolution

* Verified project structure
* Corrected include directives
* Configured CMake include directories
* Fixed IntelliSense configuration

---

## Problem 3

Confusion regarding project organization.

Questions explored:

* Single vs multiple `main.cpp`
* Proper placement of `.tpp` files
* Correct organization of headers and implementations

### Resolution

Adopted a structure consisting of:

* `include/` → Header files
* `src/` → Template implementations
* Root `main.cpp` → Testing entry point

---

# Key Learnings

* Professional organization of C++ template libraries.
* Proper separation of declarations and implementations using `.h` and `.tpp`.
* Importance of maintaining a clean project hierarchy.
* Basic CMake project configuration.
* Role of `target_include_directories()`.
* Difference between CMake builds and Code Runner builds.
* Benefits of maintaining separate build logs for individual modules instead of a single combined development log.

---

# Outcome

Successfully refactored the STL Library into a cleaner and more maintainable architecture.

The project is now better organized for future development and testing. Documentation has also been improved by separating the previously combined build log into individual module-specific build logs, making future progress tracking significantly easier and more structured.


