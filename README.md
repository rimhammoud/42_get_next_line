*This project has been created as part of the 42 curriculum by rihammou.*

# get_next_line

## Description

get_next_line is a C project that implements a function to read and return one line at a time from a file descriptor. It introduces static variables, dynamic memory allocation, and buffered reading using the `read()` system call.

The function preserves unread characters between calls, allowing files to be read line by line without losing data.

## Instructions

The project contains three mandatory files:

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

Compile the project with your own test program:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o test
```

Then run:

```bash
./test
```

`BUFFER_SIZE` determines how many bytes are read at once. It can be changed at compilation or left at the default value defined in the header.

## Algorithm

The implementation uses a static pointer called `stash` to preserve unread characters between calls.

1. **Reading:** `read_stash()` reads chunks into a temporary buffer and appends them to `stash` until a newline is found or the end of the file is reached.
2. **Extraction:** `extract_line()` copies the first line from `stash`, including the newline when present.
3. **Updating:** `update_stash()` preserves any characters remaining after the extracted line and frees the previous allocation.
4. **Returning:** `get_next_line()` returns the extracted line, or `NULL` when there is nothing left to read or an error occurs.

This approach avoids rereading characters and handles lines that span multiple buffer reads. A static variable is used because the unread characters must remain available across successive function calls.

## Resources

- [Linux `read()` manual](https://man7.org/linux/man-pages/man2/read.2.html)
- [C `malloc()` and `free()` documentation](https://man7.org/linux/man-pages/man3/malloc.3.html)

**AI usage:** AI was used to clarify concepts such as static variables, file descriptors, buffered reading, and memory management, as well as to review code, troubleshoot errors, and assist with documentation.