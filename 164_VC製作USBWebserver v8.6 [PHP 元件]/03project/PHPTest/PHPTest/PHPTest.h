#pragma once
extern zend_module_entry PHPTest_module_entry;          // PHPTest  是該示例的工程名字， PHPTest_module_entry是php擴展庫的入口聲明
#define phpext_PHPTest_ptr &PHPTest_module_entry

#ifdef PHP_WIN32
#define PHP_PHPTest_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#define PHP_PHPTest_API __attribute__ ((visibility("default")))
#else
#define PHP_PHPTest_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(PHPTest);
PHP_MSHUTDOWN_FUNCTION(PHPTest);
PHP_RINIT_FUNCTION(PHPTest);
PHP_RSHUTDOWN_FUNCTION(PHPTest);
PHP_MINFO_FUNCTION(PHPTest);

// PHP_FUNCTION  用於定義要導出給php調用的函數名稱，這裏我們定義了3個函數：init_module，test_module, close_module
// PHP_FUNCTION  只用來聲明函數的名稱，置於函數的參數將在cpp中定義

PHP_FUNCTION(init_module);
PHP_FUNCTION(test_module);
PHP_FUNCTION(close_module);


/*
Declare any global variables you may need between the BEGIN
and END macros here:
ZEND_BEGIN_MODULE_GLOBALS(CSVirusAnalyse)
long  global_value;
char *global_string;
ZEND_END_MODULE_GLOBALS(CSVirusAnalyse)
*/

/* In every utility function you add that needs to use variables
in php_CSVirusAnalyse_globals, call TSRMLS_FETCH(); after declaring other
variables used by that function, or better yet, pass in TSRMLS_CC
after the last function argument and declare your utility function
with TSRMLS_DC after the last declared argument.  Always refer to
the globals in your function as CSGAVIRUSANALYSIS_G(variable).  You are
encouraged to rename these macros something shorter, see
examples in any other php module directory.
*/

#ifdef ZTS
#define PHPTEST_G(v) TSRMG(PHPTest_globals_id, zend_PHPTest_globals *, v)
#else
#define PHPTEST_G(v) (PHPTest_globals.v)
#endif