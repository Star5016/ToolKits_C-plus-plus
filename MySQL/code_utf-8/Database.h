#ifndef LIBRARY_DATABASE_H
#define LIBRARY_DATABASE_H
#include<iostream>
#include<mysql.h>
#include<string>
#include<conio.h>
using namespace std;

class Database {

private:
    MYSQL* m_mysql; //mysql连接句柄
    bool m_status;//连接状态
    char m_query[1024];//查询语句
    MYSQL_RES* m_res;//查询结果集
    MYSQL_ROW m_row;//查询结果行

public:
    Database();//构造函数
    ~Database();//析构函数
    bool InitDatabase(const char* host = "localhost", const char* user = "testUser", const char* password = "testPassword", const char* database = "test", int port = 3306);
    bool Query(string sql);//查询储存
    bool login(string account, string password, string userTable);//登陆 用户表 第一个为id 第二个为姓名
    void showRes(const char* sql);//输出储存的所有内容
    string getRes(const char* sql);//获取指定内容
    bool change(string sql);//增改删
    void closeServer();//与服务器断开连接
    string getPassword();//获取用户输入的密码
};


#endif

