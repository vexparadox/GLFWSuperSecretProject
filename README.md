# closedFrameworks v0.2

A basic 2D game framework written in C++.

Please note the very limited functionality currently.

Core.cpp and Core.hpp is where user code should be put. The Methods contained are self-explanatory.

Setup > Update > Draw > Update > Draw > etc...

A Runner object controls the main game loop. There is currently only functionality to draw polygons, rectangles, triangles, images and key events.

You can use images by making an Image type and using loadImage(string, width, height) to load in an image. draw(x, y) will draw the image on screen.

See Graphics.hpp for shape drawing.


## v0.2 Changelog
Finalised the CSV Reader
You can normalise 3D Vectors
Triangles are now labelled properly