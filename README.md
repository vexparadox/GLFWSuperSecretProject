#closedFrameworks v0.3
A basic 2D game framework written in C++, runnable on xCode OSX 10.7+

Core.cpp and Core.hpp is the user entry point into the framework. The methods contained are explained in the wiki.

## Recent additions

-Push pop Matrixes

-Ellipse rendering and collision

-Colour fills

-Increased perforamce in collisions

##v0.3 Changelog

-Optimised shape drawing

-Added text rendering! Only uses glyphmaps at the moment

-Fixed lines being drawn around images, they weren't being clamped properly

-Added exitCalled() call back in the Core

-Commented a lot of the collision and Math code

-mousePressed and keyPressed should now be accurate and take account to multiple presses

-Added a Timer class

-Cleaned up Vector code

-Added GLEW for text rendering

##v0.2 Changelog

-Finalised the CSV Reader

-You can normalise 3D Vectors

-Triangles are now labelled properly
