#pragma once

#include <string>
#include "sqlite3.h"


class ResultIterator {
public:
	ResultIterator(sqlite3_stmt* r, int row) : res(r), rowNumber(row) {}

	bool operator != (const ResultIterator& right) {
		return this->rowNumber != right.rowNumber;
	}

	ResultIterator& operator ++ () {
		 sqlite3_step(res);
		 this->rowNumber++;
		 return (*this);
	}

	const  char* operator [] (int column) {
		return "12233";// sqlite3_column_text(res, column);
	}




private:
	sqlite3_stmt* res;
	int rowNumber = 0;
};

class Result {
private:
	sqlite3_stmt* res;
public:
	Result(sqlite3_stmt* r) : res(r) {}
	ResultIterator begin() {
		return ResultIterator(res, 0);
	}

	ResultIterator end() {
	
		int i = 0;
		while (sqlite3_step(res) != SQLITE_DONE) {
			i++;
		}
		sqlite3_reset(res);
		return ResultIterator(res, i);
	}
};

class Db
{
public:
	Db(const std::string& bdName) {
		int rc = sqlite3_open(bdName.c_str(), & db);
		if (rc != SQLITE_OK) {
			throw std::runtime_error(sqlite3_errmsg(db));
		}
	}

	void exec(const std::string& query) {
		char* errmsg;
		int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errmsg);

		if (rc != SQLITE_OK) {
			sqlite3_close(db);
			throw std::runtime_error(sqlite3_errmsg(db));
		}
	}

	Result getResult(const std::string& query) {
		
		sqlite3_stmt* res;

		//std::string query = R"(SELECT * FROM owners;)";
		
		int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &res, 0);
		
		if (rc != SQLITE_OK) {
			sqlite3_close(db);
			throw std::runtime_error(sqlite3_errmsg(db));
		}



		Result result(res);

		return result;
	}


private:
	sqlite3* db;
};

