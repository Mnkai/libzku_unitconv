//  This is free and unencumbered software released into the public domain.
//
//  Anyone is free to copy, modify, publish, use, compile, sell, or
//  distribute this software, either in source code form or as a compiled
//  binary, for any purpose, commercial or non-commercial, and by any
//  means.
//
//  In jurisdictions that recognize copyright laws, the author or authors
//  of this software dedicate any and all copyright interest in the
//  software to the public domain. We make this dedication for the benefit
//  of the public at large and to the detriment of our heirs and
//  successors. We intend this dedication to be an overt act of
//  relinquishment in perpetuity of all present and future rights to this
//  software under copyright law.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.
//
//  For more information, please refer to <http://unlicense.org/>

#pragma once
/// @brief
///  Zku library interface header.
/// @author
///  Mayu Laierlence (minacle@live.com)
/// @version
///  0.4

#ifdef __cplusplus
extern "C" {
#endif

#define ZKU_ZSMP "ZSMP/0.4"

    /// @brief
    ///  A function that is called when the module is loaded.
    /// @param message
    ///  Configurations of the module that managed by master.
    ///  \code
    ///  sender=zku#0
    ///  type=ZSMP/0.4
    ///  name=length.dylib
    ///  ident=length.dylib#0
    ///  fullname=/Users/Zku/Application Support/Zku/length.dylib
    ///  \endcode
    /// @return
    ///  Non-zero value if the module loaded unsuccessfully.
    /// @note
    ///  This function is \e optional. You can erase this declaration if
    ///  you don't want to implement.
    int load(const char *message, long size);

    /// @brief
    ///  A function that receives all kinds of request messages.
    /// @details
    ///  A content of \c pointer parameter is INI formatted UTF-8 text.
    ///  Example request and response messages are below.
    ///  \code
    ///  sender=zku#0
    ///  type=ZSMP/0.4
    ///  timestamp=1169078400
    ///  id=0
    ///  request=42yd to m
    ///  \endcode
    ///  \code
    ///  sender=length.dylib#0
    ///  type=ZSMP/0.4
    ///  timestamp=1169078400
    ///  id=0
    ///  response=38.4048 m
    ///  \endcode
    ///  @arg
    ///   \c sender is a generator of the message. This value is \e
    ///   optional when responding.
    ///  @arg
    ///   \c type contains message type and message version. \c ZSMP is
    ///   the abbreviation for Zku Standard Message Protocol. This value is
    ///   \e required when responding.
    ///  @arg
    ///   \c timestamp is generated time of the message. This value is \e
    ///   optional when responding.
    ///  @arg
    ///   \c id is a unique key for the request message. A response message
    ///   must has equal \c id with of the request message. This value is
    ///   \e required when responding.
    ///  @arg
    ///   \c request is a query text. This value is \e prohibited when
    ///   responding.
    ///  @arg
    ///   \c response is a result text. This value is \e required when
    ///   responding.
    /// @param message
    ///  A request message.
    /// @param size
    ///  A size of the request message.
    /// @return
    ///  A pointer which contains response message. Can be null pointer.
    /// @note
    ///  This function is \e required. You must implement this function.
    void *execute(const char *message, long size);

    /// @brief
    ///  A function that is called when the module will be unloaded.
    /// @param message
    ///  Empty message with master ident.
    ///  \code
    ///  sender=zku#0
    ///  type=ZSMP/0.4
    ///  \endcode
    /// @return
    ///  Non-zero value if the module loaded unsuccessfully.
    /// @note
    ///  This function is \e optional. You can erase this declaration if
    ///  you don't want to implement.
    int unload(const char *message, long size);

#ifdef __cplusplus
}
#endif
