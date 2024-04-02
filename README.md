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


## Mermaid Diagram

```mermaid
classDiagram
    class Core {
        + Core()
        + ~Core()
        + coreLoop()
        + menuLoop()
        - _currentLib: IDisplayModule*
        - _currentGame: IGameModule*
        - _displayModules: vector<shared_ptr<IDisplayModule>>
        - _gameModules: vector<shared_ptr<IGameModule>>
    }
    class IDisplayModule {
        <<interface>>
        + void init()
        + void close()
        + std::map<KeyType, int> getInputs() const
        + void setGameName(std::string name)
        + void setMapSize(Vector2i vector)
        + void clear()
        + void updateTile(Vector2i vector, ISprite *sprite)
        + void displayGame()
        + void setAnimationTime(float time)
        + float getDeltaT()
        + void setText(std::string text, Vector2i pos, Color color)
    }
    class IGameModule {
        <<interface>>
        + void init(std::string args, size_t nb_args)
        + void close()
        + bool update(std::map<KeyType, int> inputs, float deltaT)
        + std::string getGameName()
        + Vector2i getMapSize()
        + std::vector<std::vector<ISprite>> getMap()
        + unsigned int getScore()
        + float getAnimationTime()
        + std::vector<IText *> getTexts()
    }
    class Vector2i {
        - int x
        - int y
    }
    
    class ISprite {
        <<interface>>
        + void setAscii(std::string ascii)
        + std::string getAscii()
        + void setPath(char path)
        + std::string getPath()
        + void setRotation(int rotation)
        + int getRotation()
        + void setDirection(Vector2i direction)
        + Vector2i getDirection()
        + void setColor(Color color)
        + Color getColor()
        + void setShape(Shape shape)
        + Shape getShape()
    }
    class Color {
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE,
        DEFAULT
    }
    class Shape {
        RECTANGLE,
        CIRCLE,
        TRIANGLE
    }
    class IText {
        <<interface>>
        + void setText(std::string text)
        + std::string getText()
        + void setPos(Vector2i pos)
        + Vector2i getPos()
        + void setColor(Color color)
        + Color getColor()
    }
    class ModuleLibrary {
        + ModuleLibrary(const char *path)
        + std::unique_ptr<T> createModule() const
        - ModuleCreatorSymbol
        - _moduleCreator: std::function<module_creator>
    }
    Core --> IDisplayModule : "_currentLib"
    Core --> IGameModule : "_currentGame"
    Core --> ModuleLibrary : "_displayModules"
    Core --> ModuleLibrary : "_gameModules"
    IDisplayModule -- Vector2i : "setMapSize"
    IDisplayModule -- ISprite : "updateTile"
    IDisplayModule -- Vector2i : "setText"
    IDisplayModule -- Color : "setText"
    ISprite -- Vector2i : "setDirection"
    ISprite -- Color : "setColor"
    ISprite -- Shape : "setShape"
    IGameModule -- Vector2i : "getMapSize"
    IGameModule -- ISprite : "getMap"
    IGameModule -- IText : "getTexts"
```

## Contributing

Project members:
- [Thibaut HH.](https://github.com/ThibautHH)
- [Guillaume B.](https://github.com/Gaulaume)
- [Louis L.](https://github.com/LouisLanganay)

Members with whom we have shared interfaces: https://github.com/neo-jgrec/arcade