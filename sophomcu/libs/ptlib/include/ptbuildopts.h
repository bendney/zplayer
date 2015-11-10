/* include/ptbuildopts.h.  Generated from ptbuildopts.h.in by configure.  */
/*
 * buildopts.h
 *
 * Build options generated by the configure script.
 *
 * Portable Windows Library
 *
 * Copyright (c) 2003 Equivalence Pty. Ltd.
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is Portable Windows Library.
 *
 * The Initial Developer of the Original Code is Equivalence Pty. Ltd.
 *
 * Contributor(s): ______________________________________.
 *
 * $Log: ptbuildopts.h.in,v $
 * Revision 1.64  2007/10/03 01:18:34  rjongbloed
 * Fixed build for Windows Mobile 5 and added Windows Mobile 6
 *
 * Revision 1.63  2007/09/30 17:34:39  dsandras
 * Killed GCC 4.2 warnings.
 *
 * Revision 1.62  2007/08/26 12:24:59  rjongbloed
 * Changes to allow for 64 bit builds and 64 bit library linking.
 *
 * Revision 1.61  2007/08/21 10:33:32  rjongbloed
 * Improved build/configure of direct sound.
 *
 * Revision 1.60  2007/06/18 18:23:00  dsandras
 * Added patch from Elaine Xiong <elaine xiong sun com> to optimize
 * color space conversions using MediaLib.
 *
 * Revision 1.59  2007/06/09 17:25:47  dsandras
 * Integrated DirectShow support from Luc Saillard <luc saillard org> with
 * the help of Matthias Schneider <ma30002000 yahoo de>.
 *
 * Revision 1.58  2007/05/19 08:54:42  rjongbloed
 * Further integration of DirectSound plugin thanks to Vincent Luba.and NOVACOM (http://www.novacom.be).
 *
 * Revision 1.57  2007/02/01 05:04:20  csoutheren
 * Allow compilation without C++ exceptions enabled
 *
 * Revision 1.56  2006/07/18 05:17:24  csoutheren
 * Added shared memory video devices
 * Thanks to Hannes Friederich
 *
 * Revision 1.55  2006/07/05 13:51:29  shorne
 * small typo fixed
 *
 * Revision 1.54  2006/06/29 08:31:59  csoutheren
 * Fixed problems with loading new OpenSSL
 * Fixed problems with loadeding pre-packaged Win Expat
 *
 * Revision 1.53  2006/06/29 02:34:23  csoutheren
 * Add support for other Windows OpenSSL and Expat packages
 *
 * Revision 1.52  2006/06/25 11:20:23  csoutheren
 * Add detection of ODBC on Windows
 *
 * Revision 1.51  2006/02/23 00:27:19  csoutheren
 * Fixed incorrectly applied patch
 *
 * Revision 1.50  2006/02/22 11:22:34  csoutheren
 * Applied patch #1408645
 * Endianess patch for MacOSX
 *
 * Revision 1.49  2006/02/20 06:49:45  csoutheren
 * Added video file and video file input device code
 *
 * Revision 1.48  2006/02/08 04:02:24  csoutheren
 * Added ability to enable and disable socket aggregation
 *
 * Revision 1.47  2005/11/25 00:06:12  csoutheren
 * Applied patch #1364593 from Hannes Friederich
 * Also changed so PTimesMutex is no longer descended from PSemaphore on
 * non-Windows platforms
 *
 * Revision 1.46  2005/10/17 01:25:05  csoutheren
 * Added check for ssl with const argumetns
 *
 * Revision 1.45  2005/09/25 10:51:23  dominance
 * almost complete the mingw support. We'll be there soon. ;)
 *
 * Revision 1.44  2005/09/23 15:30:46  dominance
 * more progress to make mingw compile nicely. Thanks goes to Julien Puydt for pointing out to me how to do it properly. ;)
 *
 * Revision 1.43  2005/08/25 00:35:04  dereksmithies
 * Add linux test to check for the presence of openssl/aes.h which sets P_SSL_AES
 *
 * Revision 1.42  2005/08/24 12:48:39  rjongbloed
 * Added configuration define for AEC encryption
 *
 * Revision 1.41  2005/08/04 19:46:51  csoutheren
 * Applied patch #1240770
 * Fixed problem with compilation under Solaris 10
 * Thanks to Boris Pavacic
 *
 * Revision 1.40  2005/04/27 12:08:11  csoutheren
 * Added support for res_minit for thread-safe resolver access
 * Added mutex when res_minit not available
 *
 * Revision 1.39  2005/01/26 05:37:39  csoutheren
 * Added ability to remove config file support
 *
 * Revision 1.38  2005/01/03 12:48:41  csoutheren
 * Added new configure options and ability to disable/enable modules
 *
 * Revision 1.37  2004/11/17 12:50:44  csoutheren
 * Win32 DCOM support, thanks to Simon Horne
 *
 * Revision 1.36  2004/11/16 00:24:38  csoutheren
 * Added Cygwin support
 *
 * Revision 1.35  2004/08/24 07:08:13  csoutheren
 * Added use of recvmsg to determine which interface UDP packets arrive on
 *
 * Revision 1.34  2004/06/01 07:42:19  csoutheren
 * Restored memory allocation checking
 * Added configure flag to enable, thanks to Derek Smithies
 *
 * Revision 1.33  2004/04/28 11:26:42  csoutheren
 * Hopefully fixed SASL and SASL2 problems
 *
 * Revision 1.32  2004/04/21 11:22:48  csoutheren
 * Modified to work with gcc 3.4.0
 *
 * Revision 1.31  2004/04/18 12:06:06  csoutheren
 * Added classes for SASL authentication
 * Thanks to Federico Pinna and Reitek S.p.A.
 *
 * Revision 1.30  2004/04/11 07:58:07  csoutheren
 * Added configure.in check for recursive mutexes, and changed implementation
 * without recursive mutexes to use PCriticalSection or atomic word structs
 *
 * Revision 1.29  2004/04/11 06:15:27  csoutheren
 * Modified to use Atomic_word if available
 *
 * Revision 1.28  2004/04/09 11:54:46  csoutheren
 * Added configure.in check for STL streams, and tested with gcc 2.95.3,
 * gcc 3.3.1, and gcc 3.3.3
 *
 * Revision 1.27  2004/04/03 23:53:08  csoutheren
 * Added various changes to improce compatibility with the Sun Forte compiler
 *   Thanks to Brian Cameron
 * Added detection of readdir_r version
 *
 * Revision 1.26  2004/03/23 04:56:23  csoutheren
 * Added patches to use XPG6 threading under Linux if available
 * Thanks to Matthew Hodgson
 *
 * Revision 1.25  2004/02/04 02:34:38  csoutheren
 * Added many new flags to configure to allow disabling of various features
 * Fixed "swab" detection
 * Improved detection of long double type
 *
 * Revision 1.24  2004/01/30 00:52:58  csoutheren
 * Moved P_USE_PRAGMA back to the compiler flags as this cannot be
 * put into a include file due to the way gcc implements vtable closure
 *
 * Revision 1.23  2004/01/29 13:43:59  csoutheren
 * Moved some preprocessor symbols from the command line to include files
 * Modified to set P_HAS_SEMAPHORES to 0 for Linux kernels >= 2.6
 * Applied patches for Solaris thanks to Michal Zygmuntowicz
 *
 * Revision 1.22  2004/01/27 10:50:29  csoutheren
 * Added versio information to ptbuildopts.h
 *
 * Revision 1.21  2003/12/02 08:34:44  rogerhardiman
 * Tidy some comments
 *
 * Revision 1.20  2003/11/12 03:29:51  csoutheren
 * Initial version of plugin code from Snark of GnomeMeeting with changes
 *    by Craig Southeren of Post Increment
 *
 * Revision 1.19  2003/11/06 09:13:20  rjongbloed
 * Improved the Windows configure system to allow multiple defines based on file existence. Needed for SDL support of two different distros.
 *
 * Revision 1.18  2003/10/30 11:23:53  rjongbloed
 * Added direcetory name for Speech API under Windows.
 * Added automatic inclusion of Winsock2 library.
 *
 * Revision 1.17  2003/10/27 03:42:15  csoutheren
 * Added support for QoS detection
 *
 * Revision 1.16  2003/10/23 20:43:38  dereksmithies
 * Add fix for SDL video on Visual C. Thanks to Walter Whitlock.
 *
 * Revision 1.15  2003/10/20 23:13:26  csoutheren
 * Restored after deletion by Damien
 *
 * Revision 1.13  2003/09/17 09:00:59  csoutheren
 * Moved PSmartPointer and PNotifier into seperate files
 * Added detection for system regex libraries on all platforms
 *
 * Revision 1.12  2003/07/29 11:25:23  csoutheren
 * Added support for system swab function
 *
 * Revision 1.11  2003/06/23 15:17:20  ykiryanov
 * Modified for WinCE compatibility - Undef'd P_HAS_IPV6 in case of WinCE build
 *
 * Revision 1.10  2003/05/22 12:20:16  dsandras
 *
 * Define or not TRY_1394AVC/TRY_1394DC after execution of the configure script.
 *
 * Revision 1.9  2003/05/17 03:22:47  rjongbloed
 * Removed need to do strange things with main() function.
 *
 * Revision 1.8  2003/05/05 06:25:33  robertj
 * Corrections to external libraries
 *
 * Revision 1.7  2003/04/28 08:32:01  craigs
 * Added Linux SDL detection
 *
 * Revision 1.6  2003/04/28 07:27:38  craigs
 * Added SDL libs
 *
 * Revision 1.5  2003/04/28 07:04:45  craigs
 * Added SDL detection
 *
 * Revision 1.4  2003/04/17 06:14:31  robertj
 * Changed link of openssl to be static.
 *
 * Revision 1.3  2003/04/17 01:22:29  craigs
 * Fixed problem with OpenLDAP and OpenSSL-0.9.7
 *
 * Revision 1.2  2003/04/16 08:00:19  robertj
 * Windoes psuedo autoconf support
 *
 * Revision 1.1  2003/04/16 07:15:59  craigs
 * Initial version
 *
 */

#ifndef _PT_BUILDOPTS_H
#define _PT_BUILDOPTS_H


/////////////////////////////////////////////////
//
// host type
//

#define P_LINUX "4.2.2-1-ARCH"
/* #undef P_FREEBSD */
/* #undef P_OPENBSD */
/* #undef P_NETBSD */
/* #undef P_SOLARIS */
/* #undef P_MACOSX */
/* #undef P_CYGWIN */
/* #undef P_MINGW */
/* #undef P_UNKNOWN_OS */


/////////////////////////////////////////////////
//
// sizeof(int)
//

#define SIZEOF_INT 4

/////////////////////////////////////////////////
//
// Processor endianess
//

#if !defined(P_MACOSX)
#define PBYTE_ORDER PLITTLE_ENDIAN
#else
#if defined(__BIG_ENDIAN__)
#define PBYTE_ORDER PLITTLE_ENDIAN
#else
#define PBYTE_ORDER PLITTLE_ENDIAN
#endif
#endif

/////////////////////////////////////////////////
//
// IP v6 Support
//

#ifndef _WIN32_WCE
/* #undef P_HAS_IPV6 */
#endif //  _WIN32_WCE

#if defined(_MSC_VER) && P_HAS_IPV6

#pragma include_alias(<winsock2.h>, <@IPV6_DIR@/winsock2.h>)
#pragma include_alias(<ws2tcpip.h>, <@IPV6_DIR@/ws2tcpip.h>)

#define P_WINSOCK2_LIBRARY "ws2_32.lib"

#endif


/////////////////////////////////////////////////
//
// QoS Support
//
//

#ifndef _WIN32_WCE
#define P_HAS_QOS 1
#endif //  _WIN32_WCE

#if defined(_MSC_VER) && P_HAS_QOS

#pragma include_alias(<qossp.h>, <@QOS_DIR@/qossp.h>)

#define P_WINSOCK2_LIBRARY "ws2_32.lib"

#endif


/////////////////////////////////////////////////
//
// OpenSSL library for secure sockets layer
//

#ifndef _WIN32_WCE
#define P_SSL 1
/* #undef P_WINSSL */
#define P_SSL_AES 1
/* #undef P_WINSSL_AES */
#define P_SSL_USE_CONST 1
#endif

#ifdef P_WINSSL
#define P_SSL 1
#endif

#ifdef P_WINSSL_AES
#define P_SSL_AES 1
#define P_SSL_USE_CONST 1
#endif

#if defined(_MSC_VER) && P_SSL

#if defined(P_WINSSL)

#pragma include_alias(<openssl/ssl.h>,        <@WINSSL_DIR@/include/openssl/ssl.h>)
#pragma include_alias(<openssl/safestack.h>,  <@WINSSL_DIR@/include/openssl/safestack.h>)
#pragma include_alias(<openssl/stack.h>,      <@WINSSL_DIR@/include/openssl/stack.h>)
#pragma include_alias(<openssl/crypto.h>,     <@WINSSL_DIR@/include/openssl/crypto.h>)
#pragma include_alias(<openssl/opensslv.h>,   <@WINSSL_DIR@/include/openssl/opensslv.h>)
#pragma include_alias(<openssl/lhash.h>,      <@WINSSL_DIR@/include/openssl/lhash.h>)
#pragma include_alias(<openssl/buffer.h>,     <@WINSSL_DIR@/include/openssl/buffer.h>)
#pragma include_alias(<openssl/bio.h>,        <@WINSSL_DIR@/include/openssl/bio.h>)
#pragma include_alias(<openssl/pem.h>,        <@WINSSL_DIR@/include/openssl/pem.h>)
#pragma include_alias(<openssl/evp.h>,        <@WINSSL_DIR@/include/openssl/evp.h>)
#pragma include_alias(<openssl/md2.h>,        <@WINSSL_DIR@/include/openssl/md2.h>)
#pragma include_alias(<openssl/opensslconf.h>,<@WINSSL_DIR@/include/openssl/opensslconf.h>)
#pragma include_alias(<openssl/md5.h>,        <@WINSSL_DIR@/include/openssl/md5.h>)
#pragma include_alias(<openssl/sha.h>,        <@WINSSL_DIR@/include/openssl/sha.h>)
#pragma include_alias(<openssl/ripemd.h>,     <@WINSSL_DIR@/include/openssl/ripemd.h>)
#pragma include_alias(<openssl/des.h>,        <@WINSSL_DIR@/include/openssl/des.h>)
#pragma include_alias(<openssl/e_os2.h>,      <@WINSSL_DIR@/include/openssl/e_os2.h>)
#pragma include_alias(<openssl/rc4.h>,        <@WINSSL_DIR@/include/openssl/rc4.h>)
#pragma include_alias(<openssl/rc2.h>,        <@WINSSL_DIR@/include/openssl/rc2.h>)
#pragma include_alias(<openssl/rc5.h>,        <@WINSSL_DIR@/include/openssl/rc5.h>)
#pragma include_alias(<openssl/blowfish.h>,   <@WINSSL_DIR@/include/openssl/blowfish.h>)
#pragma include_alias(<openssl/cast.h>,       <@WINSSL_DIR@/include/openssl/cast.h>)
#pragma include_alias(<openssl/idea.h>,       <@WINSSL_DIR@/include/openssl/idea.h>)
#pragma include_alias(<openssl/mdc2.h>,       <@WINSSL_DIR@/include/openssl/mdc2.h>)
#pragma include_alias(<openssl/rsa.h>,        <@WINSSL_DIR@/include/openssl/rsa.h>)
#pragma include_alias(<openssl/bn.h>,         <@WINSSL_DIR@/include/openssl/bn.h>)
#pragma include_alias(<openssl/dsa.h>,        <@WINSSL_DIR@/include/openssl/dsa.h>)
#pragma include_alias(<openssl/dh.h>,         <@WINSSL_DIR@/include/openssl/dh.h>)
#pragma include_alias(<openssl/objects.h>,    <@WINSSL_DIR@/include/openssl/objects.h>)
#pragma include_alias(<openssl/asn1.h>,       <@WINSSL_DIR@/include/openssl/asn1.h>)
#pragma include_alias(<openssl/x509.h>,       <@WINSSL_DIR@/include/openssl/x509.h>)
#pragma include_alias(<openssl/x509_vfy.h>,   <@WINSSL_DIR@/include/openssl/x509_vfy.h>)
#pragma include_alias(<openssl/pkcs7.h>,      <@WINSSL_DIR@/include/openssl/pkcs7.h>)
#pragma include_alias(<openssl/pem2.h>,       <@WINSSL_DIR@/include/openssl/pem2.h>)
#pragma include_alias(<openssl/ssl2.h>,       <@WINSSL_DIR@/include/openssl/ssl2.h>)
#pragma include_alias(<openssl/ssl3.h>,       <@WINSSL_DIR@/include/openssl/ssl3.h>)
#pragma include_alias(<openssl/tls1.h>,       <@WINSSL_DIR@/include/openssl/tls1.h>)
#pragma include_alias(<openssl/ssl23.h>,      <@WINSSL_DIR@/include/openssl/ssl23.h>)
#pragma include_alias(<openssl/err.h>,        <@WINSSL_DIR@/include/openssl/err.h>)
#pragma include_alias(<openssl/rand.h>,       <@WINSSL_DIR@/include/openssl/rand.h>)
#pragma include_alias(<openssl/symhacks.h>,   <@WINSSL_DIR@/include/openssl/symhacks.h>)
#pragma include_alias(<openssl/comp.h>,       <@WINSSL_DIR@/include/openssl/comp.h>)
#pragma include_alias(<openssl/ossl_typ.h>,   <@WINSSL_DIR@/include/openssl/ossl_typ.h>)
#pragma include_alias(<openssl/md4.h>,        <@WINSSL_DIR@/include/openssl/md4.h>)
#pragma include_alias(<openssl/des_old.h>,    <@WINSSL_DIR@/include/openssl/des_old.h>)
#pragma include_alias(<openssl/ui_compat.h>,  <@WINSSL_DIR@/include/openssl/ui_compat.h>)
#pragma include_alias(<openssl/ui.h>,         <@WINSSL_DIR@/include/openssl/ui.h>)
#pragma include_alias(<openssl/aes.h>,        <@WINSSL_DIR@/include/openssl/aes.h>)
#pragma include_alias(<openssl/obj_mac.h>,    <@WINSSL_DIR@/include/openssl/obj_mac.h>)
#pragma include_alias(<openssl/kssl.h>,       <@WINSSL_DIR@/include/openssl/kssl.h>)
#pragma include_alias(<openssl/ec.h>,         <@WINSSL_DIR@/include/openssl/ec.h>)
#pragma include_alias(<openssl/ecdsa.h>,      <@WINSSL_DIR@/include/openssl/ecdsa.h>)
#pragma include_alias(<openssl/ecdh.h>,       <@WINSSL_DIR@/include/openssl/ecdh.h>)
#pragma include_alias(<openssl/pq_compat.h>,  <@WINSSL_DIR@/include/openssl/pq_compat.h>)
#pragma include_alias(<openssl/dtls1.h>,      <@WINSSL_DIR@/include/openssl/dtls1.h>)
#pragma include_alias(<openssl/pqueue.h>,     <@WINSSL_DIR@/include/openssl/pqueue.h>)

#if defined(_MSC_VER) && P_WINSSL_AES
#pragma include_alias(<openssl/aes.h>,        <@WINSSL_DIR@/include/openssl/aes.h>)
#endif

#ifdef _DEBUG
#define P_SSL_LIB1 "@WINSSL_DIR@/lib/VC/libeay32MTd.lib"
#define P_SSL_LIB2 "@WINSSL_DIR@/lib/VC/ssleay32MTd.lib"
#else
#define P_SSL_LIB1 "@WINSSL_DIR@/lib/VC/libeay32MT.lib"
#define P_SSL_LIB2 "@WINSSL_DIR@/lib/VC/ssleay32MT.lib"
#endif

#else

#pragma include_alias(<openssl/ssl.h>,        <@SSL_DIR@/inc32/openssl/ssl.h>)
#pragma include_alias(<openssl/safestack.h>,  <@SSL_DIR@/inc32/openssl/safestack.h>)
#pragma include_alias(<openssl/stack.h>,      <@SSL_DIR@/inc32/openssl/stack.h>)
#pragma include_alias(<openssl/crypto.h>,     <@SSL_DIR@/inc32/openssl/crypto.h>)
#pragma include_alias(<openssl/opensslv.h>,   <@SSL_DIR@/inc32/openssl/opensslv.h>)
#pragma include_alias(<openssl/lhash.h>,      <@SSL_DIR@/inc32/openssl/lhash.h>)
#pragma include_alias(<openssl/buffer.h>,     <@SSL_DIR@/inc32/openssl/buffer.h>)
#pragma include_alias(<openssl/bio.h>,        <@SSL_DIR@/inc32/openssl/bio.h>)
#pragma include_alias(<openssl/pem.h>,        <@SSL_DIR@/inc32/openssl/pem.h>)
#pragma include_alias(<openssl/evp.h>,        <@SSL_DIR@/inc32/openssl/evp.h>)
#pragma include_alias(<openssl/md2.h>,        <@SSL_DIR@/inc32/openssl/md2.h>)
#pragma include_alias(<openssl/opensslconf.h>,<@SSL_DIR@/inc32/openssl/opensslconf.h>)
#pragma include_alias(<openssl/md5.h>,        <@SSL_DIR@/inc32/openssl/md5.h>)
#pragma include_alias(<openssl/sha.h>,        <@SSL_DIR@/inc32/openssl/sha.h>)
#pragma include_alias(<openssl/ripemd.h>,     <@SSL_DIR@/inc32/openssl/ripemd.h>)
#pragma include_alias(<openssl/des.h>,        <@SSL_DIR@/inc32/openssl/des.h>)
#pragma include_alias(<openssl/e_os2.h>,      <@SSL_DIR@/inc32/openssl/e_os2.h>)
#pragma include_alias(<openssl/rc4.h>,        <@SSL_DIR@/inc32/openssl/rc4.h>)
#pragma include_alias(<openssl/rc2.h>,        <@SSL_DIR@/inc32/openssl/rc2.h>)
#pragma include_alias(<openssl/rc5.h>,        <@SSL_DIR@/inc32/openssl/rc5.h>)
#pragma include_alias(<openssl/blowfish.h>,   <@SSL_DIR@/inc32/openssl/blowfish.h>)
#pragma include_alias(<openssl/cast.h>,       <@SSL_DIR@/inc32/openssl/cast.h>)
#pragma include_alias(<openssl/idea.h>,       <@SSL_DIR@/inc32/openssl/idea.h>)
#pragma include_alias(<openssl/mdc2.h>,       <@SSL_DIR@/inc32/openssl/mdc2.h>)
#pragma include_alias(<openssl/rsa.h>,        <@SSL_DIR@/inc32/openssl/rsa.h>)
#pragma include_alias(<openssl/bn.h>,         <@SSL_DIR@/inc32/openssl/bn.h>)
#pragma include_alias(<openssl/dsa.h>,        <@SSL_DIR@/inc32/openssl/dsa.h>)
#pragma include_alias(<openssl/dh.h>,         <@SSL_DIR@/inc32/openssl/dh.h>)
#pragma include_alias(<openssl/objects.h>,    <@SSL_DIR@/inc32/openssl/objects.h>)
#pragma include_alias(<openssl/asn1.h>,       <@SSL_DIR@/inc32/openssl/asn1.h>)
#pragma include_alias(<openssl/x509.h>,       <@SSL_DIR@/inc32/openssl/x509.h>)
#pragma include_alias(<openssl/x509_vfy.h>,   <@SSL_DIR@/inc32/openssl/x509_vfy.h>)
#pragma include_alias(<openssl/pkcs7.h>,      <@SSL_DIR@/inc32/openssl/pkcs7.h>)
#pragma include_alias(<openssl/pem2.h>,       <@SSL_DIR@/inc32/openssl/pem2.h>)
#pragma include_alias(<openssl/ssl2.h>,       <@SSL_DIR@/inc32/openssl/ssl2.h>)
#pragma include_alias(<openssl/ssl3.h>,       <@SSL_DIR@/inc32/openssl/ssl3.h>)
#pragma include_alias(<openssl/tls1.h>,       <@SSL_DIR@/inc32/openssl/tls1.h>)
#pragma include_alias(<openssl/ssl23.h>,      <@SSL_DIR@/inc32/openssl/ssl23.h>)
#pragma include_alias(<openssl/err.h>,        <@SSL_DIR@/inc32/openssl/err.h>)
#pragma include_alias(<openssl/rand.h>,       <@SSL_DIR@/inc32/openssl/rand.h>)
#pragma include_alias(<openssl/symhacks.h>,   <@SSL_DIR@/inc32/openssl/symhacks.h>)
#pragma include_alias(<openssl/comp.h>,       <@SSL_DIR@/inc32/openssl/comp.h>)
#pragma include_alias(<openssl/ossl_typ.h>,   <@SSL_DIR@/inc32/openssl/ossl_typ.h>)
#pragma include_alias(<openssl/md4.h>,        <@SSL_DIR@/inc32/openssl/md4.h>)
#pragma include_alias(<openssl/des_old.h>,    <@SSL_DIR@/inc32/openssl/des_old.h>)
#pragma include_alias(<openssl/ui_compat.h>,  <@SSL_DIR@/inc32/openssl/ui_compat.h>)
#pragma include_alias(<openssl/ui.h>,         <@SSL_DIR@/inc32/openssl/ui.h>)
#pragma include_alias(<openssl/aes.h>,        <@SSL_DIR@/inc32/openssl/aes.h>)
#pragma include_alias(<openssl/obj_mac.h>,    <@SSL_DIR@/inc32/openssl/obj_mac.h>)
#pragma include_alias(<openssl/kssl.h>,       <@SSL_DIR@/inc32/openssl/kssl.h>)
#pragma include_alias(<openssl/ec.h>,         <@SSL_DIR@/inc32/openssl/ec.h>)
#pragma include_alias(<openssl/ecdsa.h>,      <@SSL_DIR@/inc32/openssl/ecdsa.h>)
#pragma include_alias(<openssl/ecdh.h>,       <@SSL_DIR@/inc32/openssl/ecdh.h>)
#pragma include_alias(<openssl/pq_compat.h>,  <@SSL_DIR@/inc32/openssl/pq_compat.h>)
#pragma include_alias(<openssl/dtls1.h>,      <@SSL_DIR@/inc32/openssl/dtls1.h>)
#pragma include_alias(<openssl/pqueue.h>,     <@SSL_DIR@/inc32/openssl/pqueue.h>)

#if defined(_MSC_VER) && P_SSL_AES
#pragma include_alias(<openssl/aes.h>,        <@SSL_DIR@/inc32/openssl/aes.h>)
#endif

#ifdef _DEBUG
#define P_SSL_LIBDIR "out32.dbg"
#else
#define P_SSL_LIBDIR "out32"
#endif

#define P_SSL_LIB1 "@SSL_DIR@/" P_SSL_LIBDIR "/ssleay32.lib"
#define P_SSL_LIB2 "@SSL_DIR@/" P_SSL_LIBDIR "/libeay32.lib"

#endif

#endif


/////////////////////////////////////////////////
//
// EXPAT library for XML parsing
//

#ifndef _WIN32_WCE
/* #undef P_EXPAT */
/* #undef P_WINEXPAT */
#endif

#ifdef P_WINEXPAT 
#define P_EXPAT 1
#endif

#if defined(_MSC_VER) && P_EXPAT

#ifdef P_WINEXPAT

#pragma include_alias(<expat.h>, <@WINEXPAT_DIR@/source/lib/expat.h>)

#define P_EXPAT_LIBRARY "@WINEXPAT_DIR@/libs/libexpat.lib"

#else

#pragma include_alias(<expat.h>, <@EXPAT_DIR@/lib/expat.h>)

#ifdef _DEBUG
#define P_EXPAT_LIBDIR "Debug"
#else
#define P_EXPAT_LIBDIR "Release"
#endif

#define P_EXPAT_LIBRARY "@EXPAT_DIR@/" P_EXPAT_LIBDIR "/expat.lib"

#endif

#endif


/////////////////////////////////////////////////
//
// OpenLDAP
//

#ifndef _WIN32_WCE
/* #undef P_LDAP */
#endif

#if defined(_MSC_VER) && P_LDAP

#pragma include_alias(<ldap.h>,          <@LDAP_DIR@/include/ldap.h>)
#pragma include_alias(<lber.h>,          <@LDAP_DIR@/include/lber.h>)
#pragma include_alias(<lber_types.h>,    <@LDAP_DIR@/include/lber_types.h>)
#pragma include_alias(<ldap_features.h>, <@LDAP_DIR@/include/ldap_features.h>)
#pragma include_alias(<ldap_cdefs.h>,    <@LDAP_DIR@/include/ldap_cdefs.h>)

#ifdef _DEBUG
#define P_LDAP_LIBRARY "@LDAP_DIR@/DLLDebug/openldapd.lib"
#else
#define P_LDAP_LIBRARY "@LDAP_DIR@/DLLRelease/openldap.lib"
#endif

#endif


/* #undef P_MEDIALIB */

/////////////////////////////////////////////////
//
// DNS resolver
//

#define P_DNS 1
#define P_HAS_RES_NINIT 1

#if defined(_MSC_VER) && P_DNS

#pragma include_alias(<windns.h>, <@DNS_DIR@/Include/windns.h>)

#define P_DNS_LIBRARY "@DNS_DIR@/Lib/DnsAPI.Lib"

#endif



/////////////////////////////////////////////////
//
// SAPI speech API (Windows only)
//

#ifndef _WIN32_WCE
/* #undef P_SAPI */
#endif

#if defined(_MSC_VER) && P_SAPI

#pragma include_alias(<sphelper.h>, <@SAPI_DIR@/include/sphelper.h>)
#pragma include_alias(<sapi.h>, <@SAPI_DIR@/include/sapi.h>)
#pragma include_alias(<sapiddk.h>, <@SAPI_DIR@/include/sapiddk.h>)
#pragma include_alias(<SPError.h>, <@SAPI_DIR@/include/SPError.h>)
#pragma include_alias(<SPDebug.h>, <@SAPI_DIR@/include/SPDebug.h>)

#define P_SAPI_LIBRARY "@SAPI_DIR@/Lib/i386/sapi.lib"

#endif



/////////////////////////////////////////////////
//
// Cyrus SASL
//

#ifndef _WIN32_WCE
/* #undef P_SASL */
#define P_SASL2 1
#define P_HAS_SASL_SASL_H 1
#endif

#if defined(_MSC_VER) && (defined(P_SASL) || defined(P_SASL2))

#pragma include_alias(<sasl/sasl.h>, <@SASL_DIR@/include/sasl.h>)

#define P_SASL_LIBRARY "@SASL_DIR@/lib/libsasl.lib"
#define P_HAS_SASL_SASL_H 1

#endif



/////////////////////////////////////////////////
//
// SDL toolkit
//

#ifndef _WIN32_WCE
#define P_SDL 1
#endif

#if defined(_MSC_VER) && P_SDL
#pragma include_alias(<SDL/SDL.h>, <@SDL_DIR@/include/SDL.h>)

/* #undef P_SDL_LIBDIR */

#ifndef P_SDL_LIBDIR
 #ifdef _DEBUG
  #define P_SDL_LIBDIR "VisualC/SDL/Debug"
 #else
  #define P_SDL_LIBDIR "VisualC/SDL/Release"
 #endif
#endif

#define P_SDL_LIBRARY "@SDL_DIR@/" P_SDL_LIBDIR "/SDL.lib"

#endif


/////////////////////////////////////////////////
//
// Runtime dynamic link libraries
//

#define P_DYNALINK 1
#define P_HAS_PLUGINS 1
#define P_DEFAULT_PLUGIN_DIR "/usr/local/lib/ptlib"

/////////////////////////////////////////////////
//
// Regex library
//

#define P_REGEX 1

/////////////////////////////////////////////////
//
// various non-core functions
//

#define P_TTS 1
#define P_ASN 1
#define P_STUN 1
#define P_PIPECHAN 1
#define P_DTMF 1
#define P_WAVFILE 1
#define P_SOCKS 1
#define P_FTP 1
#define P_SNMP 1
#define P_TELNET 1
/* #undef P_REMCONN */
#define P_SERIAL 1
#define P_POP3SMTP 1
#define P_AUDIO 1
/* #undef P_ALSA */
#define P_VIDEO 1
#define NO_VIDEO_CAPTURE /**/

/* #undef P_VXML */
/* #undef P_JABBER */
/* #undef P_XMLRPC */
/* #undef P_SOAP */
#define P_HTTPSVC 1
#define P_HTTP 1
#define P_CONFIG_FILE 1
/* #undef P_SOCKAGG */
#define P_VIDFILE 1
/* #undef P_ODBC */
/* #undef P_SHMVIDEO */
/* #undef P_FFVDEV */

/////////////////////////////////////////////////
//
// PThreads and related vars
//

#define P_PTHREADS 1
#define P_HAS_SEMAPHORES 1
/* #undef P_HAS_NAMED_SEMAPHORES */
#define P_PTHREADS_XPG6 1
#define P_HAS_SEMAPHORES_XPG6 1
/* #undef P_EXCEPTIONS */


/////////////////////////////////////////////////
//
// APP Share Input 
//

#if P_VIDEO
  #ifndef _WIN32_WCE
/*     #undef P_APPSHARE */
  #endif
#endif

/////////////////////////////////////////////////
//
// DirectX Support (Windows only)
//

#ifndef _WIN32_WCE
/* #undef P_DIRECTSOUND */
/* #undef P_DIRECTSHOW */
/* #undef P_VFW_CAPTURE */
#endif

#if defined(_MSC_VER) && (defined(P_DIRECTSOUND) || defined(P_DIRECTSHOW))

#pragma include_alias(<dsound.h>, <@DIRECTX_DIR@/include/dsound.h>)

/* #undef P_DIRECTSOUND_LIB64 */
/* #undef P_DIRECTSOUND_LIB32 */

#if defined(_WIN64)
#define P_DIRECTSOUND_LIBRARY P_DIRECTSOUND_LIB64
#else
#define P_DIRECTSOUND_LIBRARY P_DIRECTSOUND_LIB32
#endif

#endif


/////////////////////////////////////////////////
//
// DCOM Support (Windows only)
//

#if defined(_MSC_VER)
  #define _WIN32_DCOM 1
  #define _OLE_LIB "ole32.lib"
#endif 

/////////////////////////////////////////////////
//
// various functions
//
#define USE_SYSTEM_SWAB /**/

#define PTLIB_MAJOR 2
#define PTLIB_MINOR 0
#define PTLIB_BUILD 1
#define PTLIB_VERSION "2.0.1"

#define P_64BIT 1
#define PHAS_TEMPLATES 1
/* #undef PNO_LONG_DOUBLE */
#define P_HAS_POSIX_READDIR_R 3
#define P_HAS_STL_STREAMS 1
#define P_HAS_ATOMIC_INT 1
#define P_HAS_RECURSIVE_MUTEX 1
#define P_NEEDS_GNU_CXX_NAMESPACE 1
/* #undef PMEMORY_CHECK */
#define P_HAS_RECVMSG 1
/* #undef P_HAS_UPAD128_T */

#endif // _PT_BUILDOPTS_H


// End Of File ///////////////////////////////////////////////////////////////

