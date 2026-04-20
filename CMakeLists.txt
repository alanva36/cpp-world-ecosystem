cmake_minimum_required(VERSION 3.20) # Wersja 4.1 jeszcze nie istnieje (obecna to ~3.28)
project(Projekt)

# Ustawienie standardu C++20 (zgodnie z Twoim życzeniem)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Konfiguracja biblioteki ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# 3. Tworzenie pliku wykonywalnego z wszystkich znalezionych plików
add_executable(Projekt main.cpp
        GameController.cpp
        GameLogic/Menu.cpp
        GameLogic/World.cpp
        Ncurses/BaseRenderer.cpp
        Ncurses/GameRenderer.cpp
        Ncurses/MapRenderer.cpp
        Ncurses/Input.cpp
        Ncurses/MenuRenderer.cpp
        Ncurses/NcursesTerminal.cpp
        Entities/Animal.cpp
        Entities/Organism.cpp
        Entities/Plant.cpp
        Entities/VisualEntity.cpp
        Organisms/Wolf.cpp
        Organisms/Sheep.cpp
        Organisms/Fox.cpp
        Organisms/Human.cpp
        Organisms/Antelope.cpp
        Organisms/Turtle.cpp
        Organisms/Grass.cpp
        Organisms/Grass.hpp
        Organisms/Dandelion.cpp
        Organisms/Dandelion.hpp
        Organisms/Guarana.cpp
        Organisms/Guarana.hpp
        Organisms/Nightshade.cpp
        Organisms/Nightshade.hpp
        Organisms/Hogweed.cpp
        Organisms/Hogweed.hpp)

# 4. Linkowanie biblioteki ncurses do Twojego programu
target_link_libraries(Projekt ${CURSES_LIBRARIES})