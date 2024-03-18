# USAGE

The program must take as a startup argument the graphics library to use initially. It must nevertheless be possible to change the graphics library at run-time.

```shell
∼/B-OOP-400> ./arcade ./lib/arcade_ncurses.so
```

When the program starts, it must display in separated boxes:

- the games libraries available in the `./lib/` directory.
- the graphics libraries available in the `./lib/` directory.
- scores.
- a field for the user to enter their name.

You MUST handle the following cases:

- if there is more or less than 1 argument, your program must print a usage message and exit properly
(`84`).
- if the dynamic library passed as argument does not exist or is not compatible, your program must display a relevant error message and exit properly (`84`).

When your program is running, keys must be mapped to the following actions:

- next graphics library.
- next game.
- restart the game.
- go back to the menu.
- exit.

> [!NOTE]
> Did you know that the `nCurses` library can handle mouse events?
