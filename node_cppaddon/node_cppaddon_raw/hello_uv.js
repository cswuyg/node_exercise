// test helloUV module
'use strict';
const m = require('helloUV')

m.foo(1, 2, (a, b, c)=>{
    console.log('finish job:' + a);
    console.log('main thread:' + b);
    console.log('work thread:' + c);
});
/*
output:
finish job:3
main thread:139660941432640
work thread:139660876334848

*/