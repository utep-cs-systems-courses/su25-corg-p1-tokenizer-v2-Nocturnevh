Project 1: Tokenizer
====================

# String Tokenizer with History

A simple C program that tokenizes user input strings and maintains a history of previously entered strings. Users can recall previous inputs using command-line style history commands.

## Features

- **String Tokenization**: Breaks input strings into individual tokens separated by spaces and tabs
- **History Management**: Automatically stores all user inputs in a linked list
- **History Recall**: Retrieve and re-process previous inputs using `!number` commands
- **History Display**: View all stored history items with their IDs
- **Memory Management**: Proper allocation and deallocation of all dynamic memory

## Files

- `uimain.c` - Main user interface program
- `tokenizer.h` / `tokenizer.c` - String tokenization functions
- `history.h` / `history.c` - History management using linked lists
- `Makefile` - Build configuration

## Compilation

Using the provided Makefile:
```bash
make
```

## Usage

Run the program:
```bash
make run
```

### Commands

- **Regular Input**: Type any string to tokenize it
- **`!q`** - Quit the program
- **`!h`** - Display all history items with their IDs
- **`!0` through `!9`** - Recall and re-tokenize history item by ID

### Example Session

```
$ make run
Welcome to my tokenizer, type a string and watch it be tokenized. 
To view history !h.
To view num history  type ! followed by number 0-9.
To exit type !q.

$ hello world testing
hello world testing
Tokens[0] = hello
Tokens[1] = world
Tokens[2] = testing
Tokens[3] = 0

$ another example string
another example string
Tokens[0] = another
Tokens[1] = example
Tokens[2] = string
Tokens[3] = 0

$ !h
History:
0
hello world testing
1
another example string

$ !0
Recalling: hello world testing
Tokens[0] = hello
Tokens[1] = world
Tokens[2] = testing
Tokens[3] = 0

$ !q
Goodbye.
```

## Implementation Details

### Tokenizer Module (`tokenizer.c`)
- **Space Detection**: Recognizes tabs (`\t`) and spaces (` `) as delimiters
- **Token Extraction**: Dynamically allocates memory for each token
- **Token Counting**: Efficiently counts tokens before allocation
- **Memory Safety**: Proper cleanup of all allocated token memory

### History Module (`history.c`)
- **Linked List Storage**: Uses a singly-linked list to store history items
- **Sequential IDs**: Automatically assigns sequential IDs starting from 0
- **String Copying**: Safely copies and stores user input strings
- **Memory Management**: Complete cleanup of all nodes and strings

### User Interface (`uimain.c`)
- **Command Parsing**: Distinguishes between commands and regular input
- **History Integration**: Integrates tokenization with history recall
- **Error Handling**: Handles invalid history IDs and commands

## Dependencies

- Standard C libraries: `stdio.h`, `stdlib.h`
- No external dependencies

## Memory Management

The program carefully manages all dynamic memory:
- Tokens are allocated and freed for each tokenization
- History strings are copied and stored safely
- Complete cleanup on program exit

## Limitations

- History recall supports single-digit IDs only (0-9)
- Maximum input string length is 100 characters

## Building and Cleaning

Use the Makefile for easy building:
```bash
make        # Build the project
make clean  # Remove compiled files
```