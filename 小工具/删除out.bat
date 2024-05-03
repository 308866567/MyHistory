@echo off
set "dirPath=%C:\c+++%"

echo Deleting .exe files in %dirPath% and its subdirectories...

for /R "%dirPath%" %%F in (g*.out) do (
    echo Deleting "%%F"...
pause
    del "%%F"
)

echo Move complete.