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
