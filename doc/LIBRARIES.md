# LIBRARIES

## DYNAMIC LIBRARIES

You must use dynamic libraries at run-time.
This means that you MUST use the `dlopen`, `dlclose`, `dlsym` and `dlerror` functions to handle your dynamic libraries.

> [!CAUTION]
> `libdl` is a C library. You MUST provide an encapsulation. Also, add `-fno-gnu-unique` to your compilation flags to ensure `dlclose` unload your libraries properly.

> [!NOTE]
> Running `ldd` on your program must not show any dependency towards your libraries.

These dynamic libraries can be seen as plug-ins providing various capabilities to your main program.
In NO CASE must graphics libraries influence the game logic.
Game libraries must not contain any information about screen rendering or low-level events.
Your libraries (games and graphics) binaries (`*.so`) must be placed in the `./lib/` directory at the root of your repository.

> [!CAUTION]
> You MUST NOT differentiate your libraries.
> Each of your libraries MUST be handled in a generic and uniform manner.Keep genericity!

## GRAPHICS LIBRARIES

You must implement the `nCurses` (`arcade_ncurses.so`) and `SDL2` (`arcade_sdl2.so`) graphical libraries, and at least one more from the following list:

- NDK++ (`arcade_ndk++.so`)
- aa-lib (`arcade_aalib.so`)
- libcaca (`arcade_libcaca.so`)
- Allegro5 (`arcade_allegro5.so`)
- Xlib (`arcade_xlib.so`)
- GTK+ (`arcade_gtk+.so`)
- SFML (`arcade_sfml.so`)
- Irrlicht (`arcade_irrlicht.so`)
- OpenGL (`arcade_opengl.so`)
- Vulkan (`arcade_vulkan.so`)
- Qt5 (`arcade_qt5.so`)

## GAMES

You must implement at least two games from the following list:

- Snake (`arcade_snake.so`)
- Nibbler (`arcade_nibbler.so`)
- Pacman (`arcade_pacman.so`)
- Qix (`arcade_qix.so`)
- Centipede (`arcade_centipede.so`)
- Solarfox (`arcade_solarfox.so`)

Descriptions and rules of these games are given at the end of this document.
