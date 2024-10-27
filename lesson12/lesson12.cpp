// lesson12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

#include "sqlite3.h"

int main()
{
    sqlite3* db;
    sqlite3_stmt* res;
    int rc = sqlite3_open("cars.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) ;
        sqlite3_close(db);
        return 1;
    }

    std::string create = R"(CREATE TABLE if not exists "owners" (
        "id"    INTEGER NOT NULL UNIQUE,
        "name"    TEXT,
        PRIMARY KEY("id" AUTOINCREMENT)
        ); )";

    char* errmsg;

    rc = sqlite3_exec(db, create.c_str(), nullptr, nullptr, &errmsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot create table: " << errmsg;
        sqlite3_close(db);
        return 1;
    }


    for (const auto& name : { "Ivanov", "Borisov", "denis"}) {
        std::string insert = std::string(R"(INSERT INTO owners (name) values (")") + name + "\")";
        rc = sqlite3_exec(db, insert.c_str(), nullptr, nullptr, &errmsg);
        if (rc != SQLITE_OK) {
            std::cerr << "Cannot create table: " << errmsg;
            sqlite3_close(db);
            return 1;
        }
    }


    std::string select = R"(SELECT * FROM owners;)";
    rc = sqlite3_prepare_v2(db, select.c_str(), -1, &res, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot create table: " << sqlite3_errmsg(db);
        sqlite3_close(db);
        return 1;
    }


    while(sqlite3_step(res) == SQLITE_ROW) {
        std::cout << "\nid = " << sqlite3_column_int(res, 0) << " "
            << "name = " << sqlite3_column_text(res, 1);
    }

    std::string del = R"(DELETE FROM owners;)";
    rc = sqlite3_exec(db, del.c_str(), nullptr, nullptr, &errmsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot create table: " << errmsg;
        sqlite3_close(db);
        return 1;
    }

    sqlite3_finalize(res);
    sqlite3_close(db);

    return 0;
}
