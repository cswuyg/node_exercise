/* File : export.i */
%module my_mod 
%include "typemaps.i"
%include "std_string.i"
%include "std_vector.i"
%{
#include "export.h"
%}

%apply int *OUTPUT { int *result, int* xx};
%apply std::string *OUTPUT { std::string* result, std::string* yy };
%apply std::string &OUTPUT {std::string& result};
%apply unsigned int &OUTPUT {unsigned int&};

%template(vectori) std::vector<int>;
%template(vectorstr) std::vector<std::string>;

%include "export.h"

