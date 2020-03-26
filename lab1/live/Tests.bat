@echo off

REM Путь к тестируемой программе передаётся через 1 й аргумент командной строки
set MyProgram="%~1"

REM Защита от запуска без аргумента, задающего путь к программе
if %MyProgram%=="" (
	echo "Please specify path to program"
	exit /B 1
) 

REM non-existed file input
%MyProgram% "tests\nofile.txt" && goto err
echo Test 1 passed

REM input with incorrect symbol
%MyProgram% "tests\input0.txt" && goto err
echo Test 2 passed

REM input with incorrect dimension
%MyProgram% "tests\input1.txt" && goto err
echo Test 3 passed

REM input
%MyProgram% "tests\input2.txt" > "tests\output2.txt" || goto err
echo Test 4 passed

REM input with check
%MyProgram% "tests\input3.txt" > "tests\output3.txt" || goto err
fc "tests\output3test.txt" "tests\output3.txt" > nul || goto err
echo Test 5 passed


REM Тесты прошли успешно
echo All tests passed successfuly
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test failed
exit /B 1