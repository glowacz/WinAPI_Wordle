

# WinAPI_Wordle

Wordle game written in WinAPI. It has 3 difficulty levels, letter revealing animation and coloring (in the main window and keyboard window).

![screen](https://github.com/glowacz/WinAPI_Wordle/assets/94084660/0cad8ea5-2bab-4bc4-827c-18629945835c)

Details (task content prepared by course instructors):

**Layout:** <br />
• Keyboard window centered horizontally and pushed down, should always be fully visible<br />
• Game windows centered to given screen sections:<br />
o One window - in the center of the screen<br />
o Two windows - centered in two halves of the screen<br />
o Four windows - centered in four quarters of the screen<br />
• Fixed size of game windows depending on board size<br />
• Fixed size of keyboard window chosen randomly<br />
• Set title "WORDLE - KEYBORD" and "WORDLE - PUZZLE" respectively for keyboard window and game windows<br />
• Set icon: "Wordle.ico" (Icon should also be visible in the taskbar. It suffices if it's in the main window.)<br />
• Application background color: (255, 255, 255)<br />
• Button colors (letter backgrounds) size 55 and margin between them 6:<br />
• Empty letter (default color) - (251,252,255)<br />
• Incorrect letter - (164, 174, 196)<br />
• Letter in word but wrong place - (243,194,55)<br />
• Letter in correct place - (121,184,81)<br />
• Letter border in button color and/or incorrect color if background has default color<br />
• Default size is 6 words of 5 letters<br />
• Variable size depending on difficulty level (e.g. Easy 6 words, Medium 8 words, Hard 10 words)<br />
• Application loads available words from txt file<br />
• Each game window has a different word to solve<br />
• Letters are entered simultaneously to all game windows<br />
• Enter accepts word, Backspace removes letter<br />
• Accepted word cannot be changed<br />
• After acceptance letter revealing animation in the word occurs<br />
• If word was guessed, green transparent overlay appears and window stops accepting new letters<br />
• If we didn't guess the word, red transparent overlay appears with message containing correct password<br />
• Keyboard letters are colored immediately after guessing (Enter) depending on difficulty level and window layout

**Application logic:** <br />
• Keyboard window is always transparent<br />
• Keyboard window displays letters as on keyboard<br />
• Keyboard window and game windows color letters depending on their status in given game window (several colors for larger number of game windows)<br />
• Changing difficulty level (also to the same) causes game restart and windows reset<br />
• Enter accepts word<br />
• Backspace removes letter<br />
• Display overlay depending on game status<br />
• Green - word guessed<br />
• Red with displayed solution - loss<br />
• Letters are revealed using animation<br />
• Window drawing should not cause flickering<br />
• Letter input occurs only when keyboard window has focus<br />
• Application uses save/load of difficulty level to/from ini file
