# S.T.A-Engine
A simple text adventure game engine

A console based C++ text adventure game engine, using SQLITE to store data you are able to write a story-question based game.

Each "page" is an entry in the database with a unique ID, you are able to enter "page text" which is displayed such as... "You wake up in a dark cave..." 
and have multiple choices such as.. "Go back to sleep", "Walk towards the light" etc..

As entry has a unique ID, each choice can be linked to a specific ID, building up the gameplay this way.

Entry 1:
Page Text = "Wake up in a dark cave..."
Option 1 = "Go back to sleep" => ID 2
Option 2 = "Walk towards the light" => ID 4
Option 3 = "Cry" => ID 6
Option 4 = "Look for a weapon" => ID 8

The ID can be any entry that exists within the database and they can link back to themselves if required.

Once I've finished the database-side of the program, I will write a console-based application that can load those database files and "play" them.

The creator and the "player" are planned to be two different applications.
