@echo off

REM Путь к тестируемой программе передаётся через 1 й аргумент командной строки
set MyProgram="%~1"

REM Защита от запуска без аргумента, задающего путь к программе
if %MyProgram%=="" (
	echo "Please specify path to program"
	exit /B 1
) 


REM non-existed file input
%MyProgram% nofile.txt && goto err
echo Test 1 passed

REM input matrix 3x3 with 0 value elements
%MyProgram% input0.txt && goto err
echo Test 2 passed

REM input matrix 3x3
%MyProgram% input1.txt > output1.txt || goto err
fc output1test.txt output1.txt > nul || goto err
echo Test 3 passed

REM input another matrix 3x3
%MyProgram% input2.txt > output2.txt || goto err
fc output2test.txt output2.txt > nul || goto err
echo Test 4 passed


REM Тесты прошли успешно
echo All tests passed successfuly
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test failed
exit /B 1