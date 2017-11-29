<?php
require "connect_to_database.php" ;

$returnText = "" ;

$uName = $_GET["uName"] ;

$query = "SELECT username FROM userslist" ;

$result = mysqli_query($connection,$query) ;

if (!empty($uName)) {
	while ($row = mysqli_fetch_assoc($result)) {
		if (preg_match("/^" . $uName . "/", $row["username"])) {
			$returnText .= $row["username"] . " , " ;
		}		
	}
}
echo $returnText ;
?>