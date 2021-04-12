# 1. tfm
A light weight TUI file manager made in C
## 1.1. Features
- Cross platform
    - [x] Support for Windows (Under development)
    - [ ] Support for MacOS
    - [x] Support for Linux
- Easy to edit config files
- Subprocess shell
- Keybinds
    - [x] `↑`: (Up arrow key) Select above
    - [x] `↓`: (Down arrow key) Select below
    - [x] `→`: (Right arrow key || Enter key) Open file or open directory
    - [x] `←`: (Left arrow key) Go to parent directory
    - [ ] `c`: Cut file
    - [ ] `y`: Copy file
    - [ ] `p`: Paste file
    - [ ] `m`: Move file
    - [ ] `t`: Create file
    - [x] `d`: Delete file
    - [ ] `u`: Undo
    - [x] `l`: Change directory
    - [ ] `h`: Display keybinds
## 1.2. Compiling
- With make
```
git clone https://github.com/synth9283/tfm.git
cd tfm/
make
```
- If linking fails, try the following
```
git clone https://github.com/synth9283/tfm.git
cd tfm/
make flags="-O3 -static -lncurses -ltinfo"
```
