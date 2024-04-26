# 209.1 Robot sprzatajacy
## Project status
beginning


## Description
cleaning robot - roomba style.
symulator for choosing path to clean whole room and visualasing.



## Roadmap
1. skeleton of Robot, Room, Furniture and Visualiser.
    - room and furniture constraction
    - robot constraction
    - visualiser can show robot in room
2. Robot can generate simple path in the room
    - robot movement algorithm
    - visualiser can show path and cleaned area
    - visualiser can show robot moving in room (simulation)
3. adding Furniture and Robot avoidance of obstacles
    - obstacles constraction (rectangular)
    - visualiser can show obstacles
    - robot avoiding obstacles
4. simulate with ranomly placed obstacles


## Authors
Weronika Maślana
Alesia Filinkova
Katarzyna Kanicka

## Responsibilities
1. Weronika Maślana
points: 1.1(Robot), 2.1(algorithm)

2. Alesia Filinkova
points: 1.2(Room, Furniture), 2.2 (Showing path)

3. Katarzyna Kanicka
points: 1.3(Visualiser), 2.3 (Simulation)

## Architecture

### Main objects
- **Room** - has obstacles with coordinates, dimentions  (width, length)
- **Obstacle** - has dimentions (width, length)
- **Robot** - has start coordinates and size, can find path for cleaning

### Helper object
- **Obstacle in room** - has coordinates and obstacle
- **Visualiser** - can show room, obstacles, robot, robots path

### Methods
- **make_path** - takes room, returns list of coordinates. It moves from left to right and top to bottom.