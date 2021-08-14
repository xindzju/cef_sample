# CEF Sample
A CEF based application

# Prerequisites
* CEF_LIB: https://cef-builds.spotifycdn.com/index.html
    * Windows 64 bits
    * Standard Distribution

* Building CEF C++ wrapper(libcef_dll_wrapper.lib) and related file structure as below
-CMakeLists.txt
-cef (same level of CMakeListst.txt)
    -include(copied from CEF_LIB)
    -Debug(copied from CEF_LIB)
    -Release(copied from CEF_LIB)
    -wrapper
        -debug
            -libcef_dll_wrapper.lib(built by yourself)
        -release
            -libcef_dll_wrapper.lib(built by yourself)

# Reference
https://www.cnblogs.com/w4ngzhen/p/14323803.html
