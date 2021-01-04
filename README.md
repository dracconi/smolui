A small experiment on how to make menus.

![operation](https://github.com/dracconi/smolui/raw/master/show.gif "in operation")

Also features some small proof-of-concept (?) on how screen UIs could be tested.

# Usage

Everything is contained in the `tk` directory. Fonts and icons are embedded in
the code. 

User changes the `menu.c` file to make their menu (it is a rather immediate mode GUI).
User also provides set, clear pixel, and clear display functions, which
interface with the said display. Rest is listed in `tk/usage.txt` and
`tk/using-bitmaps.txt`.

