# SafeMsgSend

`SafeMsgSend` is a header-only Objective-C pod that provides safer macro wrappers
for `objc_msgSend` and `objc_msgSendSuper`.

## Features

- `SAFE_MSG_SEND`: Checks whether the receiver responds to the selector before invoking `objc_msgSend`.
- `SAFE_MSG_SEND_SUPER`: Checks whether the superclass responds to the selector before invoking `objc_msgSendSuper`.
- Returns a zero-initialized fallback value (`(retType){ 0 }`) when a call cannot be performed.

## Project Structure

```text
SafeMsgSend/
├── LICENSE
├── README.md
├── SafeMsgSend.podspec
└── Sources/
    └── SafeMsgSend/
        └── SafeMsgSend.h
```

## Installation

### CocoaPods

```ruby
pod 'SafeMsgSend', :git => 'https://your.git.repo/SafeMsgSend.git', :tag => '0.1.0'
```

For local development:

```ruby
pod 'SafeMsgSend', :path => '../safe_msgSend'
```

## Usage

```objc
#import <SafeMsgSend/SafeMsgSend.h>

SEL sel = @selector(length);
NSUInteger length = SAFE_MSG_SEND(NSUInteger, @"hello", sel);

// Call with arguments
BOOL ok = SAFE_MSG_SEND(BOOL, @"SafeMsgSend", @selector(hasPrefix:), @"Safe");
```

```objc
#import <SafeMsgSend/SafeMsgSend.h>

// Super call example
(void)SAFE_MSG_SEND_SUPER(void, self, @selector(viewDidLoad));
```

## Macro Signatures

- `SAFE_MSG_SEND(retType, receiver, sel, ...)`
- `SAFE_MSG_SEND_SUPER(retType, super_receiver, sel, ...)`

## Notes

- This library relies on Clang statement-expression syntax (`({ ... })`).
- `retType` must match the method's actual return type.
- `SAFE_MSG_SEND_SUPER` infers the superclass from `object_getClass(receiver)`.
- Verify ABI behavior when working with struct or other complex return types.

## License

MIT
