# BoggleDevice
Boggle Solver!

This kind of program of a "Boggle Solver" has been done before, however, I wanted to do something
cool both with programming and a physical device. This project is different in that I am not only building
the software to discover all of the words that can be made from an (n x n) Boggle board, but also create
a physical device that can play the game on a phone.

This is purely for fun and a real-world challenge for myself being that I wanted to expand upon my C++ knowledge
and skills after taking a Systems Software course. I want to learn more about C/C++ and its great power, and I
believe tackling this project is a great way to do that.

I will be offering helping positions in this project amongst my friends who are studying diverse areas of Engineering
such as Computer and Electrical Engineering, as well as my fellow Computer Science people. I want to give the chance
for my peers to get involved with real-life projects as well if they have not found where to start.

----------------------------------------------------------------------------------------------------------------------
This project is going to be split up into three phases, each of which has its unique challenges and associated
technical disciplines.
Phase 1:
    Design and Implementation of the Word-Finder. This phase is strictly software and involves the implementation
    of the algorithm to find each word in the (n x n) Boggle board, and generate the necessary "paths" for the
    physical device to play the game on the phone.
    
Phase 2:
    Research, Design, and Construction of the Boggle-playing device. In a nutshell, this is more or less constructing
    a custom 3D printer that doesn't build anything. My initial design idea consists of a moving carriage that acts as
    a phone holder in the xy-plane. This plane is parallel to a flat surface and is responsible for moving the phone
    in this plane to simulate a person dragging his/her finger along the screen to create words. The z-axis will be a
    standard touchscreen stylus to simulate the person's finger whose movements are solely vertical. Down to select a
    tile on the board, up to signify the end of the word. Most digital versions allow the user to tap each letter
    individually to build words instead of dragging. My teammembers (those I bring on to assist me with the device) 
    and I will test the accuracy and stability of the dragging versus tapping method. My preconceived notion is that
    the tapping method will prove superior as it is less strain on the stylus and requires less precision with stylus
    height and pressure on the screen to effectively build words.
    
Phase 3:
    Automation. Up until this point, everything (including the the board letters) needs to be manually entered into the
    program through the command line to work. Once both phase 1 and 2 are working sufficiently and efficiently, the last
    piece to this project is to incorporate computer vision into the device, effectively allowing it to play the game
    from start to finish on its own. The main usage of this technology is for the device to determine the game's letters
    on each tile. Without this, the operator needs to see the game's letters and input them through the command line. This
    phase is purely for the challenge and coolness factor, but who doesn't want that?
