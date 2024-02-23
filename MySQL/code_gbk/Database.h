#ifndef LIBRARY_DATABASE_H
#define LIBRARY_DATABASE_H
#include<iostream>
#include<mysql.h>
#include<string>
#include<conio.h>
using namespace std;

class Database {

private:
    MYSQL* m_mysql; //mysql���Ӿ��
    bool m_status;//����״̬
    char m_query[1024];//��ѯ���
    MYSQL_RES* m_res;//��ѯ�����
    MYSQL_ROW m_row;//��ѯ�����

public:
    Database();//���캯��
    ~Database();//��������
    bool InitDatabase(const char* host = "localhost", const char* user = "testUser", const char* password = "testPassword", const char* database = "test", int port = 3306);
    bool Query(string sql);//��ѯ����
    bool login(string account, string password, string userTable);//��½ �û��� ��һ��Ϊid �ڶ���Ϊ����
    void showRes(const char* sql);//����������������
    string getRes(const char* sql);//��ȡָ������
    bool change(string sql);//����ɾ
    void closeServer();//��������Ͽ�����
    string getPassword();//��ȡ�û����������
};


#endif

