@echo off
setlocal enabledelayedexpansion

set /p x=请输入数字x（不大于10）: 

set curr=1
for /l %%i in (1,1,%x%) do (
  set name=!curr!
  echo. > !name!.cpp
  set /a curr+=1
)

echo 生成完成！
pause