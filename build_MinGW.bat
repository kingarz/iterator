del /Q log_file.txt
del /Q a.exe
set "path=D:\ProgramFiles\MinGW\bin"
cls

g++ *.cpp -std=c++11 > log_file.txt 2>&1
start "Containers" /B /W a.exe > log_debug.txt 2>&1
start log_debug.txt

del a.exe
RD Debug /Q /S

exit