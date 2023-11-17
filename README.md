# MarkdownEditor
复旦大学2023年OOAD课程lab，使用C++语言实现

可以在命令行输入以下指令，编译运行并跑黑盒自动测试。

```cmd
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
cd ../manual_test
./test.bat
```

注意，根据机器C++环境不同，cmake和make语句可能不同，可以替换为以下两句试试：

```cmd
cmake ..
make
```

注意事项：如果是windows平台使用powershell，因为项目的history指令会输出中文，所以要在控制面板>时钟和区域>区域中开启Beta版本

#### 1.源代码

**/src** 目录下的文件既为源代码，使用C++语言开发。

**/src/public** 为**#include**的头文件

**/src/private** 为**.cpp**文件

**/src/.../Commands** 中的文件为所有**命令**的相关实现，使用命令模式，把命令抽象为类。

**/src/.../logging**  中的文件为history和stats两个日志类功能的实现，使用观察者模式

**/src/.../MarkDownFile** 中的文件是对MarkDown文件的抽象。

#### 2.自动测试用例

测试用例分为两类，一类是黑盒测试，一类是白盒单元测试

##### 2.1 黑盒测试

在./manual_test目录下，虽然文件夹名字叫“手工测试”，但是在设计好 **test.bat** 脚本后，已经可以方便地自动测试了。

运行 **test.bat** 会把所有的 **.in** 文件作为输入传给 **MarkDownEditor.exe** 得到 **.out**文件，然后和 **.ans** 文件 **diff** 进行对比，如果一致则测试通过。

==图片==

##### 2.2 白盒测试

白盒单元测试使用 **googletest** 框架，和编译一起会得到 MarkDownEditor_test.exe

直接运行该 exe 会根据 **/test/** 目录下的 **.cc** 文件跑设计好的单元测试。并输出对应的通过情况。

==图片==



#### 3.功能完成度列表

lab1实验要求中给出的要求**全部完成**：

- 命令：load、save、ws、switch、close、insert、append-head、append-tail、delete、undo、redo、list、list-tree、dir-tree
- 日志模块，history命令，存在 **command_history.txt** 日志文件中
- 统计模块，stats命令，存在 **file_history.txt** 日志文件中

#### 4.使用说明

运行环境

启动步骤

#### 5.使用的设计模式

##### 5.1 命令模式



##### 5.2 观察者模式



##### 5.3 Composite组件模式







