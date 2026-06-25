# Date - 2026-06-24 (Session 1)
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


