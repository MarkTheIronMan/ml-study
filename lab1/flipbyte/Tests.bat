@echo off

REM Путь к тестируемой программе передаётся через 1 й аргумент командной строки
set MyProgram="%~1"

REM Защита от запуска без аргумента, задающего путь к программе
if %MyProgram%=="" (
	echo "Please specify path to program"
	exit /B 1
) 

REM numeric input "6"
%MyProgram% "6" > nul || goto err
echo Test 1 passed

REM num input > range
%MyProgram% "255" > nul && goto err
echo Test 2 passed

REM num input < range
%MyProgram% "-1" > nul && goto err
echo Test 3 passed

REM num input < range
%MyProgram% "0" > nul && goto err
echo Test 4 passed

REM string input
%MyProgram% "another string" > nul && goto err
echo Test 5 passed

REM num less than min + string input
%MyProgram% "-1 abc" > nul && goto err
echo Test 6 passed

REM num more than max + string input
%MyProgram% "500 abc" > nul && goto err
echo Test 7 passed

REM empty
%MyProgram% > nul && goto err
echo Test 8 passed

REM Тесты прошли успешно
echo All tests passed successfuly
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test failed
exit /B 1