// Prints a right-aligned half-pyramid of a user-chosen height (1-8)
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Re-prompt until the user gives an integer from 1 to 8.
    // This has to be a loop, not an "if", because a single check only
    // catches one bad answer — a loop keeps control at this line until
    // the condition is finally satisfied.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Outer loop: one pass per row of the pyramid, rows 0..height-1
    for (int row = 0; row < height; row++)
    {
        // Inner loop 1: leading spaces. Row 0 needs the most (height - 1).
        for (int space = 0; space < height - 1 - row; space++)
        {
            printf(" ");
        }

        // Inner loop 2: hashes. Row 0 gets 1, last row gets height.
        for (int hash = 0; hash <= row; hash++)
        {
            printf("#");
        }

        printf("\n");
    }
}
