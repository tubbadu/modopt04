# ModOpt - Lab1

This is the base template for ModOpt Lab1 activities.

Please refer to the description of the various tasks that comprise this lab in order to progress with it.


## Troubleshooting
In case you get errors concerning missing libraries, either when compiling or running your code, make sure your environment is properly set up.
You can check whether the required variables exist in your shell session, via:
```
export -p | grep "SYSTEMC_HOME"
export -p | grep "LD_LIBRARY_PATH"
```
If either commands return an empty result, you can try to fix the issue running the following command from `<project_dir>/Lab1`

```
source init.sh
```
