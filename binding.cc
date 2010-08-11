#include <v8.h>
#include <node.h>
#include <stdlib.h>
#include <unistd.h>

#include "binding.h"

using namespace v8;
using namespace node;

extern "C" void init (Handle<Object> target) {
  HandleScope scope;
  NODE_SET_METHOD(target, "fork", ProcessControl::Fork);
}

Handle<Value> ProcessControl::Fork(const Arguments& args) {
    HandleScope scope;
    Local<Value> pid_return;
    
    int child_pid = fork();
    if(child_pid == 0){
      pid_return = Integer::New(0);
      // since node statically sets it's PID at startup, we need to reset it
      Local<Object> process = v8::Context::GetCurrent()->Global();
      Local<Object> node_obj = process->Get(String::NewSymbol("process"))->ToObject();
      node_obj->Set(String::New("pid"), Integer::New(getpid())); 
    } else {
      pid_return = Integer::New(child_pid);
    }

    return scope.Close(pid_return);
}

