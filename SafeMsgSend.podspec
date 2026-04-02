Pod::Spec.new do |s|
  s.name             = 'SafeMsgSend'
  s.version          = '0.1.0'
  s.summary          = 'Header-only Objective-C macros for safer objc_msgSend and objc_msgSendSuper.'
  s.description      = <<-DESC
SafeMsgSend provides two header-only macros for safer dynamic Objective-C message dispatch:
SAFE_MSG_SEND and SAFE_MSG_SEND_SUPER.
The library validates selector availability before invoking runtime message send APIs.
  DESC

  s.homepage         = 'https://github.com/Jamyw7g/SafeMsgSend'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Jamyw7g' => 'jamykp@gmail.com' }
  s.source           = { :git => 'https://github.com/Jamyw7g/SafeMsgSend.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.osx.deployment_target = '10.13'

  s.requires_arc         = false
  s.source_files         = 'Sources/SafeMsgSend/*.h'
  s.public_header_files  = 'Sources/SafeMsgSend/*.h'
  s.header_mappings_dir  = 'Sources'
end
