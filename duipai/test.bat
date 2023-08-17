@echo off  
:loop  
    examples.exe > data.in
    std.exe < data.in > std.out
    @REM solve.exe < data.in > solve.out
pause
goto loop