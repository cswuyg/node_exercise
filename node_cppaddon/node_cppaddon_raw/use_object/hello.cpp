/* test input json object from Javascript to Cpp
 * input: {a: 1, b: 2, c:[3,4,'5']}
 * output: {a: a_value}
 * cswuyg@gmail.conm
 * 
 * */
#include <node.h>
#include <iostream>

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
    using v8::Array;
    using v8::Uint32;
    using v8::JSON;

    void Foo(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        HandleScope handle_scope(isolate);
        if (args.Length() != 1) {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "arguments error")));
            return;
        }
        // test input object
        if (args[0]->IsObject()) {
            Local<Object> input_obj = args[0]->ToObject();

            Local<Value> key_a = String::NewFromUtf8(isolate, "a"); 
            Local<Value> num_a = input_obj->Get(key_a);
            std::cout << "a: " << num_a->ToInteger()->Value() << std::endl;

            Local<Value> key_b = String::NewFromUtf8(isolate, "b");
            Local<Value> num_b = input_obj->Get(key_b);
            std::cout << "b: " << num_b->ToInteger()->Value() << std::endl;

            Local<Value> key_c = String::NewFromUtf8(isolate, "c");
            Local<Value> array_c = input_obj->Get(key_c);
            std::cout << "C: ";
            if (array_c->IsArray()) {
                std::cout << "[";
                Local<Array> array = Local<Array>::Cast(array_c);
                for (unsigned int i = 0; i != array->Length(); ++i) {
                    Local<Value> ele = array->Get(i);
                    if (ele->IsNumber()) {
                        std::cout << ele->ToInteger()->Value() << std::endl;
                    } else if (ele->IsString()) {
                        std::cout << std::string(*(String::Utf8Value)ele->ToString()) << std::endl;
                    }
                }
                std::cout << "]" << std::endl;
            }
        } else {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "arguments error")));
            return;
        }
        // test output object;
        std::string output_str = "{\"a\":\"a_value\"}";
        Local<String> output_v8_str = String::NewFromUtf8(isolate, output_str.c_str());
        v8::MaybeLocal<Value> output_obj = JSON::Parse(isolate, output_v8_str);
        Local<Value> ret_obj;
        if (!output_obj.ToLocal(&ret_obj)) {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "convert error")));
            return;
        } else {
            args.GetReturnValue().Set(ret_obj);
        }

        /*Local<Object> ret = Object::New(isolate);
        Local<Value> ret_key_a = String::NewFromUtf8(isolate, "a");
        Local<Value> ret_val_a = Uint32::New(isolate, 100);
        ret->Set(ret_key_a, ret_val_a);
        args.GetReturnValue().Set(ret);*/
    }

    void Init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "foo", Foo);
    }

    NODE_MODULE(cpphello, Init)
}

