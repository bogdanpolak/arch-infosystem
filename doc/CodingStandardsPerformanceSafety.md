| Info | Value |
| --- | --- |
| Source | https://gist.github.com/lefticus/10191322 |
| Author | Jason Turner (https://github.com/lefticus) |

# C++ Coding Standards Part 2: Performance and Safety

## Limit Variable Scope

Variables should be declared as late as possible, and ideally, only when it's possible to initialize the object. Reduced variable scope results in less memory being used, more efficient code in general, and helps the compiler optimize the code further.

```c++
// Good idea
for (int i = 0; i < 15; ++i)
{
  MyObject obj(i);
  // do something with obj
}

// Bad Idea
MyObject obj; // meaningless object initialization
for (int i = 0; i < 15; ++i)
{
  obj = MyObject(i); // unnecessary assignment operation
  // do something with obj
}
// obj is still taking up memory for no reason
```

## Use Exceptions Instead of Return Values to Indicate Error

Exceptions cannot be ignored. Return values, such as using `boost::optional`, can be ignored and if not checked can cause crashes or memory errors. An exception, on the other hand, can be caught and handled. Potentially all the way up the highest level of the application with a log and automatic restart of the application.

Stroustrup, the original designer of C++, [makes this point](http://www.stroustrup.com/bs_faq2.html#exceptions-why) much better than I ever could.

## Avoid raw memory access

Raw memory access, allocation and deallocation, are difficult to get correct in C++ without [risking memory errors and leaks](http://blog2.emptycrate.com/content/nobody-understands-c-part-6-are-you-still-using-pointers). C++11 provides tools to avoid these problems.

```cpp
// Bad Idea
MyClass *myobj = new MyClass;

// ...
delete myobj;


// Good Idea
std::shared_ptr<MyClass> myobj = make_shared<MyClass>();
// ... 
// myobj is automatically freed for you whenever it is no longer used.
```

## Avoid global data
... this includes singleton objects

Global data leads to unintended sideeffects between functions and can make code difficult or impossible to parallelize. Even if the code is not intended today for parallelization, there is no reason to make it impossible for the future.


## Prefer pre-increment to post-increment 
... when it is semantically correct. Pre-increment is [faster](http://blog2.emptycrate.com/content/why-i-faster-i-c) then post-increment because it does not require a copy of the object to be made.

```cpp
// Bad Idea
for (int i = 0; i < 15; i++)
{
  std::cout << i << std::endl;
}


// Good Idea
for (int i = 0; i < 15; ++i)
{
  std::cout << i << std::endl;
}

```



## Const as much as possible
`const` tells the compiler that a variable or method is immutable. This helps the compiler optimize the code and helps the developer know if a function side effects. Also, using `const &` prevents the compiler from copying data unnecessarily. [Here](http://kotaku.com/454293019) are some comments on const from John Carmack.

```cpp
// Bad Idea
class MyClass
{
public:
  MyClass(std::string t_value)
    : m_value(t_value)
  {
  }

  std::string get_value() 
  {
    return m_value;
  }

private:
  std::string m_value;
}


// Good Idea
class MyClass
{
public:
  MyClass(const std::string &t_value)
    : m_value(t_value)
  {
  }

  std::string get_value() const
  {
    return m_value;
  }

private:
  std::string m_value;
}
```


## Prefer Stack Operations to Heap Operations

Heap operations have performance penalties in mulithreaded environments on most platforms and can possibly lead to memory errors if not used carefully.

Modern C++11 has special move operations which are designed to enhances the performance of stack based data by reducing or eliminating copies, which can bring even the single threaded case on par with heap based operations.
