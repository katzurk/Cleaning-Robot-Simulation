# 209.1 Robot sprzatajacy
## Project status
beginning


## Description
cleaning robot - roomba style.
symulator for choosing path to clean whole room and visualasing.



## Roadmap
1. room constraction
2. room visualation
3. obstacles constraction
4. obstacles visualation
5. robot movement algorithm
6. robot moving in room
7. robot avoiding obstacles
8. robot using alghoritm to clean
9. testing for random placed obstacles in the room


## Authors
Weronika Maślana
Alesia Filinkova
Katarzyna Kanicka

## Responsibilities
points:
Weronika Maślana

points:
Alesia Filinkova

points:
Katarzyna Kanicka

## Architecture

### Main objects
- **room** - has obstacles with coordinates, dimentions  (width, length)
- **obstacle** - has dimentions (width, length)
- **robot** - has start coordinates and size, can find path for cleaning

### Helper object
- **obstacle in room** - has coordinates and obstacle
- **path visualiser** - can show room, obstacles, robot, robots path