/**
C++ has virtual function for Python 
cswuyg@gmail.com
2014.1.14
*/
#pragma once
#include <string>
#include <vector>
#include <iostream>


int add(int a, int b);
std::vector<int> test(int a);
std::string append(const std::string& a, const std::string& b); 
std::vector<std::string> test(std::string a);
void point_ret(std::string* result);
void sub2(int x, int y, int* result);
void two_ret(int x, const std::string& y, int* xx, std::string* yy);
void ref_ret(std::string& result);
void get(unsigned int a, unsigned int& b);
