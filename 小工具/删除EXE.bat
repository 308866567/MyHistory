@echo off
set "dirPath=%D:\code\c++%"

echo Deleting .exe files in %dirPath% and its subdirectories...

for /R "%dirPath%" %%F in (*.exe) do (
    echo Deleting "%%F"...
pause
    del "%%F"
)

echo Move complete.