@echo off
setlocal enabledelayedexpansion

set /p x=����������x��������10��: 

set curr=1
for /l %%i in (1,1,%x%) do (
  set name=!curr!
  echo. > !name!.cpp
  set /a curr+=1
)

echo ������ɣ�
pause