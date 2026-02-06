# Cardinal
Stack-based 2D esoteric programming language inspired by [Befunge](https://esolangs.org/wiki/Befunge).

### Commands

| Command   | Description                                        |
| --------- | -------------------------------------------------- |
| `0` - `9` | Push corresponding number onto the stack           |
| `$`       | Pop top of stack and discard                       |
| `.`       | Pop top of stack and output as integer             |
| `,`       | Pop top of stack and output as ASCII character     |
| `#`       | Skip next command in current direction             |
| `@`       | End program                                        |
| `:`       | Duplicate top of the stack                         |
| `>`       | Direction right                                    |
| `<`       | Direction left                                     |
| `^`       | Direction up                                       |
| `v`       | Direction down                                     |
| `?`       | **Pop top of stack, if value=0 reflect direction** |
| `+`       | Add: pop a and b, push b+a                         |
| `-`       | Subtraction: pop a and b, push b-a                 |
| `*`       | Multiplication: pop a and b, push b*a              |
| `/`       | Integer division: pop a and b, push b/a            |
| `%`       | Modulo: pop a and b, push the remainder of b/a     |
| `&`       | Accept integer from user and push it               |
