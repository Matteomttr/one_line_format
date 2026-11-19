*This project was carried out personally by Matteo Mattera.*

# one_line_format

## Description

`one_line_format` is a small C program that reformats one or more text files.

Everything found **between curly braces `{ }`** is collapsed onto a **single line**:

- line breaks and tabs become spaces;
- consecutive spaces are reduced to a single one.

Text outside the braces is left untouched.

**Example**

Before:

```
int a = 1;
{
	x = 1;
	y = 2;
}
```

After:

```
int a = 1; { x = 1; y = 2; }
```

The file is modified in place (overwritten with the result).

## Instructions

### Compilation

```bash
make
```

### Usage

```bash
./one_line_format file1 [file2 ...]
```

Each file passed as an argument is read, reformatted, then written back.

### Errors

- No argument: `Error: no file.`
- File not found: `Error: invalid file <name>`

> Warning: the original file is overwritten. Make a backup first if needed.

## How it works

The program is split into three parts:

| File | Role |
|---|---|
| `main.c` | Reads each file, calls the formatting, then rewrites the file |
| `ft_parse_file.c` | Reads the whole file line by line (`get_next_line`) and joins everything into a single string |
| `ft_format_text.c` | Applies the formatting to the string |
| `libft_dprintf.a` | My dprintf archive |

### Algorithm

A depth counter (`depth`) tracks the braces: it increases on each `{` and decreases on each `}`. While `depth > 0`, we are inside a block.

Formatting is done in two passes over the string:

1. **`ft_replace_whitespaces`**: replaces `\n` and `\t` with spaces inside the braces.
2. **`ft_remove_extra_spaces`**: removes duplicate spaces inside the braces.

**Why this choice?** A simple counter is enough, fast (two passes over the string), and needs no complex data structure. Loading the whole file into one string makes it easy to handle blocks that span several lines.

## Resources

- `man 2 open`, `man 2 close`, `man 3 free`
- `get_next_line` and libft documentation (42 projects)

**AI usage:** AI was used only to help write this README. The code was written and is understood by the author.
