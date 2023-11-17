# MarkdownEditor
复旦大学2023年OOAD课程lab，使用C++语言实现

可以在命令行输入以下指令，编译运行并跑黑盒自动测试。

编译：

```cmd
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
```

**Windows**环境的话可以不编译，直接运行项目目录中的**.exe**

注意，根据机器C++环境不同，cmake和make语句可能不同，可以替换为以下两句试试：

```cmd
cmake ..
make
```

注意事项：如果是windows平台使用powershell，因为项目的指令会输出中文，所以要在控制面板>时钟和区域>区域中开启Beta版本，支持UTF-8编码。

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

```cmd
PS D:\OOAD\MarkdownEditor\manual_test> .\test.bat

D:\OOAD\MarkdownEditor\manual_test>copy ..\MarkDownEditor.exe .\MarkDownEditor.exe 
        1 file(s) copied.

D:\OOAD\MarkdownEditor\manual_test>del *.md

D:\OOAD\MarkdownEditor\manual_test>del *.txt

D:\OOAD\MarkdownEditor\manual_test>del *.out
Group 1: Output matches the answer.
Group 2: Output matches the answer.
Group 3: Output matches the answer.
```



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

##### 编译环境

要有cmake，有C++环境

##### 运行环境

项目目录下现成的.exe文件的运行需要是windows环境

##### 启动步骤

有2种使用方式

1.直接运行MarkDownEditor.exe，正常使用

2.在./manual_test/ 目录下，添加.in文件，然后运行./test.bat查看对应的.out文件即为输出



#### 5.使用的设计模式

##### 5.1 命令模式

把命令抽象为Command类，每一个具体的命令都是Command的子类，覆写具体的**exex()**执行函数以及**Undo**时的逻辑。

```C++
class Command_Insert : public Command
{
public:
    virtual void exec(EditorState &state) override;
    virtual void undo(EditorState &state) override;
    Command_Insert(std::string raw_para, std::vector<std::string> para);
};
```

命令模式的优点：

1.容易实现**Undo**、**Redo**的逻辑，一次命令的相关参数都存在**Command**类中，只要拿到指针就可以重复执行、**undo**。

2.开发新的**Command**时，和其他**Command**基本完全解耦，避免了众多命令函数挤在一个文件中难以维护的情况。

3.继承满足了命令对于多样性的需求，例如：每个命令可以自行管理参数（Int？String？），



##### 5.2 观察者模式

- 日志模块，history命令，存在 **command_history.txt** 日志文件中
- 统计模块，stats命令，存在 **file_history.txt** 日志文件中

这两个模块都是用观察者来实现的，日志模块会在命令执行后记录下来。统计模块会在命令执行前，根据命令是否会关闭文件，记录下文件的持续时长

这两个观察者会监听命令执行前后两个阶段，覆写自己需要监听的部分即可

```C++
class LogListenerBase
{
public:
    virtual ~LogListenerBase() {}
    virtual void notifyBeforeExec(Command *cmd, EditorState &state){};
    virtual void notifyAfterExec(Command *cmd, EditorState &state){};
};
```



##### 5.3 Composite组件模式

在设计**MarkDown**文件的组织方式时，注意到，逻辑上，Title类型可以有很多叶子结点（Title 或者 正文），这一嵌套结构非常适合使用组件模式

即：**MarkDownTitle**和**MarkDownBody** 均继承自 **MarkDownComponent**，**MarkDownTitle**又以组合的方式持有**MarkDownComponent**的指针。







