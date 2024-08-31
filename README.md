# cub3D

## Overview
`cub3D` is a 42 project inspired by the classic FPS game **Wolfenstein 3D**, developed by Id Software. The project involves creating a simple 3D game using ray-casting techniques. The goal is to render a dynamic view inside a maze from a first-person perspective.

## Features
- **Ray-Casting Engine**: The core of the project, rendering a 3D view based on 2D map data.
- **MiniLibX**: Used for window management, rendering, and handling events.

## Mandatory Part
- **Wall Rendering**: Walls are rendered with different textures depending on their orientation (North, South, East, West).
- **Movement and Rotation**: The player can move forward, backward, and rotate left or right using the keyboard (W, A, S, D, and arrow keys).
- **Color Customization**: The floor and ceiling colors can be set through the configuration file.
- **Error Handling**: The program handles invalid map configurations and exits gracefully with an error message.

## Bonus Features
- **Wall Collisions**: Implemented wall collision detection to prevent the player from walking through walls.
- **Minimap**: A minimap that shows the player’s position and the layout of the maze.
- **Doors**: Doors in the maze that can be opened and closed.
- **Animated Sprites**: Added animated sprites to enhance the visual experience.
- **Mouse Rotation**: The player can rotate the view using the mouse for a smoother experience.

## Installation
1. Clone the repository:
   ```bash
   git clone git@github.com:igox008/cub3d-42.git
   ```
2. Navigate to the project directory:
   ```bash
   cd cub3d-42
   ```
3. Compile the project:<br>
   for Mandatory :
   ```bash
   make
   ```
   for Bonus :
   ```bash
   make bonus
   ```

## Usage
To run the game, provide a `.cub` map file as an argument:
```bash
./cub3D path_to_map_file.cub
```

### Example:
```bash
./cub3D maps/example.cub
```

## Controls
- **W, A, S, D**: Move forward, left, backward, right.
- **Left/Right Arrow**: Rotate the view.
- **Mouse**: Rotate the view (Bonus).
- **TAB** : zoom the minimap (Bonus).
- **Mouse Left click or SPACE** : animate the weapon (Bonus).
- **O** : open the door (Bonus).
- **F** : close the door (Bonus).
- **C** : hide or show the mouse cursor (Bonus)
- **ESC**: Exit the game.

## Map Configuration
The `.cub` file specifies the map layout and textures. Example of a basic `.cub` file:

```
NO ./textures/north_texture.png
SO ./textures/south_texture.png
WE ./textures/west_texture.png
EA ./textures/east_texture.png
F 220,100,0
C 225,30,0

111111
100001
1000N1
111111
```

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Credits
- Inspired by **Wolfenstein 3D** by Id Software.
- Developed as part of the curriculum at **1337**.
