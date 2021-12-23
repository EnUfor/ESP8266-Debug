# ESP8266 GDB Debug

<sub><sup>[source](https://arduino-esp8266.readthedocs.io/en/latest/gdb.html)</sup></sub>

1. Cloned [esp-gdbstub](https://github.com/espressif/esp-gdbstub) to `C:\Users\Andrew Grosman\Documents\Arduino\libraries`

2. Add `#include <GDBStub.h>` to `app.ino`

3. Modify `platform.txt` (`C:\Program Files (x86)\Arduino\hardware\arduino\avr`) to not optimize code during compile.

    ```
    # Change:
    compiler.cpp.flags=-c -g -Os

    # To:
    compiler.cpp.flags=-c -g -O0
    ```

    > Note: this setting has to do with code compression and saving space. Swap back the flag for final releases

## Shell Commands

1. Open GDB shell
	```DOS
	"C:\Users\Andrew Grosman\AppData\Local\Arduino15\packages\esp8266\tools\xtensa-lx106-elf-gcc\2.5.0-4-b40a506\bin\xtensa-lx106-elf-gdb.exe"
	```

2. Set ESP8266 parameters

	```
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
	```

3. Tell GDB where the compiled ELF file is located

	```
	file 'C:/Users/Andrew Grosman/Desktop/Code/esp-debug/build/app.ino.elf'
	```

4. Attach the debugger

	```
	target remote \\.\COM4
	```
	
	> Note: the Serial Monitor can not be open. Serial will be reported to the command line

## VSCode *launch.json*

<sub><sup>[source](https://github.com/microsoft/vscode-cpptools/issues/1447#issuecomment-517906636)</sup></sub>

```JSON
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
```
