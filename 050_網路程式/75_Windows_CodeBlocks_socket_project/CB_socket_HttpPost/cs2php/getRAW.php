<?php
/*
資料來源:http://phpwolf.blogspot.tw/2013/08/php-post-json.html
讓 PHP 接收 post 的 json 資料
我們在串接API的時候會用到 CURL 函式 POST 資料給 JSON 接收，雖然我們是使用 POST 傳出資料。但是我們在接收的 SERVER 端使用 $_POST 卻抓不到任何資料。

原來 PHP 默認只支援 application/x-www.form-urlencoded 來把資料塞入到  $_POST  所以即便你用 POST 傳值過來，也不能用 $_POST 來取值。

這時候我們就要用 $GLOBALS['HTTP_RAW_POST_DATA'] 來取得資料了。因為其實SERVER端是有拿到資料的，所以用這個參數就可以拿到"完整"資料。


後記：
後來又出現了一個問題，$GLOBALS['HTTP_RAW_POST_DATA'] 如果要可以正確取得資料，需要去把 php.ini 中的功能打開，這對很多專案中客戶是採用虛擬主機的是一個很大的問題。好險有另一個方式也可以取得原始的 post 資料：
*/
header('content-type:text/html;charset=utf-8');

$data = file_get_contents("php://input");
echo urldecode($data)."_get";
?>