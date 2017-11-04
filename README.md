# 项目概述 #
MediaProcessors项目包含若干音视频处理的服务组件。目前包括AudioMixer、VideoRelay、 SDK三个主要的部分。

AudioMixer作为视频会议的混音服务组件，具备从网络接收音频数据包，对其解码、混音之后，再编码发送到网络上的功能。AudioMixer使用thrift对外提供服务接口，接受应用程序的指令在指定的端口接收合法的音频数据并对其进行混音处理，再根据应用程序的要求将混音数据发送到指定的网络地址和端口。

VideoRelay是视频转发组件，可用于视频会议转发、视频直播等场景。

SDK分为DataStream/MediaStream/ServiceAgent三个部分，分别处理白板、音视频和信令。
android子目录下包含SDK的android封装。

# 第三方库介绍 #

MediaProcessors使用了多个开源的第三方组件，包括：
* [Google gRpc](http://www.grpc.io) —— 远程过程调用中间件，支持多种编程语言间的异构通信。本项目中使用的是V1.4.x稳定版。中文文档地址为：http://doc.oschina.net/grpc?t=57966。
* [Poco C++](http://pocoproject.org) —— 跨平台的C++函数库，提供I/O、网络、日志、数据库等编程接口，支持Windows/Linux/OS X/Andriod/IOS等操作系统。使用[Boost Software License 1.0](http://pocoproject.org/license.html)开源协议。

# 编译工程 #
CMake是我们选用的AutoMake工具，各个平台的编译脚本或工程文件，都由CMake命令生成。当然我们也可以直接使用CMake build命令直接编译项目。

## CMAKE选项 ##
| 选项 | 支持平台 | 默认值 |可选值|
|:--- |:--- |:---: |:---: |
|BUILD_SDK|Windows/Android/OSX/IOS|OFF|ON/OFF|
|BUILD_SERVER|Windows/Linux|OFF|ON/OFF|
|BUILD_QTGUI|Windows|OFF|ON/OFF|
|BUILD_TEST|Windows|OFF|ON/OFF|


## Windows ##
### 环境要求 ###
* 操作系统：Windows7及以上
* Visual Studio 2013及以上，最好使用Visual Studio 2015
* NASM（用于编译BoringSSL库，需要将其加入到{ProgramFiles}环境变量所在路径下）
* YASM (用于编译Openh264等第三方库的汇编代码)
* Perl5.6.1以上（用于编译BoringSSL库，需要将其路径加入环境变量）
* Go（用于编译BoringSSL库，需要将其路径加入环境变量）
* Python2.7及以上
* CMAKE 3.6以上

示例命令
```
mkdir build
cd build
mkdir win
cd win
cmake ../.. -G"Visual Studio 14 2015 Win64" -DBUILD_SDK=ON -DBUILD_SERVER=ON
```
## Linux ##
### 环境要求 ###
* 操作系统:内核版本2.7以上
* GCC版本4.6以上


示例命令
```
mkdir build
cd build
mkdir linux
cd linux
cmake ../.. -G"Unix Makefiles"  -DBUILD_SERVER=ON
make
```

## Android ##
### 环境要求 ###
* 操作系统:Windows7及以上/OSX
* Android Studio 2.3以上，安装CMake工具
* NDK 10以上14以下，建议使用NDK13
* Perl5.6.1以上（用于编译BoringSSL库，需要将其加入环境变量）
* Go（用于编译BoringSSL库，需要将其路径加入环境变量）
* Python2.7及以上

### 编译步骤 ###
1. 使用Android Studio打开android子目录项目，编译和调试
2. 也可在命令行进入android/engine子目录，使用gradle build 或者 gradle assembleRelease编译
