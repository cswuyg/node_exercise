/*
* cswuyg 
* 2016.01.13
* */
var demo = require('./build/Release/my_mod.node');
var input_array = new demo.VectorStr();
input_array.add("hello");
input_array.add("world");
var ret_array = demo.show(input_array);
for (var i = 0; i != ret_array.size(); ++i) {
    console.log(ret_array.get(i));
}