/*
* cluster module's example
* node helloworld.js
* more cluster infomation: https://nodejs.org/api/cluster.html
* 2016.02.16
* cswuyg
* */
'use strict';

var cluster = require('cluster');
var http = require('http');
var cpuCount = require('os').cpus().length;


if (cluster.isMaster) {
    console.log('cpu count' + cpuCount);
    console.log('master start...');
    function my_fork() {
        var worker = cluster.fork();
        worker.send('hi worker');  // send msg to worker
        worker.on('message', (msg)=>{ // receive msg from worker
            console.log('[master] get msg from worker: '  + msg);
        });
    }
    for (var i = 0; i < 2; ++i) {
        my_fork();
    }
    cluster.on('listening', (worker, address)=>{
        console.log('listenning: worker ' + worker.process.pid + ' Address: ' + address.address + ':' + address.port);
    });
    cluster.on('exit', (worker, code, signal)=>{
        console.log('worker ' + worker.process.pid + ' died');
        my_fork();
    });
} else {
    process.on('message', (msg)=>{ // receive msg from master
        console.log('[worker' + cluster.worker.id + '] get msg from master:' + msg); 
        });
    http.createServer((req, res)=>{
        res.writeHead(200);
        res.end('hello world\n');
        process.send('get request, worker id: ' + cluster.worker.id); // send msg to master process
    }).listen(8678);
}