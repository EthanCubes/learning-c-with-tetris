# Learning C With Tetris
A C Tetris clone. Made without AI or tutorials. My first C project. While I have used similar languages in the past, C is harder than anything I've ever used imo.

## Click [here]() to download the game

## Quickstart
- Download the game for your platform [here]()
- Run the executable file included, which may be inside a folder. This may require admin permissions on every OS, but is especially annoying on MacOS
### For MacOS users
A popup might show up saying that your computer was unable to verify that the file is free of malware. It, of course, doesn't have any malware (you can check the code for any malicious content), but Apple is just very paranoid
- Go to Settings/Privacy, scroll down until you reach a thing that says `[the app] was blocked from running`
- Allow the app. This will require admin permissions
- Try to open the file again. It should work

## How to play
- Use the `WASD` or `arrow keys` to play
- `W` or `UP` to rotate the block
- `A` or `LEFT` to move the block left, `D` or `RIGHT` to move the block right
- `S` or `DOWN` to speed up the block falling
- `Escape` to pause the game
- `N` to start a new game

## Features
- Graphical interface with falling blocks!
- User can move the falling blocks around in the sky
- Fill an entire row to clear it and gain points
- Let's be real, you definitely already know what tetris is. I'm just writing this so that my readme has more content

## How to run locally
Assuming that you mean to build from source
- Clone the Git repo from GitHub (where you're reading this right now)
- Navigate to the root of the project and compile the code.
- I'm not going to elabourate because it's really complicated and I don't really want to explain it right now

## How it works
This game was built in C with Raylib, and was created for Hack Club Out To Sea.
Raylib is a graphics library that I already have experience in, which is why I picked it.
I picked C as the primary language because Raylib still, at the end of the day, a C library, and I wanted to learn more programming languages.

## Fun facts
- Although I did know how to code somewhat well in C++ before making this project, C is so much more low level than C++ that a lot of my C++ knowledge was useless, hence why it took so long to make (still much easier compared to learning C#)
- When testing this program, I use two bash scripts, compile.sh and run.sh. Since neither of those are terms used up by any commands or things like that, I just edited my bashrc and aliased run and compile to ./run.sh and ./compile.sh

## AI usage disclosure
I didn't use AI, except when GitHub Copilot in Visual Studio Code decided to turn on and give me inline suggestions that I didn't want and didn't need.

## Credits
- This game is literally a [Tetris](https://tetris.com/) clone.
- [GeeksForGeeks](https://www.geeksforgeeks.org/) was helpful in learning C since a lot of things in C are quite different from C++.
