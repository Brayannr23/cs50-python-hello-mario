# Hello and Mario: C vs Python

I rewrote two of my C programs in Python for CS50 (Problem Set 6).

## Hello

```python
# Ask the user for their name, then greet them
name = input("What's your name? ")
print(f"hello, {name}")
```

## Mario: side by side

### C (36 lines)

```c
// Prints a right-aligned half-pyramid of a user-chosen height (1-8)
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Re-prompt until the user gives an integer from 1 to 8.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Outer loop: one pass per row of the pyramid
    for (int row = 0; row < height; row++)
    {
        // Inner loop 1: leading spaces
        for (int space = 0; space < height - 1 - row; space++)
        {
            printf(" ");
        }

        // Inner loop 2: hashes
        for (int hash = 0; hash <= row; hash++)
        {
            printf("#");
        }

        printf("\n");
    }
}
```

### Python (26 lines)

```python
# Prints a right-aligned half-pyramid of the height the user chooses


def main():
    height = get_height()

    # Row 1 has 1 brick, row 2 has 2, and so on.
    # Spaces fill the left side so the bricks line up on the right.
    for row in range(1, height + 1):
        print(" " * (height - row) + "#" * row)


def get_height():
    # Keep asking until the user gives a whole number from 1 to 8
    while True:
        try:
            height = int(input("Height: "))
        except ValueError:
            # They typed something like "cat" or "", so ask again
            continue

        if 1 <= height <= 8:
            return height


main()
```

## What changed

- Python's string multiplication (`" " * 3`) replaced my two inner loops for spaces and hashes.
- The C `do { } while` became `while True` with `try / except`, because `int("cat")` raises a `ValueError` in Python.
- No `#include`, no `int` types, and no `\n`: Python's `print` adds the newline for me.
