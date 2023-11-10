# ModOpt - Lab4

This is the base template for ModOpt Lab4 activities.

Please refer to the description of the various tasks that comprise this lab in order to progress with it.

## Compiling and running your code [Terminal]
Move into the dedicated folder within a terminal for the activity you are trying to complete and use makefile commands to compile your code. It is enough to run the command
```
make
```
In case of success, a new file called run.x should appear.
In order to run the file just compiled, type
```
./run.x
```

## Compiling and running your code [User Interface]
Open the top-level file for your project in the editor. The most likely option, is the file called `main.cpp`.
You can compile, run and debug yuor code using the user interface. You can either select "Run > Start Debugging" or press F5 to start the process. In order to debug your code, you have to place at least one break-points in your source code, otherwise the execution will go from start to end without halting.

## Troubleshooting
In case you get errors concerning missing libraries, either when compiling or running your code, make sure your environment is properly set up.
You can check whether the required variables exist in your shell session, via:
```
export -p | grep "SYSTEMC_HOME"
export -p | grep "LD_LIBRARY_PATH"
```
If either commands return an empty result, you can try to fix the issue running the following command from `<project_dir>/Lab4`

```
source init.sh
```
