swig -javascript -node -c++ -DV8_VERSION=0x040599 export.i
node-gyp configure build
node test.js
