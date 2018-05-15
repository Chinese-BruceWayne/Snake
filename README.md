# README


**c++ 大作业**

1. 修复食物初始化x值极大bug

2. 除去按任意键继续中文标识

3. 使用英文提示提高兼容性

4. 更改蛇、食物、标识

5. srand函数调用入口置于main函数内，防止随机数表在生成.o文件时生成

6. 重新组织文件结构，加入Menu.h, Menu.cpp(函数Start()、Menus()、CreatMap()、createSnake()、create_food())

7. 加入更改字符、游戏长宽、速度菜单

8. 完成设置字符长宽速度函数，并提示现有状态

9. 将长宽等信息提取出来，作为全局变量

10. 加入SetWindowsSize函数，通过dos命令设置窗口大小

11. 函数改名由Initial()改名为creatSnake()。

12. 加入加速度，*速度 = 初速度 + 加速度 &lowast; 分数*，并显示加速度

13. 加入是否重新游戏提示

14. 加入Map.h头文件，定义读地图，初始化地图等函数

15. 将全局变量width改为实际的方块数目

16. 从creat_food中抽象出isSnakePos函数，并重构creat_food函数

17. 加入SetMap函数

<a href=https://www.bilibili.com/video/av23440462/>bilibili演示视频</a>
