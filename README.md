# kolm

Our team has developed a powerful game engine that is cross-platform and supports gamepad. The engine is written in C and uses SDL2 for maximum compatibility. With our game engine, you can create immersive gaming experiences that work seamlessly across different platforms.

## Features

- Cross-platform compatibility
- Gamepad support
- Written in C
- Uses SDL2 for maximum compatibility

## Team Members

Our team consists of some of the most talented and attractive game developers out there. We're excited to bring our skills and good looks to the world of game development.

### DEV
- install sdl

uwubuntu
```bash
sudo apt-get install libsdl2-dev
```
arch sempai
```bash
sudo pacman -S sdl2
```

- build and run
```
gcc -o main main.c -lSDL2 && ./main
```

- windows

To install SDL2 and build the program on Windows, you can follow these steps:

1. Download the SDL2 development libraries for Windows from the SDL website: https://www.libsdl.org/download-2.0.php

2. Extract the downloaded ZIP file to a directory on your computer. For example, you could extract it to `C:\SDL2`.

3. Open a command prompt and navigate to the directory where you saved your C source file and type the following command to compile the program:

```powershell
gcc -o mygame mygame.c -IC:\SDL2\include -LC:\SDL2\lib -lSDL2main -lSDL2
```

Replace `mygame` with the name of your executable file, and `mygame.c` with the name of your C source file.

4. If the compilation is successful, you should have an executable file named `mygame.exe` in your current directory. To run the program, simply double-click on the executable file.

Note that the above steps assume that you have installed the GCC compiler on your Windows system. If you haven't already installed it, you can download the MinGW-w64 installer from the following website: https://sourceforge.net/projects/mingw-w64/

Once you have installed MinGW-w64, you can open a command prompt and type `gcc` to make sure it is installed correctly.

- building for production
```
gcc -o kolm kolm.c -lSDL2 -O2 -s
```