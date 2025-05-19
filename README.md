# Cleaning Robot Simulator

- [Polish](README-PL.md)

---

## Authors
- Weronika Maślana
- Alesia Filinkova
- Katarzyna Kanicka

---

## Description
A Roomba-style cleaning robot simulator.
This project simulates a robot that selects a path to clean an entire room and visualizes the process.

## Languages and Libraries Used
- **Languages**: C++
- **Build System**: CMake
- **GUI Framework**: Qt

---

## Roadmap

1. **Initial Setup**
   - Construct room and furniture objects
   - Construct robot object
   - Visualizer displays robot inside the room

2. **Basic Pathfinding**
   - Implement robot movement algorithm
   - Visualizer displays path and cleaned areas
   - Visualizer simulates robot movement in the room

3. **Advanced Features: Dirt, Cats, and Obstacles**
   - Add dirt generation and cleaning algorithm
   - Randomly place furniture and introduce cats (moving obstacles)
   - Implement obstacle avoidance for the robot

4. **Full Simulation**
   - Simulate room with both static (furniture) and dynamic (cats) obstacles


---

## Responsibilities

1. **Weronika Maślana**  
   - 1.1: Robot construction  
   - 2.1: Pathfinding algorithm  
   - 3.3: Obstacle avoidance  

2. **Alesia Filinkova**  
   - 1.2: Room and furniture construction  
   - 2.2: Path visualization  
   - 3.1: Dirt generation and cleaning algorithm  

3. **Katarzyna Kanicka**  
   - 1.3: Visualizer implementation  
   - 2.3: Simulation of movement  
   - 3.2: Cats (moving furniture logic)  

---

## Main Objects

- **Room** — Defines dimensions (width, length) and holds obstacles  
- **Furniture** — Includes dimensions and coordinates  
- **Robot** — Has starting position and size; capable of pathfinding  
- **Cat** — Represents dynamic, moving furniture with dimensions and coordinates  

## Supporting Components

- **Visualizer** — Displays the room, robot, path, and obstacles  
- **Simulation** — Sets up the room, robot, obstacles, and cleaning process  
- **RoomInfo** — Virtual parent of `Room`, can evaluate free space and proximity to walls (south/east)  
- **FurnitureGenerator** — Randomly generates furniture in the room  

---

## Key Methods

- `make_path` — Generates a path that moves from left to right, top to bottom  
- `object_detour` — Navigates around an obstacle, then returns to the original vertical position  
- `detour_object_below_next_to_wall` — Handles cases where the robot is trapped and must retreat and try a new route  
- `move_back_to_check_for_moving_object` — Robot backs off to check if an obstacle has moved  
- `go_to_touch_object` — Approaches an object, then retreats until a free position is found  
- `is_place_free_for_object` — Verifies whether a given area is free and inside the room  
- `dust` — Generates dust and visualizes it  
