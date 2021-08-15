# CEF Sample
A CEF based Win10 desktop sample
<img src="https://github.com/xindzju/cef_sample/blob/master/cef_sample.png" alt="cef_sample_screenshot"/>


# Prerequisites
* CEF_LIB: https://cef-builds.spotifycdn.com/index.html
    * Windows 64 bits
    * Standard Distribution

* Building CEF C++ wrapper(libcef_dll_wrapper.lib) and related file structure as below

--CMakeLists.txt\
--cef (same level of CMakeListst.txt)\
    --include(copied from CEF_LIB)\
    --Debug(copied from CEF_LIB)\
    --Release(copied from CEF_LIB)\
    --Resources(copied from CEF_LIB)\
    --wrapper\
        --debug\
            --libcef_dll_wrapper.lib(built by yourself)\
        --release\
            --libcef_dll_wrapper.lib(built by yourself)\


# How to build
```
git clone https://github.com/xindzju/cef_sample.git
mkdir build
cd build
cmake ...
```
First build the cef_sample project, then build the CopyTask project, both of them are needed.

# Reference
cef_sample: https://www.cnblogs.com/w4ngzhen/p/14323803.html\
add_custom_target/commnad: https://zhuanlan.zhihu.com/p/95771200