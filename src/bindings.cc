// tested on:
// Node.js v10.23.0 (V8 v6.8.275.32)
// Node.js v14.15.3 (V8 v8.4.371.19)
// at 2020.12.30
#include <node.h>
#include <v8.h>

// TODO: implement UNSAFE versions of digitalRead, digitalWrite, pinMode, delayMicroseconds. Store them in `unsafe` object in `exports` (see init())
// TODO: implement other core features of wiringPi/wiringOP, add other core variables

/*
currently exported functions:
    wiringPiSetup(): Number
    piBoardRev(): Number
    pinMode(pin: Number, mode: OUTPUT | INPUT): void
    digitalWrite(pin: Number, value: LOW | HIGH): void
    digitalRead(pin: Number): void
    delay(ms: Number): void
    delayMicro(mks: Number): void
*/

// used this version: https://github.com/orangepi-xunlong/wiringOP.git (latest commit: 35de0150a9c319a52badd15abe7ef172bc2e4afe @2020.12.14)
#include <wiringPi.h>

namespace wpi {
    static void wiringPiSetup       (const v8::FunctionCallbackInfo<v8::Value>& args);
    static void piBoardRev          (const v8::FunctionCallbackInfo<v8::Value>& args);
    static void pinMode             (const v8::FunctionCallbackInfo<v8::Value>& args);
    static void digitalRead         (const v8::FunctionCallbackInfo<v8::Value>& args);
    static void digitalWrite        (const v8::FunctionCallbackInfo<v8::Value>& args);
    static void delay               (const v8::FunctionCallbackInfo<v8::Value>& args);
    static void delayMicroseconds   (const v8::FunctionCallbackInfo<v8::Value>& args);
}

// Implementations

void wpi::wiringPiSetup(const v8::FunctionCallbackInfo<v8::Value>& args) {
    int res;
    auto isolate = args.GetIsolate();
    
    if (args.Length() != 0) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments (0 expected).").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    // global namespace call
    // call needed try-catch?
    res = ::wiringPiSetup();
    
    args.GetReturnValue().Set(v8::Int32::New(isolate, res));
}

void wpi::piBoardRev(const v8::FunctionCallbackInfo<v8::Value>& args) {
    int res;
    auto isolate = args.GetIsolate();
    
    if (args.Length() != 0) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments (0 expected).").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    // global namespace call
    // call needed try-catch?
    res = ::piBoardRev();
    
    args.GetReturnValue().Set(v8::Int32::New(isolate, res));
}

void wpi::pinMode(const v8::FunctionCallbackInfo<v8::Value>& args) {
    auto isolate = args.GetIsolate();
    
    if (args.Length() != 2) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments (2 expected. pin, mode).").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong argument types. Numbers expected").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    int32_t pin = args[0].As<v8::Int32>()->Value();
    int32_t mode = args[1].As<v8::Int32>()->Value();
    //int mode = args[1]->ToInt32(isolate).ToLocalChecked();
    if (!(
        mode == INPUT
        || mode == OUTPUT
        // || mode == PWM_OUTPUT
        // || mode == GPIO_CLOCK
        // || mode == SOFT_PWM_OUTPUT
        // || mode == SOFT_TONE_OUTPUT
        // || mode == PWM_TONE_OUTPUT
    )) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong mode.").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    // call needed try-catch?
    ::pinMode(pin, mode);
    
    args.GetReturnValue().SetUndefined();
}

void wpi::digitalWrite(const v8::FunctionCallbackInfo<v8::Value>& args) {
    auto isolate = args.GetIsolate();
    
    if (args.Length() != 2) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments (2 expected. pin, level).").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong argument types. Numbers expected").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    int32_t pin = args[0].As<v8::Int32>()->Value();
    int32_t value = args[1].As<v8::Int32>()->Value();
    
    if (!(
        value == HIGH
        || value == LOW
    )) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong level value (HIGH or LOW expected).").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    // call needed try-catch?
    ::digitalWrite(pin, value);
    
    
    args.GetReturnValue().SetUndefined();
}

void wpi::digitalRead(const v8::FunctionCallbackInfo<v8::Value>& args) {
    auto isolate = args.GetIsolate();
    
    if (args.Length() != 1) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments (1 expected. pin).").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    if (!args[0]->IsNumber()) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong argument type. Number expected").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    int32_t pin = args[0].As<v8::Int32>()->Value();
    
    // call needed try-catch?
    int res = ::digitalRead(pin);
    
    args.GetReturnValue().Set(v8::Int32::New(isolate, res));
}

void wpi::delay(const v8::FunctionCallbackInfo<v8::Value>& args) {
    auto isolate = args.GetIsolate();
    
    if (args.Length() != 1) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments (1 expected. howLong_ms).").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    if (!args[0]->IsNumber()) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong argument type. Number expected").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    uint32_t howLong = args[0].As<v8::Uint32>()->Value();
    
    // call needed try-catch?
    ::delay(howLong);
    
    args.GetReturnValue().SetUndefined();
}

void wpi::delayMicroseconds(const v8::FunctionCallbackInfo<v8::Value>& args) {
    auto isolate = args.GetIsolate();
    
    if (args.Length() != 1) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments (1 expected. howLong_mks).").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    if (!args[0]->IsNumber()) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong argument type. Number expected").ToLocalChecked()
        ));
        args.GetReturnValue().SetUndefined();
        return;
    }
    
    uint32_t howLong = args[0].As<v8::Uint32>()->Value();
    
    // call needed try-catch?
    ::delayMicroseconds(howLong);
    
    args.GetReturnValue().SetUndefined();
}

void init(v8::Local<v8::Object> exports, v8::Local<v8::Value> module) {
    v8::Isolate* isolate = exports->GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    
    // Functions
    NODE_SET_METHOD(exports, "wiringPiSetup", wpi::wiringPiSetup);
    NODE_SET_METHOD(exports, "piBoardRev", wpi::piBoardRev);
    NODE_SET_METHOD(exports, "pinMode", wpi::pinMode);
    NODE_SET_METHOD(exports, "digitalRead", wpi::digitalRead);
    NODE_SET_METHOD(exports, "digitalWrite", wpi::digitalWrite);
    NODE_SET_METHOD(exports, "delay", wpi::delay);
    NODE_SET_METHOD(exports, "delayMicroseconds", wpi::delayMicroseconds);
    
    exports->Set(context, v8::String::NewFromUtf8(isolate, "INPUT").ToLocalChecked(), v8::Int32::New(isolate, INPUT));
    exports->Set(context, v8::String::NewFromUtf8(isolate, "OUTPUT").ToLocalChecked(), v8::Int32::New(isolate, OUTPUT));
    
    exports->Set(context, v8::String::NewFromUtf8(isolate, "HIGH").ToLocalChecked(),  v8::Int32::New(isolate, HIGH));
    exports->Set(context, v8::String::NewFromUtf8(isolate, "LOW").ToLocalChecked(),   v8::Int32::New(isolate, LOW));
}

NODE_MODULE(wiringPi, init)