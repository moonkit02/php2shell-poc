/*
   +----------------------------------------------------------------------+
   | Copyright (c) The PHP Group                                          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | https://www.php.net/license/3_01.txt                                 |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Stig Sæther Bakken <ssb@php.net>                             |
   +----------------------------------------------------------------------+
*/

#define CONFIGURE_COMMAND " './configure'  '--build=aarch64-linux-musl' '--sysconfdir=/usr/local/etc' '--with-config-file-path=/usr/local/etc/php' '--with-config-file-scan-dir=/usr/local/etc/php/conf.d' '--enable-option-checking=fatal' '--with-mhash' '--with-pic' '--enable-mbstring' '--enable-mysqlnd' '--with-password-argon2' '--with-sodium=shared' '--with-pdo-sqlite=/usr' '--with-sqlite3=/usr' '--with-curl' '--with-iconv=/usr' '--with-openssl' '--with-readline' '--with-zlib' '--enable-phpdbg' '--enable-phpdbg-readline' '--with-pear' 'build_alias=aarch64-linux-musl'"
#define PHP_ODBC_CFLAGS	""
#define PHP_ODBC_LFLAGS		""
#define PHP_ODBC_LIBS		""
#define PHP_ODBC_TYPE		""
#define PHP_OCI8_DIR			""
#define PHP_OCI8_ORACLE_VERSION		""
#define PHP_PROG_SENDMAIL	"/usr/sbin/sendmail"
#define PEAR_INSTALLDIR         "/usr/local/lib/php"
#define PHP_INCLUDE_PATH	".:/usr/local/lib/php"
#define PHP_EXTENSION_DIR       "/usr/local/lib/php/extensions/no-debug-non-zts-20220829"
#define PHP_PREFIX              "/usr/local"
#define PHP_BINDIR              "/usr/local/bin"
#define PHP_SBINDIR             "/usr/local/sbin"
#define PHP_MANDIR              "/usr/local/php/man"
#define PHP_LIBDIR              "/usr/local/lib/php"
#define PHP_DATADIR             "/usr/local/share/php"
#define PHP_SYSCONFDIR          "/usr/local/etc"
#define PHP_LOCALSTATEDIR       "/usr/local/var"
#define PHP_CONFIG_FILE_PATH    "/usr/local/etc/php"
#define PHP_CONFIG_FILE_SCAN_DIR    "/usr/local/etc/php/conf.d"
#define PHP_SHLIB_SUFFIX        "so"
#define PHP_SHLIB_EXT_PREFIX    ""
