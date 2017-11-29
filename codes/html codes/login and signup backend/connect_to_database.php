<?php

	$serverName = "localhost" ;
	$userName   = "root" ;
	$password   = "EZka16!&" ;
	$dbName     = "task3db" ;

	$connection = mysqli_connect($serverName,$userName,$password,$dbName) ;

	if (!$connection) {
		die("unable to establish connection with database : " . mysqli_connect_error());
	}

	date_default_timezone_set("Asia/Kolkata") ;

	session_start() ;
?>