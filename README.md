*This project has been created as part of the 42 curriculum by rihammou.*

# get_next_line

## Description

get_next_line is a C project from the 42 curriculum that implements a function to read a file descriptor one line at a time.

The project focuses on file handling, static variables, dynamic memory allocation, and efficient buffer management using the `read()` system call.

Each call returns the next available line, including the newline character when present, or `NULL` when there is nothing left to read or an error occurs.

## Instructions

The mandatory project consists of three files:

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

To compile the project with a test program:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o test
```

Run the executable:

```bash
./test
```

`BUFFER_SIZE` determines the maximum number of bytes read at once. It can be changed during compilation to test different buffer sizes.

## Algorithm

The implementation uses a static string to preserve unread characters between successive calls to `get_next_line()`.

1. **Reading:** `read_line()` reads chunks of data into a temporary buffer until a newline is found or EOF is reached.
2. **Accumulation:** `append_line()` combines newly read characters with the existing string while preserving previously read data.
3. **Memory allocation:** Instead of allocating a new string for every read, the allocated capacity grows exponentially when additional space is needed. This reduces repeated allocations and copying, improving performance for long lines.
4. **Extraction:** `extract_line()` allocates and copies the next line, including its terminating newline when present.
5. **Updating:** `update_line()` moves the remaining unread characters to the beginning of the existing allocation, preserving them for the next call.
6. **Cleanup:** Allocated memory is released when no longer needed, with error handling for failed reads and allocations.

### Algorithm choice

The implementation uses buffered reading and a static variable to avoid losing characters between calls. Exponential capacity growth was chosen to improve efficiency when processing long lines, since allocating and copying the entire accumulated string after every read would result in unnecessary repeated work.

Reusing the existing allocation for leftover characters also avoids unnecessary memory allocations.

## Resources

- [Linux `read()` manual](https://man7.org/linux/man-pages/man2/read.2.html)
- [Linux `malloc()` and `free()` manual](https://man7.org/linux/man-pages/man3/malloc.3.html)
