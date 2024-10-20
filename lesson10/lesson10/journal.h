#pragma once
#include <unordered_map>
#include <map>
#include <string>

struct Person {
	std::string name;
	std::string adres;
	std::string telephon;
};

struct Journal
{
	void push(const std::string& name, const Person& person ) {
		telephons[name] = person;
	}

	Person get(const std::string& name) {
		return telephons[name];
	}

	std::unordered_map<std::string, Person> telephons;
};
