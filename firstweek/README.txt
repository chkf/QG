.vscoe 存放vscode配置文件
  使用VScode重新编译需要修改task.json文件（.vscode文件夹）中编译器位置

Headers 存放头文件
  main.h存放main函数中用到的自定义函数的声明

Release 存放可执行文件
  两个可执行文件共同特性(bug)：输入指令，初始化或插入链表结点时，需要输入数据，若数据形如123abc123，会自动忽略第一个非数字之后的所有值，读取到的的数据为123

Sources 存放源文件

  单链表ReverseList(LinkedList *L)函数有递归和非递归两种，使用递归的函数需要在main.h将宏定义ReverseList_use_algo置1

