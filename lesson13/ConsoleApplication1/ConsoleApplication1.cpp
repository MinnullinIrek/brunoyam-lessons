// lesson12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>


#include "Db.h"




struct A {
    int i;
    double d;
    std::string s;
};





template <typename T>
T sum(T a, T b) {
    return a + b;
}


template <typename T>
class Number {
public:
    Number(T a = 0) : value(a) {
    }

    Number  operator + (const Number& right) {
        return Number{ value + right.value };
    }

    bool operator != (const Number& right) {
        return this->value != right.value;
    }

    T get() {
        return value;
    }

    operator T() {
        return value;
    }

private:
    T value;
};




int main()
{

    {
     //   auto rs = sum<std::vector<int>>(std::vector<int>{1,2}, std::vector<int>{3,4});
    }

    std::vector<int> vec;


    Number<int> n1(10 );
    Number<int> n2( 20 );
    Number<int> n3 = n1 + n2;
    Number<float> f4(6.9f);


    int i = n3;

    std::cout << n3;


    std::string create = R"(CREATE TABLE if not exists "owners" (
        "id"    INTEGER NOT NULL UNIQUE,
        "name"    TEXT,
        PRIMARY KEY("id" AUTOINCREMENT)
        ); )";
   
        std::string insert = std::string(R"(INSERT INTO owners (name) values ("Ivan"))");
   

    std::string select = R"(SELECT * FROM owners;)";



    try {
        Db db("cars.db");
        db.exec(create);
        db.exec(insert);

        Result result = db.getResult(select);

        for (auto it = result.begin(); it != result.end(); ++it) {
            std::cout << "name " << it[1];
        }

        std::vector<int> v = {1,2,3,45,6  };  
        for (auto it = v.begin(); it != v.end(); ++it) {
            std::cout << *it;
        }


    }
    catch (const std::exception& ex)
    {
        std::cout << "error: " << ex.what();
    }


    /*



    sqlite3* db;
    sqlite3_stmt* res;
    int rc = sqlite3_open("cars.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db);
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


    for (const auto& name : { "Ivanov", "Borisov", "denis" }) {
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


    while (sqlite3_step(res) == SQLITE_ROW) {
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
    */
    return 0;
}
