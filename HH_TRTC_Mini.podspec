Pod::Spec.new do |s|
    s.name         = "HH_TRTC_Mini"
    s.version      = "3.0.8.010712"
    s.summary      = "和缓视频医生 SDK"

    s.description  = <<-DESC
    和缓视频医生，连接千万用户和全科医生。
    DESC

    s.homepage     = "https://github.com/HHMedic/HH_TRTC_Mini"
    s.license      = "MIT"
    s.author             = { "chengyanfang" => "cumt_cyf@163.com" }
    s.social_media_url   = "https://github.com/HHMedic"

    s.platform     = :ios, "9.0"
    s.source       = { :git => "https://github.com/HHMedic/HH_TRTC_Mini.git" }
    s.default_subspec = 'Base'

    s.dependency 'TXIMSDK_iOS'

    s.subspec 'Base' do |base|
        base.vendored_frameworks = 'HH_TRTC_Mini/*.framework'

        base.frameworks = 'SystemConfiguration', 'MobileCoreServices', 'AVFoundation', 'CoreTelephony', 'VideoToolbox', 'AudioToolbox', 'CoreMedia'
        base.libraries = 'z', 'sqlite3.0', 'c++', 'resolv.9'
    end

end


