<?php
header('content-type:text/html;charset=utf-8');
session_start();
echo "<font size='24' face='Arial'>";//PHP放大字體

$username = htmlspecialchars($_POST['username']);
$password = $_POST['password'];

if($username==='jash' && $password=='1234')
{
	//登錄成功
	$_SESSION['username'] = $username;
	exit('OK');
} else {
	exit('fail');
}
?>
