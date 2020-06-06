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
│  │  boss.h
│  │  cast.h
│  │  distinguishObject.h
│  │  door.h
│  │  draw.h
│  │  equipment.h
│  │  event.h
│  │  file.h
│  │  floor.h
│  │  handleKey.h
│  │  handleMonster.h
│  │  key.h
│  │  map.h
│  │  menu.h
│  │  monster.h
│  │  monsterMannual.h
│  │  object.h
│  │  picture.h
│  │  prop.h
│  │  shop.h
│  │  runGame.h
│  │  space.h
│  │  theBrave.h
│  │  point.h
│  │  theElderly.h
│  │  tool.h
│  │  tools.h
│  │  wall.h
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
        boss.cpp
        cast.cpp
        distinguishObject.cpp
        door.cpp
        draw.cpp
        equipment.cpp
        event.cpp
        file.cpp
        floor.cpp
        handleKey.cpp
        handleMonster.cpp
        key.cpp
        main.cpp
        map.cpp
        menu.cpp
        monsterMannual.cpp
        prop.cpp
        runGame.cpp
        shop.cpp
        space.cpp
        theBrave.cpp
        theElderly.cpp
        tool.cpp
        wall.cpp
```

