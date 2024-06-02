# Leetcode Local Playground

This repo is still in an experimental stage.
But the principle is simple, so it's possible to try it out in a hands-on way.

⚠️ Should be noticed that this is a third-party sample | template,
and it's not affiliated with Leetcode.

## How it works

The fundamental idea is:
every leetcode input/output is a JSON object | Markdown table (for database test).
So the key point is to get a serializer/deserializer for each language.

## Prerequisites

C++ programs require `nlohmann/json` library to work.
We use `vcpkg` to manage the dependencies.
You should install `vcpkg` and configure it in your PATH before running the example.

```bash
# For Linux | MacOS
(cd playgrounds/cpp/ && vcpkg install)
```

## How to run

Press `Ctrl+F5` to debug the program.

## Progress

While implementing input/output helpers, I will also go through some Leetcode exercises.

Funtionalities:

- [x] C++: Array input/output
- [ ] C++: ListNode input/output
- [ ] C++: TreeNode input/output
- [x] Python: Array input/output
- [ ] Python: ListNode input/output
- [ ] Python: TreeNode input/output
- ...

Exercise:

- [ ] Leetcode Hot 100
