编译方法：  
swig -javascript -node -c++ -DV8_VERSION=0x040599 example.i  
node-gyp configure build  


说明：DV8_VERSION指定V8版本  



实现：
跟其它语言使用swig类似，要有一个*.i文件，指定导出的内容，然后使用swig生成代码，把*wrap跟实现文件合在一起编译生成插件。  
