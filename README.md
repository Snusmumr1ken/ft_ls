# ft_ls

This is my implementation of the one of the most popular unix functions ls.

This project was done during my study at [UNIT Factory](https://unit.ua).

---

### About ft_ls

Amongst the numerous options available, I've done the following: -l, -R, -a, -r, -h, -f and -t.

Here is the usage of this program:

```
Usage: ft_ls [KEY]... [FILE]...

Show info about files (in current directory by default).
Sort everything in alphabetical order, if keys -tfr are absent

Arguments:
  -a --all            do not ignore entries starting with .
  -R --recursive      list subdirectories recursively
  -l --long           use a long listing format
  -t --time           sort by modification time, newest first
  -r --reverse        do not ignore entries starting with .
  -f                  sort nothing
  -h --help           show this info and exit

Exit codes:
  0 - everything is great
  1 - minor errors
  2 - crashes
  ```
---

