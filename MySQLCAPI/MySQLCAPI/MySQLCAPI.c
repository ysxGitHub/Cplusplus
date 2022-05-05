// MySQLCAPI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <mysql.h>

int main()
{
    // 1. 初始化连接环境
    MYSQL* mysql = mysql_init(NULL);
    if (mysql == NULL) {
        printf("mysql_init() error\n");
        return -1;
    }

    // 2.连接数据库服务器
    mysql = mysql_real_connect(mysql,
        "localhost", // mysql服务器的主机地址, 写IP地址即可 (localhost/NULL 代表本地连接)
        "root", // 连接mysql服务器的用户名, 默认: root
        "111",   // 连接mysql服务器用户对应的密码, root用户的密码
        "mybase",  // 要使用的数据库的名字
        3306,  // 连接的mysql服务器监听的端口, 如果==0, 使用mysql的默认端口3306, !=0, 使用指定的这个端口
        NULL, // 本地套接字, 不使用指定为 NULL
        0);

    if (mysql == NULL) {
        printf("mysql_real_connect() error\n");
        return -1;
    }

    printf("mysql api使用的默认编码: %s\n", mysql_character_set_name(mysql));
    // 设置编码为utf-8
    mysql_set_character_set(mysql, "utf8");
    printf("mysql api使用的修改之后的编码: %s\n", mysql_character_set_name(mysql));
    printf("恭喜, 连接数据库服务器成功了...\n");

    // 3. 执行一个SQL语句
    // 查询 mybase 数据库下的 t_user
    const char* sql = "select * from t_user";
    // 执行这个sql语句
    int ret = mysql_query(mysql, sql);
    if (ret != 0) {
        printf("mysql_query() 失败了, 原因: %s\n", mysql_error(mysql));
        return -1;
    }
    
    // 4.取出结果集
    MYSQL_RES* res = mysql_store_result(mysql);
    if (res == NULL) {
        printf("mysql_store_result() 失败了, 原因: %s\n", mysql_error(mysql));
        return -1;
    }

    // 5. 得到结果集中的列数
    int num = mysql_num_fields(res);
    
    // 6. 得到所有列的名字， 并且输出
    MYSQL_FIELD* fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i) {
        printf("%s\t\t", fields[i].name);
    }
    printf("\n");

    // 7.遍历结果集中所有的行
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res)) != NULL) {
        // 得到结果集中字段的长度
        unsigned long* lenghts = mysql_fetch_lengths(res);
        // 将当前行中的每一行信息读出
        for (int i = 0; i < num; ++i) {
            printf("%s(length = %ul)\t\t", row[i], lenghts[i]);
        }
        printf("\n");
    }

    // 8.释放资源 - 结果集
    mysql_free_result(res);
    
    // 9.写数据库
    // 以下三条是一个完整的操作，对应的是一个事务
    // 设置事务为手动提交
    mysql_autocommit(mysql, 0);
    int ret1 = mysql_query(mysql, "delete from t_user where id = 2");
    int ret2 = mysql_query(mysql, "delete from t_user where id = 3");
    int ret3 = mysql_query(mysql, "delete from t_user where id = 4");
    printf("ret = %d, ret2 = %d, ret3 = %d\n", ret1, ret2, ret3);
    if (ret1 == 0 && ret2 == 0 && ret3 == 0) {
        // 提交事务
        printf("已经提交事务\n");
        mysql_commit(mysql);
    }
    else {
        // 事务回滚
        printf("已经回滚事务, 请检查你的SQL语句是否有错误\n");
        mysql_rollback(mysql);
    }

    // 9.写数据库
    // 以下三条是一个完整的操作，对应的是一个事务
    // 设置事务为手动提交
    mysql_autocommit(mysql, 0);
    ret1 = mysql_query(mysql, "insert into t_user values(2, 'ls')");
    ret2 = mysql_query(mysql, "insert into t_user values(3, 'ww')");
    ret3 = mysql_query(mysql, "insert into t_user values(4, 'll')");
    printf("ret = %d, ret2 = %d, ret3 = %d\n", ret1, ret2, ret3);
    if (ret1 == 0 && ret2 == 0 && ret3 == 0) {
        // 提交事务
        printf("已经提交事务\n");
        mysql_commit(mysql);
    }
    else {
        // 回滚事务
        printf("已经回滚事务, 请检查你的SQL语句是否有错误\n");
        mysql_rollback(mysql);
    }
    // 释放数据库资源
    mysql_close(mysql);
    
    return 0;
}


