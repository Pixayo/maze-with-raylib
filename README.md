# maze-with-raylib

Graphical maze generator built with C/C++ and Raylib. This repository holds my final project for CS50x 2026.

<table>
  <tr>
    <td align="center">
      <img width="854" height="730" alt="Demo 3" src="https://github.com/user-attachments/assets/99d65b39-e246-4849-8205-ce46bba489f8" />
    </td>
    <td align="center">    
      <img width="854" height="730" alt="Demo 4" src="https://github.com/user-attachments/assets/304eabb2-ef5b-4aea-934d-ac3e8d023ff1" />
    </td>
  </tr>
</table>

#### Video demo: `TODO`

## Thoughts

In this section I talk about why I made this project and what my objective was. It's a more casual way of explaining everything I did. If you want a more technical approach, read the `Details` section instead.

I made this project solely thinking about making my own game. I don't want to use complicated game engines and my current machine isn't powerful enough to run those programs and provide a suitable development environment. That is why I am relying on low-level programming and graphical libraries.

Everything I just said is just half the reason. The other half is that I feel pressured when using those tools; they are so over-complicated and offer functionalities that I either don't need or don't know what they are for. Then I thought I could be better off making everything myself; that was when I started learning Raylib.

Before bashing my head against the giant wall that game development is, I tried thinking about a simple project I could make to learn more about problems I could run into in the development process. In the meantime, I concluded the last CS50 problem set; I was also in need of a final project idea...

I think you already know where this is going... I thought about making a maze generator. It wasn't so difficult to make, yet, I did run into problems, like: 

- How can I display the maze in the window?
- How do I handle user input?
- What about actually generating the maze and then solving it?
- And how could I compile the program to other platforms? 

I still don't know how to compile for other platforms! But I am sure I will run into the same problem when I make my game, no need to solve every single problem now.

And here I am today writing the README because it is the last thing to do... well, I didn't make the demo video yet... so it's the second-to-last thing.

## Details



## Build

Download the source code and make sure you have a `C++ compiler` and `CMake (v3.14+)` installed. Raylib and any other dependencies will be downloaded by CMake.

1. Clone the repo and `cd` into the project directory:

```bash
git clone https://github.com/Pixayo/maze-with-raylib.git
cd maze-with-raylib
```

2. Configure the build and create a build directory:

```bash
cmake -B build
```

3. Build the project:

```bash
cmake --build build
```

That's it — after a successful build you should find the maze executable in the `build` directory.

4. Finally, run the executable:

- On Linux/MacOS:

```bash
./build/maze
```

- On Windows (PowerShell/CMD):

```powershell
.\build\maze.exe
```