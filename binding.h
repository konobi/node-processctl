#ifndef STATEMENT_H
#define STATEMENT_H

#include <v8.h>
#include <node.h>
#include <stdlib.h>
#include <unistd.h>

using namespace v8;
using namespace node;

class ProcessControl {
  public:
    static void Init(v8::Handle<Object> target);
    static Handle<Value> Fork(const Arguments& args);
};

#endif
