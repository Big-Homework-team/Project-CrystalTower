# Project-CrystalTower
A C++ Big Homework using EGE(UI lib)

It's a game like magic tower

## Build

Only build in MinGW-GCC(4.8+), Windows NT

```bash
mkdir build
cd build
cmake ..
```

## Source Structure

```
│  .gitignore
│  CMakeLists.txt
│  README.md
│
├─include
│  │  ege.h
│  │  graphics.h
│  │  
│  └─ege
│          button.h
│          fps.h
│          label.h
│          sys_edit.h
│          
├─lib
│      libgraphics.a
│      libgraphics64.a
│      
└─src
        main.cpp
```

