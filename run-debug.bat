@echo off
del /Q log_debug.txt
cls
start "Containers" /B /W Debug/Kontener.exe > log_debug.txt 2>&1
echo Done
start log_debug.txt
pause