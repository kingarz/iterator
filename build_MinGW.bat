del /Q log_file.txt
del /Q a.exe
set "path=C:\MinGW\bin"
cls

g++ *.cpp -std=c++11 > log_file.txt 2>&1

cd > log_debug.txt

	start "Containers" /B /W a.exe >> log_debug.txt 2>>&1
if ERRORLEVEL 1 (
	start log_file.txt
) else (
	start log_debug.txt
)

del a.exe
::RD Debug /Q /S
exit