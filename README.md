# This is my favorite project from my latest class!
I am very proud of this project!

# Summarize the project and what problem it was solving.
The point of this project was to make a clock that worked in real time and had settable hours, minutes, and seconds. The clock was to display in 12-hour and 24-hour formats.

# What did you do particularly well?
What I am particularly proud of is the ability of my program to look for user input while simultaneously moving the clock forward in real time. To do this, I used a function called _kbhit() to check if a key had been pressed every time I looped through the clock functionality.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I used "using namespace std." I know now that, although this is not that bad in a main.cpp file, it could sometimes cause issues with other namespaces, and "using namespace std" arguably hinders readability of code by removing the "std::" from standard library methods.
Also, in a few functions I used to mutate hours, mins, or secs, I passed in pointers as parameters. Now I know it is much more concise to just pass the parameters in as references.
I also used the conio.h library a fair bit, which is non-standard and non-portable. If I were to go through and rewrite some of the code, I would try to find a way to do the same things but make it portable to other platforms, like Linux or Mac OS.

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
For some reason, I always have a bit of trouble working with iostreams. Writing the getUserChoice() function was tougher than I thought it was going to be. But, the toughest part was figuring out which methods from which libraries to use to check for user input while making the clock tick.
For both of these problems I read a lot of Stack Overflow threads. That resource is my absolute favorite. It always has the answers I am looking for.

# What skills from this project will be particularly transferable to other projects or course work?
Working on this project taught me a lot! I learned a lot of the basics of C++ coding this. But, this was the first project so far at SNHU that has really challenged me in a very satisfying way. It felt really open-ended. There was not too much hand-holding, and it forced me to make a plan, think about how it would work as code, then execute it. I feel a lot more confident now that whatever this degree throws at me, I will be able to figure it out if I just grind hard enough.

# How did you make this program maintainable, readable, and adaptable?
I tried to put as much of my code as I could into functions. I find that a main method that is mostly calls to functions with intuitive names makes the code really easy to understand. The code is really flexible and maintainable since it is chopped up into comprehensible pieces. If you want to make a change to the way the program displays the clocks you can change the code in the displayClocks() function. Also, I thoroughly commented my code to explain every little thing I did.
