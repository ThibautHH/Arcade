# Arcade


<b>binary name:</b> arcade  
<b>language:</b> C++  
<b>compilation:</b> via Makefile (`all`, `clean`, `fclean`, `re`) or CMake

> [!CAUTION]
> - The totality of your source files, except all useless files (binary, temp files, obj files,...), must be included in your delivery.
> - All the bonus files (including a potential specific Makefile) should be in a directory named bonus.
> - Error messages have to be written on the error output, and the program should then exit with the 84 error code (0 if there is no error).


Arcade is a **gaming platform**: a program that lets the user choose a game to play and keeps a register of player scores.  
To be able to deal with the elements of your gaming plateform at run-time, your graphics libraries and your games must be implemented as **dynamic libraries**, loaded at runtime.  

Each GUI available for the program must be used as a shared library that will be loaded and used dynamically by the main
program.

> [!CAUTION]
> It is STRICTLY FORBIDDEN to refer to a graphics library explicitly in your main program.
> Only your dynamic libraries can do so.
> This also applies to your games.

## Table of Contents

- [LIBRARIES](doc/libraries.md)
    - [DYNAMIC LIBRARIES](doc/libraries.md#dynamic-libraries)
    - [GRAPHICS LIBRARIES](doc/libraries.md#graphics-libraries)
    - [GAMES](doc/libraries.md#games)
- [USAGE](doc/USAGE.md)
- [BUILD](doc/BUILD.md)
    - [Makefile](doc/BUILD.md#makefile)
    - [CMake](doc/BUILD.md#cmake)
- [GAMES](doc/GAMES.md)
    - [Snake](doc/GAMES.md#snake)
    - [Nibbler](doc/GAMES.md#nibbler)
    - [Pacman](doc/GAMES.md#pacman)
    - [Qix](doc/GAMES.md#qix)
    - [Centipede](doc/GAMES.md#centipede)
    - [Solarfox](doc/GAMES.md#solarfox)


## Contributing

Project members:
- [Thibaut HH.](https://github.com/ThibautHH)
- [Guillaume B.](https://github.com/Gaulaume)
- [Louis L.](https://github.com/LouisLanganay)

Members with whom we have shared interfaces: https://github.com/neo-jgrec/arcade