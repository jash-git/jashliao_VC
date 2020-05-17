<?php 
$url = "http://127.0.0.1:8080/cs2php/login.php"; 
$urls = "http://127.0.0.1:8080/cs2php/outjson.php"; 
$lgt = 0; 
$user = "jash"; 
$pass = "1234"; 
$cookie_file='./cookie.tmp'; 
$postdata = "username=".$user."&password=".$pass; 
$ch = curl_init(); 
curl_setopt($ch, CURLOPT_URL, $url); 
curl_setopt($ch, CURLOPT_HEADER, 0); 
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); 
curl_setopt($ch, CURLOPT_POST, 1); 
curl_setopt($ch, CURLOPT_POSTFIELDS, $postdata); 
curl_setopt($ch, CURLOPT_COOKIEJAR, $cookie_file); 
curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true); 
$data = curl_exec($ch); 
curl_close($ch); 
//echo $data; 

$ch = curl_init(); 
curl_setopt($ch, CURLOPT_URL, $urls); 
curl_setopt($ch, CURLOPT_HEADER, 0); 
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 0); 
curl_setopt($ch, CURLOPT_COOKIEFILE, $cookie_file); 
$data = curl_exec($ch); 
echo $data; 
curl_close($ch); 
?>
