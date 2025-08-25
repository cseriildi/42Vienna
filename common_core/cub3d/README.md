# About the cub3d project

You can find our cub3d git repo [here](https://github.com/cseriildi/cub3d). We collaborated on this with [Daniel](https://github.com/Csicsi).

## Summary
This is the last C project in the common core and it is a graphical one again. The goal is to learn about **ray casting** and and to create a 3D graphical representation of the inside of a maze from first-person perspective (the way you can walk around in [Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D)).

- **Allowed external functions**: `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`, `perror`, `strerror`, `exit`, `gettimeofday`, everything from `<math>`, everything from [MinilibX](https://github.com/42Paris/minilibx-linux)

## Mandatory Part

- Create maps files with `.cub` extension similar to this:
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F 220,100,0
C 225,30,0

		1111111111111111111111111
		1000000000110000000000001
		1011000001110000000000001
		1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```
- where
	- `NO`, `SO`, `WE`, `EA` are containing the path to the textures of the walls according to the direction
	- `F` and `C` is the floor and ceiling color in RGB
	- the map containing ones and zeros, where `1` is wall `0` is empty space and one `W`, `N`, `S` or `E` meaning the starting direction of the player.
	- the map should be the last thing in the file, no empty lines after of inbetween, but before the map you can separate the textures and colors with any amout of empty lines and those can be in any order, but you must only have one of each.
- In case of any issues with the map "Error\n" should be written on STDERR and exit.
- The player should start at the position where it was marked on the map, and should be able to move around freely (with the `W`, `A`, `S`, `D` buttons) and look around (with the left and right arrow buttons) in the maze realisticly.
- The window should close and when clicking on the X or hitting Esc.

## Bonus Part

Additionally to the mandatory:
- Wall collisions.
- A minimap system.
- Doors which can open and close.
- Animated sprite.
- Rotate the point of view with the mouse.

