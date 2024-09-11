@echo off
set UE4EDITORCMD_EXE=C:\Program Files\Epic Games\UE_4.27\Engine\Binaries\Win64\UE4Editor-Cmd.exe
set E:\UE\ShootThemDownHub\ShootThemDown.uproject
call "%UE4EDITORCMD_EXE%" "%UPROJECT_PATH%" -run=CompileAllBlueprints -ShowResultsOnly
pause