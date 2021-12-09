ESP8266 GDB Debug

Cloned https://github.com/espressif/esp-gdbstub to C:\Users\Andrew Grosman\Documents\Arduino\libraries
can use #include <GDBStub.h> then


PLATFORM.TXT was modified to not optimize
compiler.cpp.flags=-c -g -Os > compiler.cpp.flags=-c -g -O0
Has to do with compression / saving space. Swap back for final product


Godsend of an article
https://arduino-esp8266.readthedocs.io/en/latest/gdb.html

Shell:
"C:\Users\Andrew Grosman\AppData\Local\Arduino15\packages\esp8266\tools\xtensa-lx106-elf-gcc\2.5.0-4-b40a506\bin\xtensa-lx106-elf-gdb.exe"

INSIDE GDB Shell:
set remote hardware-breakpoint-limit 1
set remote hardware-watchpoint-limit 1
set remote interrupt-on-connect on
set remote kill-packet off
set remote symbol-lookup-packet off
set remote verbose-resume-packet off
mem 0x20000000 0x3fefffff ro cache
mem 0x3ff00000 0x3fffffff rw
mem 0x40000000 0x400fffff ro cache
mem 0x40100000 0x4013ffff rw cache
mem 0x40140000 0x5fffffff ro cache
mem 0x60000000 0x60001fff rw
set serial baud 115200

file 'C:/Users/Andrew Grosman/Desktop/Code/esp-debug/build/app.ino.elf'

(SERIAL MONITOR CAN'T BE OPEN)
target remote \\.\COM4


VSCode setup:
https://github.com/microsoft/vscode-cpptools/issues/1447#issuecomment-517906636

{
    "name": "(gdb) Launch",
    "type": "cppdbg",
    "request": "launch",
    "program": "${workspaceFolder}/build/app.ino.elf",
    "args": [],
    "stopAtEntry": false,
    "cwd": "${workspaceFolder}",
    "environment": [],
    "externalConsole": true,
    "MIMode": "gdb",
    "miDebuggerPath": "C:\\Users\\Andrew Grosman\\AppData\\Local\\Arduino15\\packages\\esp8266\\tools\\xtensa-lx106-elf-gcc\\2.5.0-4-b40a506\\bin\\xtensa-lx106-elf-gdb.exe",
    "miDebuggerServerAddress": "\\\\.\\COM4",
    "setupCommands": [
        {"text": "set remote hardware-breakpoint-limit 1"},
        {"text": "set remote hardware-watchpoint-limit 1"},
        {"text": "set remote interrupt-on-connect on"},
        {"text": "set remote kill-packet off"},
        {"text": "set remote symbol-lookup-packet off"},
        {"text": "set remote verbose-resume-packet off"},
        {"text": "mem 0x20000000 0x3fefffff ro cache"},
        {"text": "mem 0x3ff00000 0x3fffffff rw"},
        {"text": "mem 0x40000000 0x400fffff ro cache"},
        {"text": "mem 0x40100000 0x4013ffff rw cache"},
        {"text": "mem 0x40140000 0x5fffffff ro cache"},
        {"text": "mem 0x60000000 0x60001fff rw"},
        {"text": "set serial baud 115200"}
    ]
}