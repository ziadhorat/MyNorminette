# MyNorminette (Extremely basic)
### Features

<p align="center">
  <img src="https://i.imgur.com/AW9MLPw.jpg">
</p>



### Note
###### ⚫Only works on .c files
###### ⚫This is extremely messy code, I'm just trying to get basic detection working

### Detects
###### ⚫Empty lines (Gives error if there are multiple '\n's next to each other)
###### ⚫Incorrect header (Based on no. of lines)
###### ⚫Empty line after header (Only checks if header is perfect)
###### ⚫New line after pre-proc (Checks for '\n' after the final '#')
###### ⚫Too many lines in function (Based on open and close curly braces { })
###### ⚫Final line can't be empty ('\0' after '\n' & '\n')
###### ⚫Trailing spaces (Spaces before ' ' or '\t')

### To-Detect
###### ⚫Space after while/if/return etc

### To-Fix
###### ⚫All pre-processors at top of file (Technically only makes sure they're all together)
