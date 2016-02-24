/*
* Node.js cpp Addons demo: async call and call back.
* gcc 4.8.2
* author:cswuyg
* Date:2016.02.22
* */
#include <iostream>
#include <node.h>
#include <uv.h> 
#include <sstream>
#include <unistd.h>
#include <pthread.h>

namespace cpphello {
    using v8::FunctionCallbackInfo;
    using v8::Function;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::Value;
    using v8::Exception;
    using v8::Persistent;
    using v8::HandleScope;
    using v8::Integer;
    using v8::String;

    // async task
    struct MyTask{
        uv_work_t work;
        int a{0};
        int b{0};
        int output{0};
        unsigned long long work_tid{0};
        unsigned long long main_tid{0};
        Persistent<Function> callback;
    };

    // async function
    void query_async(uv_work_t* work) {
        MyTask* task = (MyTask*)work->data;
        task->output = task->a + task->b;
        task->work_tid = pthread_self();
        usleep(1000 * 1000 * 1); // 1 second
    }

    // async complete callback
    void query_finish(uv_work_t* work, int status) {
        Isolate* isolate = Isolate::GetCurrent();
        HandleScope handle_scope(isolate);
        MyTask* task = (MyTask*)work->data;
        const unsigned int argc = 3;
        std::stringstream stream;
        stream << task->main_tid;
        std::string main_tid_s{stream.str()};
        stream.str("");
        stream << task->work_tid;
        std::string work_tid_s{stream.str()};
        
        Local<Value> argv[argc] = {
            Integer::New(isolate, task->output), 
            String::NewFromUtf8(isolate, main_tid_s.c_str()),
            String::NewFromUtf8(isolate, work_tid_s.c_str())
        };
        Local<Function>::New(isolate, task->callback)->Call(isolate->GetCurrentContext()->Global(), argc, argv);
        task->callback.Reset();
        delete task;
    }

    // async main
    void async_foo(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        HandleScope handle_scope(isolate);
        if (args.Length() != 3) {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "arguments num : 3")));
            return;
        } 
        if (!args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsFunction()) {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "arguments error")));
            return;
        }
        MyTask* my_task = new MyTask;
        my_task->a = args[0]->ToInteger()->Value();
        my_task->b = args[1]->ToInteger()->Value();
        my_task->callback.Reset(isolate, Local<Function>::Cast(args[2]));
        my_task->work.data = my_task;
        my_task->main_tid = pthread_self();
        uv_loop_t *loop = uv_default_loop();
        uv_queue_work(loop, &my_task->work, query_async, query_finish); 
    }

    void Init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "foo", async_foo);
    }

    NODE_MODULE(cpphello, Init)
}

