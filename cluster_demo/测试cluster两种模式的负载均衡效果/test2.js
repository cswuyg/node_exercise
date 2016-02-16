/*
* cluster module's example 2
* 2016.02.16
* cswuyg
* */
'use strict';

var cluster = require('cluster');
cluster.schedulingPolicy = cluster.SCHED_NONE;  // attention
var http = require('http');
var cpuCount = require('os').cpus().length;

if (cluster.isMaster) {
    for (var i = 0; i < cpuCount; ++i) {
        cluster.fork();
    }
} else {
    http.createServer(function(req, res) {
        res.writeHead(200);
        res.end('hello world\n');
        console.log(cluster.worker.id);
    }).listen(8678);
}
