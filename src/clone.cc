#ifndef BUILDING_NODE_EXTENSION
#define BUILDING_NODE_EXTENSION
#endif  // BUILDING_NODE_EXTENSION
#include <node.h>
#include "nan.h"

using Nan::New;
using Nan::GetFunction;


using namespace v8;

NAN_METHOD(Clone) {
  Nan::HandleScope scope;

  Handle<Value>arg = info[0];
  if (arg->IsObject()) {
    Handle<Object>obj = Handle<Object>::Cast(arg);
    info.GetReturnValue().Set(obj->Clone());
  }
  info.GetReturnValue().Set(arg);
}

NAN_MODULE_INIT(InitAll) {
  Nan::Set(target, New<String>("clone").ToLocalChecked(), GetFunction(New<FunctionTemplate>(Clone)).ToLocalChecked());
}

NODE_MODULE(addon, InitAll)