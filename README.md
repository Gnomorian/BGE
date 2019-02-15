# BGE
Bill's Game Engine

There are 4 projects here:
 - Audio
 - Graphics
 - Network
 - System
 - BGE
 - TestGame
 
The first 3 projects for now are meerly wrappers for SFML libraries, when I feel like replacing them with my own code, the structure will exist in these libraries to switch between SFML and Native by the use of #defines, similar to how windows uses defines for char vs wchar_t.

System is the main interface to the operating system, an abstraction layer for Windows and Linux.

BGE is the main application that does all the work for a game, main loop, opening windows etc.
will read a config that says what "mods" to load. writes logs (debug messages on hooks if needed to work out what the mods are doing, tracing and that sort of thing).

TestGame is a dll which BGE loads like a "mod", you can have as many off these external dlls as you like, and they can hook into different parts of the engine to do what they will.
This is where the bulk of the game will be, creates entities, handles player input, networking etc.

Later when the basic wrappers and functionality for this is working, Tradegy will be updated to use this engine.
