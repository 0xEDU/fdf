<h1 align="center">
	FDF
</h1>

<p align="center">
	<b><i>Wireframe model</i></b><br>
</p>

## Summary
> This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.
> It will also use the MinlibX, our own graphics library.

## Getting started
This project currently works only on Linux.
All valid maps are inside test_maps folder.
First, clone this repository, `cd` into it and also clone and compile MinilibX:

```zsh
$ git clone https://github.com/0xEDU/get_next_line; cd get_next_line
$ git clone https://github.com/42paris/minlibx-linux && make -C minlibx-linux
```

Compile the program with:

```zsh
$ make
```

Usage:

```zsh
$ ./fdf [VALID FILE]
```
