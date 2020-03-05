@echo off

REM ���� � ����������� ��������� ��������� ����� 1 � �������� ��������� ������
set MyProgram="%~1"

REM ������ �� ������� ��� ���������, ��������� ���� � ���������
if %MyProgram%=="" (
	echo "Please specify path to program"
	exit /B 1
) 

REM numeric input "6"
%MyProgram% "6" > nul || goto err
echo Test 1 passed

REM num+string input
%MyProgram% "1ab" > nul || goto err
echo Test 2 passed

REM num+string input
%MyProgram% "1 abc" > nul || goto err
echo Test 3 passed

REM string input
%MyProgram% "another string" > nul && goto err
echo Test 4 passed

REM num less than min + string input
%MyProgram% "-1 abc" > nul && goto err
echo Test 5 passed

REM num more than max + string input
%MyProgram% "999 abc" > nul && goto err
echo Test 6 passed

REM empty
%MyProgram% > nul && goto err
echo Test 7 passed

REM ����� ������ �������
echo All tests passed successfuly
exit /B 0

REM ���� �������� � ������ ������
:err
echo Test failed
exit /B 1