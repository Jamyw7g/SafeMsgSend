#import <Foundation/Foundation.h>
#import <objc/message.h>
#import <objc/runtime.h>


#ifndef SAFE_MSG_SEND

#define SAFE_MSG_SEND(retType, receiver, sel, ...) \
({ \
    __typeof__(receiver) _r = (receiver); \
    SEL _s = (sel); \
    retType _ret = (retType){ 0 }; \
    if ([_r respondsToSelector:_s]) { \
        _ret = ((retType (*)(id, SEL, ...))objc_msgSend)(_r, _s, ##__VA_ARGS__); \
    } \
    _ret; \
})

#endif

#ifndef SAFE_MSG_SEND_SUPER

#define SAFE_MSG_SEND_SUPER(retType, super_receiver, sel, ...) \
({ \
    __typeof__(super_receiver) _r = (super_receiver); \
    SEL _s = (sel); \
    retType _ret = (retType){ 0 }; \
    Class _cls = object_getClass(_r); \
    Class _superCls = class_getSuperclass(_cls); \
    if (class_respondsToSelector(_superCls, _s)) { \
        struct objc_super _superInfo = { \
            .receiver = _r, \
            .super_class = _superCls \
        }; \
        _ret = ((retType (*)(struct objc_super *, SEL, ...))objc_msgSendSuper)(&_superInfo, _s, ##__VA_ARGS__); \
    } \
    _ret; \
})

#endif
