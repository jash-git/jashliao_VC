// PHPTest.cpp : 定義 DLL 應用程式的匯出函式。
//

#include "stdafx.h"

// 聲明以下的宏定義解決在編譯過程中會發生：error C2466: 不能分配常量大小為0 的數組的錯誤。
#ifdef PHP_WIN32  
#define _STATIC_ASSERT(expr) typedef char __static_assert_t[ (expr)?(expr):1 ]  
#else  
#define _STATIC_ASSERT(expr) typedef char __static_assert_t[ (expr) ]  
#endif  

// #include "XXXXX.h" 在以下包含頭文件的前面包含要用到的c++ 的stl的頭文件，或者你自己寫的C++的頭文件。
#include <string>
using namespace std;

extern "C" {
#include "zend_config.w32.h"
#include "php.h"
#include "ext/standard/info.h"
#include "PHPTest.h"
}


// 聲明了擴展庫的導出函數列表
zend_function_entry PHPTest_functions[] = {
	PHP_FE(init_module, NULL)
	PHP_FE(test_module, NULL)
	PHP_FE(close_module, NULL)
	PHP_FE_END
};

zend_module_entry PHPTest_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"PHPTest",
	PHPTest_functions,
	PHP_MINIT(PHPTest),
	PHP_MSHUTDOWN(PHPTest),
	PHP_RINIT(PHPTest), /* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(PHPTest), /* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(PHPTest),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};


ZEND_GET_MODULE(PHPTest);

PHP_MINIT_FUNCTION(PHPTest)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(PHPTest)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}

PHP_RINIT_FUNCTION(PHPTest)
{
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(PHPTest)
{
	return SUCCESS;
}

PHP_MINFO_FUNCTION(PHPTest)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "PHPTest support", "enabled");
	php_info_print_table_end();


	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}

// 以下是php導出函數的實現，比如string init_module(string content)
PHP_FUNCTION(init_module)
{
	char *content = NULL;   // 
	int argc = ZEND_NUM_ARGS();
	int content_len;
	// 這句話便是導出傳入參數 
	if (zend_parse_parameters(argc TSRMLS_CC, "s", &content, &content_len) == FAILURE)
		return;
	if (content)
	{
		//  這裏只是為了測試，直接把傳入值返回去。
		string strRet = content;
		// 返回值
		RETURN_STRING((char*)strRet.c_str(), 1);
	}
	else
	{
		php_error(E_WARNING, "init_module: content is NULL");
	}
}

// 以下是int test_module(string content)函數的實現
PHP_FUNCTION(test_module)
{
	char *content = NULL;
	int argc = ZEND_NUM_ARGS();
	int content_len;


	if (zend_parse_parameters(argc TSRMLS_CC, "s", &content, &content_len) == FAILURE)
		return;
	if (content)
	{
		int nRet = content_len;
		RETURN_LONG(nRet);
	}
	else
	{
		php_error(E_WARNING, "test_module: &content is NULL");
	}


}

// 以下是 void close_module()函數的實現
PHP_FUNCTION(close_module)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_printf("close_module successfully\n");
}
