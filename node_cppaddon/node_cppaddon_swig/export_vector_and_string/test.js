/*
* cswuyg 
* 2016.01.12
* */
var demo = require('./build/Release/my_mod.node');


// test int + int
console.log(demo.add(1, 20));


// test vector
var vec = demo.test(10);
console.log('--------test vector<int>--------');
for (var i = 0; i < vec.size(); ++i) {
    console.log(vec.get(i));
}
console.log('--------test vector<int> end --------');

var vec = demo.test("abc");
console.log('--------test vector<std::string>--------');
for (var i = 0; i < vec.size(); ++i) {
    console.log(vec.get(i));
}
console.log('--------test vector<std::string> end--------');


// test string + string
console.log(demo.append("a", "b"));


// test string point ret
console.log(demo.point_ret()[0]);
console.log(demo.sub2(10, 20)[0]);
var x = demo.two_ret(10, "abcd");
console.log(x[0]);
console.log(x[1]);
console.log(demo.ref_ret()[0]);

/*
 output:
 21
 --------test vector<int>--------
 10
 10
 20
 --------test vector<int> end --------
 --------test vector<std::string>--------
 abc
 start
 end
 --------test vector<std::string> end--------
 ab
 all info
 -10
 10
 abcd
 hello cswuyg
 * */
