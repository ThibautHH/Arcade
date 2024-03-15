# BUILD
You can build your project using either a `Makefile` or `CMake`.

## MAKEFILE
Your Makefile must have the following rules (in addition to `all`, `re`, `clean` and `fclean`):  
- `core`: it must **only** build the core of your arcade (not the games nor the graphical librairies).
- `games`: it must **only** build your games librairies.
- `graphicals`: it must **only** build your graphical librairies.

The results of running a simple `make` command in your turn in directory must generate a program, at least three graphics dynamic libraries and at least two game dynamic libraries.

## CMAKE
Your CMakeLists.txt **must** build a program, at least three graphics dynamic libraries and at least two game dynamic libraries at the root of the repository.
```
∼/B-OOP-400> mkdir ./build/ && cd ./build/
∼/B-OOP-400> cmake .. -G “Unix Makefiles” -DCMAKE_BUILD_TYPE=Release
[...]
∼/B-OOP-400> cmake --build .
[...]
∼/B-OOP-400> cd ..
∼/B-OOP-400> ls ./arcade ./lib/
./arcade
./lib/:
arcade_ncurses.so
arcade_pacman.so
arcade_sdl2.so
arcade_sfml.so
arcade_solarfox.so
```