# Overview
This is the github remote repository hosting my OOP University Laboratory exercises and tests.

# How to build
Make sure you have GNU Make or a an equivalent shell on Windows with GNU Make.
Then, in the root directory, run:
```bash
make
```

This is gonna automatically build all the laboratories exercises. You're gonna find the executables in their respective directories (eg. ./lab1/problem1/lab1problem1)

# How to clean
If you want to cleanup the executables and object files, simply run:
```bash
make clean
```

# Want to integrate with Clangd?
If you want to generate a JSON compile\_commands.json database to integrate with clangd or any other lsp you're using, you can use https://github.com/rizsotto/Bear.git
