<?php
	echo init_module('test init');
	echo'<br>';
	//輸出: test init
	echo test_module('test_module');
	echo'<br>';
	close_module();
?>