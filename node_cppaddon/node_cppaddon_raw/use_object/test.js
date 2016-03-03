'use strict';
const m = require('./build/Release/hello')
var input = {a: 1, 
             b: 2,
             c: [3, 4, '5']}
var ret = m.foo(input);
console.log('----------');
console.log(ret.a);
