# Cleaning Robot Simulator
## Authors
- Weronika Maślana
- Alesia Filinkova
- Katarzyna Kanicka

## Description
Cleaning robot - roomba style.
Simulator for choosing path to clean the whole room and visualisization.

## Roadmap
1. Skeleton of Robot, Room, Furniture and Visualiser.
    - room and furniture constraction
    - robot constraction
    - visualiser can show robot in room
2. Robot can generate simple path in the room
    - robot movement algorithm
    - visualiser can show path and cleaned area
    - visualiser can show robot moving in room (simulation)
3. Adding Dirt, Cats and Robot avoidance of obstacles
    - showing dirt and cleaning algorithm
    - random placement of furniture and adding cats (randomly moving furniture in room)
    - robot avoiding obstacles
4. Simulate with randomly placed static (Furniture) and dynamic (Cats) obstacles in room

## Responsibilities
1. Weronika Maślana
points: 1.1(Robot), 2.1(Algorithm), 3.3(Avoiding obstacles)

2. Alesia Filinkova
points: 1.2(Room, Furniture), 2.2 (Showing path), 3.1(Dirt and cleaning algorithm)

3. Katarzyna Kanicka
points: 1.3(Visualiser), 2.3 (Simulation), 3.2(Cats - moving Furniture)

## Architecture
- Used C++, Cmake and Qt for visualization

### Main objects
- **Room** - has obstacles with coordinates, dimentions  (width, length)
- **Furniture** - has dimentions (width, length) and coordinates
- **Robot** - has start coordinates and size, can find path for cleaning
- **Cat** - randomly moving furniture, has dimentions (width, length) and coordinates

### Helper object
- **Visualiser** - can show room, obstacles, robot, robots path
- **Simulation** - sets up room, obstacles, robot, dirt and cleaning
- **Room_info** - virtual parent to Room. Can calculate if place is free and if is close to wall (south or east)
- **Furniture_generator** - generates random furniture in room.

### Methods
- **make_path** - takes room, returns list of coordinates. It moves from left to right and top to bottom.
- **object_detour** - takes room, path and x_direction. Moves around object down, left or right (based on x_direction) and up back to begining y pos.
- **detour_object_below_next_to_wall** - takes room, path and x_direction. If robot can't move to front nor down go back and then down to begining y pos + size down.
- **move_back_to_check_for_moving_object** - moves once back and forth to check if object is still there after coming back.
- **go_to_touch_object** - takes room, path, x_direction and y_direction. Robot wants to move per size on to object. Move there pointer and go back until found free position. Now actually move robot on free pos.
- **is_place_free_for_object** - checks if all cords with in object are inside room and not taken by other objects
- **dust** - makes dust and shows it
