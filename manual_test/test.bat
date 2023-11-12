copy ..\MarkDownEditor.exe .\MarkDownEditor.exe


@echo off
setlocal enabledelayedexpansion

rem 设置程序名
set program_name=MarkDownEditor.exe

rem 处理多组文件
for /L %%i in (1, 1, 3) do (
    set input_file=%%i.in
    set output_file=%%i.out
    set answer_file=%%i.ans

    rem 执行程序生成输出文件
    %program_name% < !input_file! > !output_file!

    rem 使用 `fc` 命令比较两个文件
    fc !output_file! !answer_file! > nul

    rem 检查 `fc` 命令的返回值
    if !errorlevel! equ 0 (
        echo Group %%i: Output matches the answer.
        rem 在这里执行下一组的操作
    ) else (
        echo Group %%i: Output does not match the answer.
        rem 在这里执行适当的错误处理操作
    )
)

