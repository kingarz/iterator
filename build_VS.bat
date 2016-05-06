del /Q log_debug.txt
::zapisanie oryginalej path
set o_path=%path%
set path="C:\Program Files (x86)\MSBuild\14.0\Bin\"
cd ..
cls
MSBuild Container.sln
start "Containers" /B /W x64\Debug\Kontener.exe > log_debug.txt 2>&1
echo Done
start log_debug.txt

::odzyskanie oryginalnej path dla TASKKILL
set path=%o_path%
TASKKILL /F /IM vctip.exe
RD Containers\x64 /Q /S

exit