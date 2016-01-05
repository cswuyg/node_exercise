/**                                                                                                                                                                                                               
 *  * @file 长连接测试服务器
 *  * 启动： node persistent.js
 *  * ./a.html 为同目录下的ajax请求测试文件
 *  * @authoer cswuyg
 *   */
var os = require('os');
var http = require('http');
var fs = require('fs');

var server = http.createServer(function(req, res) {
    if (/^\/a.html/.test(req.url)) {
        fs.createReadStream('a.html').pipe(res);
    } else {
        console.log(req.connection.remoteAddress + ':' + req.connection.remotePort);
        res.writeHead(200, {'Content-Type': 'text/plain'});
        res.end('Hello World\n');
    }
}).listen(8124);
server.setTimeout(0);   //服务端不会主动关闭连接

console.log('start ' + os.hostname() + ':8124');
