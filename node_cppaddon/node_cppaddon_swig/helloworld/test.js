#!/home/users/wuyinguang/install/node/bin/node
// node test.js 测试example模块
var example = require('./build/Release/example');
var x = example.add(1, 20);
console.log(x);

var a = new example.A();
console.log(a.add(1,2));
