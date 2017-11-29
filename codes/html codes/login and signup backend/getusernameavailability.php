<?php
require "connect_to_database.php" ;

$returnText = "" ;

$uName = $_GET["uName"] ;

$query = "SELECT username FROM userslist" ;

$result = mysqli_query($connection,$query) ;

if (!empty($uName)) {
	if (mysqli_num_rows($result) > 0) {
		while ($row = mysqli_fetch_assoc($result)) {
		    if ($row["username"] == $uName) {
			    $returnText = "taken" ;
			    break ;
		    } else {
			    $returnText = "available" ;
		    }		
	    }
	} else {
		$returnText = "available" ;
    }
	
}
echo $returnText ;
?>