#include "Database.h"
//构造函数
Database::Database() {
    this->m_mysql = mysql_init(new MYSQL);
    this->m_status = false;
    this->m_res = nullptr;
}
//析构函数
//如果使用过程中出现断连 请将closeServer注释掉 并在需要断开连接的地方重新调用
Database::~Database() {
    this->closeServer();
}

//初始化数据库 用于数据库连接 默认以 testUser 连接本地 3306 端口 的 test数据库
//连接成功返回true 连接失败返回false
bool Database::InitDatabase(const char* host, const char* user, const char* password, const char* database,int port )
{
    if (mysql_real_connect(m_mysql, host, user, password, database, port, nullptr, 0)) {
        qDebug() << "数据库连接成功\n";
        m_status = true;
        return true;
    }
    else {
        qDebug()<<"登录失败:" << mysql_error(m_mysql)<<"\n";
        return false;
    }
}

//判断语法是否正确以及是否能查询到记录
//查询不到返回false 语法错误 false+errorDetail 能查到 true
bool Database::Query(string sql) {
    sprintf_s(m_query, "%s", sql.c_str());
    if (mysql_real_query(m_mysql, m_query, strlen(m_query))) {
        qDebug() << "错误:" << mysql_error(m_mysql)<<"\n";
        return false;
    }
    else {
        m_res = mysql_store_result(m_mysql);
        if (m_res == nullptr) {
            qDebug() << "未查询到相关数据" << "\n";
            return false;
        }
        else {
            return true;
        };

    }
}


//登录功能实现  输入值分别是账号 密码 信息所在表 
//密码表头为password  用户名表头为ID
//明码传递 请结合实际情况进行加密
bool Database::login(string account, string password, string userTable) {
    string sql = "select * from " + userTable + " where id = '" + account + "' and password = '" + password + "'";
    if (Query(sql)) {
        m_row = mysql_fetch_row(m_res);
        if (m_row) {
            return true;
        }
    }
    return false;
}


//输出全部指定结果
void Database::showRes(const char* sql) {
    if (!this->Query(sql)) { return; }
    m_row = mysql_fetch_row(m_res);
    if (this->m_row != nullptr) {
        while (m_row) {
            for (int i = 0; i < mysql_num_fields(m_res); i++) {
                qDebug() << m_row[i] << " ";
            }
            qDebug() << "\n";
            m_row = mysql_fetch_row(m_res);
        }
    }
    else {
        qDebug() << "未查询到相关信息" << "\n";
        return;
    }
}

//获取指定数据
//如select address from table where name = "star" and id = "0516" 
//从而获取address
string Database::getRes(const char* sql) {
    if (!this->Query(sql)) { return "Null"; }
    m_row = mysql_fetch_row(m_res);
    return m_row[0];
}

string Database::getPassword() {
    char password[31], ch; //密码长度30位
    string result;
    int i = 0;
    
    while (true)
    {
        ch = _getch();
        password[i++] = ch;
        if (ch == '\r')
        {
            password[i] = '\0';
            break;
        }
    }
    for (int j = 0; j < i - 1; j++) {
        result += password[j];
    }
    return result;
}

//用于断开数据库连接
void Database::closeServer()
{
    if (m_mysql) {
        mysql_close(m_mysql);
    }
}
//用于执行增删改操作
bool Database::change(string sql) {
    sprintf_s(m_query, "%s", sql.c_str());
    if (mysql_real_query(m_mysql, m_query, strlen(m_query))) {
        return false;
    }
    else {
        return true;
    }
}
