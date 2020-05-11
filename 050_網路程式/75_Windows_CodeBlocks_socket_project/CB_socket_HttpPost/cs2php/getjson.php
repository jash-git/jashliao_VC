<?php
header('content-type:text/html;charset=utf-8');


$data = $_POST['data'];
$obj= json_decode($data);

print_r($obj);

foreach($obj as $key => $value) {
    if($value) {

            //how to use json array to insert data in Database
        echo "$value->name"." $value->password"."\n";
    }
}

echo $data.'_get';
?>