# MyNorminette (Extremely basic)
### Features

<p align="center">
  <img src="https://i.imgur.com/AW9MLPw.jpg">
</p>



### Detects
###### ⚫Empty lines (Gives error if there are multiple '\n's next to each other)
###### ⚫Incorrect header (Based on no. of lines)
###### ⚫Empty line after header (Only checks if header is perfect)
###### ⚫All pre-processors at top of file (Technically only makes sure they're all together)
###### ⚫Too many lines in function (Based on open and curly braces { })

### To-Detect
###### ⚫New line after pre-proc (Checks for '\n' after the final '#')
###### ⚫Trailing spaces (Spaces before ' ' or '\t')
###### ⚫Final line can't be empy ('\0' after '\n')
###### ⚫Space after while/if/return etc
