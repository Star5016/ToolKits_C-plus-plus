# VS Studio 配置

1.需要安装MYSQL

2.将文件复制到代码目录

3.右键单击添加现有项

![](https://star5016-ossbucket-shanghai.oss-cn-shanghai.aliyuncs.com/mdimg/1.png)

4.工具栏->项目->属性

![](https://star5016-ossbucket-shanghai.oss-cn-shanghai.aliyuncs.com/mdimg/vsstudio_mysql_config2.png)

5.查看MySQL安装目录 找到 include 和 lib两个目录

![](https://star5016-ossbucket-shanghai.oss-cn-shanghai.aliyuncs.com/mdimg/vsstudio_mysql_config4.png)

6.VC++->

包含目录 填写MySQL安装文件夹下的include文件夹路径

库目录 填写MySQL安装文件夹下的lib文件夹路径

![](https://star5016-ossbucket-shanghai.oss-cn-shanghai.aliyuncs.com/mdimg/vsstudio_mysql_config3.png)

7.链接器->输入->附加依赖性 输入 libmysql.lib

![](https://star5016-ossbucket-shanghai.oss-cn-shanghai.aliyuncs.com/mdimg/vsstudio_mysql_config5.png)

8.把libmysql.dll文件复制到生成的可编译文件夹处 libmysql.dll在刚才的lib文件夹中

![](https://star5016-ossbucket-shanghai.oss-cn-shanghai.aliyuncs.com/mdimg/vsstudio_mysql_config6.png)

9.即可调用相关函数

# CmakeLists.txt配置

适用于clion  QT等cmake.txt配置的软件

1.需要安装MySQL

2.将文件复制到代码文件夹

3.打开CmakeLists.txt文件 输入以下代码

```c++
include_directories(${mysql安装目录}\\include)
link_directories(${MySQL安装目录}\\lib)
link_libraries(libmysql)
注意: 如果安装目录中包含空格 请输入"\ "来代替空格
```

4.在add_executable()中输入文件名

![](https://star5016-ossbucket-shanghai.oss-cn-shanghai.aliyuncs.com/mdimg/cmake_mysql_config1.png)

5.把libmysql.lib文件复制到生成可执行文件的文件夹

![](https://star5016-ossbucket-shanghai.oss-cn-shanghai.aliyuncs.com/mdimg/cmake_mysql_config2.png)

6.即可使用