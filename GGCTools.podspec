@version = "0.0.1"

Pod::Spec.new do |s| 
s.name = "GGCTools" 
s.version = @version 
s.summary = "ios日常开发用到的工具" 
s.description = "封装了GCD，定义了一些常用的宏" 
s.homepage = "https://github.com/GoGoCoding/HQTools" 
s.license = { :type => 'MIT', :file => 'LICENSE' } 
s.author = { "HaoQi" => "it_haoqi@163.com" } 
s.ios.deployment_target = '8.0' 
s.source = { :git => "https://github.com/GoGoCoding/HQTools.git", :tag => "v#{s.version}" } 
s.source_files = 'Tools/*.{h,m}' 
s.requires_arc = true 
s.framework = "UIKit" 
end
