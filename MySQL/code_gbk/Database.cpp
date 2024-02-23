#include "Database.h"
//���캯��
Database::Database() {
    this->m_mysql = mysql_init(new MYSQL);
    this->m_status = false;
    this->m_res = nullptr;
}
//��������
//���ʹ�ù����г��ֶ��� �뽫closeServerע�͵� ������Ҫ�Ͽ����ӵĵط����µ���
Database::~Database() {
    this->closeServer();
}

//��ʼ�����ݿ� �������ݿ����� Ĭ���� testUser ���ӱ��� 3306 �˿� �� test���ݿ�
//���ӳɹ�����true ����ʧ�ܷ���false
bool Database::InitDatabase(const char* host, const char* user, const char* password, const char* database,int port )
{
    if (mysql_real_connect(m_mysql, host, user, password, database, port, nullptr, 0)) {
        cout << "���ݿ����ӳɹ�"<<endl;
        m_status = true;
        return true;
    }
    else {
        cout<<"��¼ʧ��:" << mysql_error(m_mysql)<<endl;
        return false;
    }
}

//�ж��﷨�Ƿ���ȷ�Լ��Ƿ��ܲ�ѯ����¼
//��ѯ��������false �﷨���� false+errorDetail �ܲ鵽 true
bool Database::Query(string sql) {
    sprintf_s(m_query, "%s", sql.c_str());
    if (mysql_real_query(m_mysql, m_query, strlen(m_query))) {
        cout << "����:" << mysql_error(m_mysql)<<endl;
        return false;
    }
    else {
        m_res = mysql_store_result(m_mysql);
        if (m_res == nullptr) {
            cout << "δ��ѯ���������" << endl;
            return false;
        }
        else {
            return true;
        };

    }
}


//��¼����ʵ��  ����ֵ�ֱ����˺� ���� ��Ϣ���ڱ� 
//�����ͷΪpassword  �û�����ͷΪID
//���봫�� ����ʵ��������м���
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


//���ȫ��ָ�����
void Database::showRes(const char* sql) {
    if (!this->Query(sql)) { return; }
    m_row = mysql_fetch_row(m_res);
    if (this->m_row != nullptr) {
        while (m_row) {
            for (int i = 0; i < mysql_num_fields(m_res); i++) {
                cout << m_row[i] << " ";
            }
            cout << endl;
            m_row = mysql_fetch_row(m_res);
        }
    }
    else {
        cout << "δ��ѯ�������Ϣ" << endl;
        return;
    }
}

//��ȡָ������
//��select address from table where name = "star" and id = "0516" 
//�Ӷ���ȡaddress
string Database::getRes(const char* sql) {
    if (!this->Query(sql)) { return "Null"; }
    m_row = mysql_fetch_row(m_res);
    return m_row[0];
}

string Database::getPassword() {
    char password[31], ch; //���볤��30λ
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

//���ڶϿ����ݿ�����
void Database::closeServer()
{
    if (m_mysql) {
        mysql_close(m_mysql);
    }
}
//����ִ����ɾ�Ĳ���
bool Database::change(string sql) {
    sprintf_s(m_query, "%s", sql.c_str());
    if (mysql_real_query(m_mysql, m_query, strlen(m_query))) {
        return false;
    }
    else {
        return true;
    }
}
