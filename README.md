# Cub3D

![Demo of Cub3D](Assets/demo.gif)

## Description

Cub3D is a project developed at 42 Paris in a team of two.  
The goal is to recreate a game engine inspired by Wolfenstein 3D using the **raycasting** technique.

Raycasting consists of casting rays from the player’s point of view onto a 2D map to detect walls and create a 3D-like perspective.

To optimize performance, we use the **DDA (Digital Differential Analyzer)** algorithm, which allows efficient grid traversal without checking every point.

## Requirements

This project works on **Linux**.

It can also run on Windows using **WSL (Windows Subsystem for Linux)** with a Linux distribution

## Compilation

```bash
make all
```

If you encounter this error:

> make: *** [Makefile:40: minilibx-linux/libmlx.a] Error 2

Run the following command:

```bash
chmod +x minilibx-linux/configure
```

Then recompile.

## Execution

```bash
./cub3d Maps/[map.cub]
```

## Authors

- Noam Gauthreau--Massela  
- Celian de Segonzac

## Credits

This project uses the **MiniLibX** graphics library.
