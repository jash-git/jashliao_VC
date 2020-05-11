<?php
header('content-type:text/html;charset=utf-8');
session_start();

//檢測是否登錄，若沒登錄則轉向登錄介面
if(!isset($_SESSION['username'])){
	header("Location:login.html");
	exit();
}
else{
	
	$arraydata=array();
	for($i=0;$i<5;$i++)
	{
		$arraydata[$i]["name"]="jash";
		$arraydata[$i]["password"]="1234";
	}
	echo json_encode($arraydata);	
}
?>
