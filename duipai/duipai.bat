@echo off  
:loop  
    examples.exe %random% > data.in
    std.exe < data.in > std.out
    solve.exe < data.in > solve.out
    fc solve.out std.out 
if not errorlevel 1 goto loop  
pause
goto loop