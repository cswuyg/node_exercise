const m = require('./build/Release/hello')

m.foo(1, 2, (a, b, c)=>{
    console.log('finish job:' + a);
    console.log('main thread:' + b);
    console.log('work thread:' + c);
});
