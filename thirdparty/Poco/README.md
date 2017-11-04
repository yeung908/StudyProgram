# for Android build in ndk or system
   first you must setup ndk-build env
   now you just down it from git@gitlab.gz.cvte.cn:1602/android.git
   git clone git@gitlab.gz.cvte.cn:1602/android.git
   cd android/trunk
   . ./setenv.sh
   cd android/trunk/source/jnilib2.0
  ./build.sh
   then you can found the lib in android/trunk/source/jnilib2.0/libs/armeabi/libpoco.a

  sharedlibs_Android 是因为该库依赖openssl,这个库在所有android系统上都有，所以直接使用动态库
  目录中的文件只是为了编译使用，安装到系统上会自动调用系统的openssl库
  ├── include   //这个里面是openssl的依赖头文件
│   ├── ifaddrs.h //这个是android编译系统缺少的头文件 
└── libssl.so  //这个是系统的ssl库，在此仅用于编译连接
 
