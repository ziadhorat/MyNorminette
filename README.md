# MyNorminette (WIP)

<p align="center">
  <img src="https://i.imgur.com/AW9MLPw.jpg">
</p>

### Detects
###### [01] Incorrect 42header
###### [02] Empty line required after 42header
###### [03] Pre-processor/s needs to be at the top of file
###### [04] Empty line required after pre-processor/s
###### [05] Empty line 
###### [06] Empty line at the end of the file
###### [07] Empty line required after function
###### [08] Space at the end of the line
###### [09] Too many characters in line, max 80 characters
###### [10] Too many lines in function, max 25 lines
###### [11] Too many functions in file, max 5 functions
###### [12] Curly braces need to be on their own line

### Planned
###### ⚫Tabs should be used for spacing
###### ⚫Space after while/if/return etc
###### ⚫Declaration and initialization can't be on the same line
###### ⚫All declarations must bee at the top of the function
###### ⚫Empty line after declarations

### Known bugs
###### Only works on .c files
###### New version has not yet been tested
###### Comments will throw alot of the detection off
###### The line num is 1-3 lines before the actual error

### Improvements
###### Make header detection more robust, check format instead of just characters
###### Make print_error take a value for error type instead of string for error message
