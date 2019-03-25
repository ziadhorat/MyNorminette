# MyNorminette (Extremely basic)
### Features

<p align="center">
  <img src="https://i.imgur.com/AW9MLPw.jpg">
</p>

### Note
###### ⚫Only works on .c files
###### ⚫This is extremely messy code, I'm just trying to get basic detection working, everythin is pretty much in one function, I repeat, this is horrible programming practices!

### Things that work??? (I didn't test)
###### ⚫Empty lines (Gives error if there are multiple '\n's next to each other)
###### ⚫Incorrect header (Based on no. of lines that start with '/')
###### ⚫Empty line after header (Only checks if header is perfect)
###### ⚫New line after pre-proc (Checks for '\n' after the final '#')
###### ⚫Too many lines in function (Based on open and close curly braces { })
###### ⚫80 character per line max
###### ⚫Final line can't be empty ('\0' after '\n' & '\n')
###### ⚫Trailing spaces (Spaces before ' ' or '\t')

### Buggggz (I'll fix this...maybe?)
###### ⚫All pre-processors at top of file (Technically only makes sure they're all together)

### Coming soon (I'll do it at some point)
###### ⚫5 functions per file
###### ⚫Space after while/if/return etc
###### ⚫If theres a curly brace, there can't be anything else on the line
###### ⚫Declaration and initialization can't be on the same line
