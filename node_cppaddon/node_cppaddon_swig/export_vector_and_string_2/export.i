/* File : export.i */
%module my_mod 
%include "typemaps.i"
%include "std_string.i"
%include "std_vector.i"
%{
#include "export.h"
%}

%template(VectorStr) std::vector<std::string>;

%include "export.h"

