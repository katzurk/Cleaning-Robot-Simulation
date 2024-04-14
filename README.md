# 209.1 Robot sprzatajacy
## Project status
beginning


## Description
cleaning robot - roomba style.
symulator for choosing path to clean whole room and visualasing.



## Roadmap
1. skeleton of Robot, Room and Visualiser.
    - room constraction
    - robot constraction
    - visualiser can show robot in room
2. Robot can generate simple path in the room
    - robot movement algorithm
    - visualiser can show path and cleaned area
    - visualiser can show robot moving in room (simulation)
3. adding Obstacles and Robot avoidance of obstacles
    - obstacles constraction (rectangular)
    - visualiser can show obstacles
    - robot avoiding obstacles
4. simulate with ranomly placed obstacles


## Authors
Weronika Maślana
Alesia Filinkova
Katarzyna Kanicka

## Responsibilities
points: 1.1(Robot)
Weronika Maślana

points: 1.2(Room)
Alesia Filinkova

points: 1.3(Visualiser)
Katarzyna Kanicka

## Architecture

### Main objects
- **Room** - has obstacles with coordinates, dimentions  (width, length)
- **Obstacle** - has dimentions (width, length)
- **Robot** - has start coordinates and size, can find path for cleaning

### Helper object
- **Obstacle in room** - has coordinates and obstacle
- **Visualiser** - can show room, obstacles, robot, robots path