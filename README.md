# Fillit

This programme takes as input a file with tetrominoes (figures from tetris game) and places them in the smallest possible square with regard to order of appearance, where the first figure is shown with letter 'A', the second with 'B', etc. If there are several solutions within the same square possible there will be selected the one where the figures that appeared earlier are placed in the most upper-left position possible

```
$ cat -e input_file
....$
####$
....$
....$
$
....$
..##$
..##$
....$
$
....$
..#.$
###.$
....$
$
....$
##..$
.##.$
....$
$
..##$
.##.$
....$
....$
$
..#.$
.##.$
.#..$
....$
$
.#..$
.##.$
..#.$
....$
$
.#..$
.###$
....$
....$
$
.#..$
.#..$
.#..$
.#..$
$
.#..$
.#..$
.##.$
....$
```

Output will look like:
```
$ ./fillit input_file
AAAABBI
..C.BBI
CCCDD.I
.EEFDDI
EEFFJG.
H.F.JGG
HHH.JJG
```
