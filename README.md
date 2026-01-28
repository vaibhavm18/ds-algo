

## DS&A Practice

Personal C++20 playground for learning data structures and algorithms. Nothing fancy, just a clean way to compile and run files without writing g++ commands every time.

### Structure

```
.
├── sort/           # Sorting algorithms
└── bin/            # Compiled binaries (auto-created)
```

### Running Code

From the root folder:

```bash
# Compile and run a specific file
make run f=sort/main

# Or with .cpp extension (works either way)
make run f=sort/main.cpp

# Compile everything at once
make

# List all available source files
make list

# Clean up binaries
make clean
```

### Requirements

- g++ with C++20 support (Debian 13 has it by default)
- make

That's it. Add folders as needed, drop .cpp files in them, run with `make run f=folder/filename`.

