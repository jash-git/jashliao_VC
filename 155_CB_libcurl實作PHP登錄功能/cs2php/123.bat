wget --post-data="username=jash&password=1234" --save-cookies=cookie.txt --keep-session-cookies http://localhost:8080/cs2php/login.php -O login.txt
wget --load-cookies=cookie.txt "http://localhost:8080/cs2php/outjson.php" -O outjson.txt