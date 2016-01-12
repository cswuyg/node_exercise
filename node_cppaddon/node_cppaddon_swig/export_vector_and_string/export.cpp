#include "export.h"

int add(int a, int b) {
	return a + b;
}

std::vector<int> test(int a) {
	std::vector<int> v_a;
	v_a.push_back(a);
	v_a.push_back(10);
	v_a.push_back(20);
	return v_a;
}

std::string append(const std::string& a, const std::string& b) {
	return a + b;
}

std::vector<std::string> test(std::string a) {
	std::vector<std::string> a_v;
	a_v.push_back(a);
	a_v.push_back("start");
	a_v.push_back("end");
	return a_v;
}

void point_ret(std::string* result) {
    *result = "all info";
}

void sub2(int x, int y, int* result) {
    *result = x - y;
}

void two_ret(int x, const std::string& y, int* xx, std::string* yy) {
    *xx = x;
    *yy = y;
}

void ref_ret(std::string& result) {
    result = "hello cswuyg";
}

void get(unsigned int a, unsigned int& b) {
    b = a;
}
