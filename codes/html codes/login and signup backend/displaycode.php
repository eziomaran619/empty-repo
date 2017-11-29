<?php  
require "connect_to_database.php" ; 
?>

<?php

$sno = $_GET["snippetno"] ;

if (isset($_SESSION["user"])) {
	$un = $_SESSION["user"] ;
	$title = "user : " . $un ;
} else {
	$un = "" ;
	$title = "Guest user" ;
}


$query  = "SELECT * FROM snippetlist WHERE snippetno=$sno" ;
$result = mysqli_query($connection,$query) ;

if (mysqli_num_rows($result) == 0) {
	echo "paste doesn't exist" ;
}else {
	$result = mysqli_fetch_assoc($result) ;

	if (!is_null($result["expirytime"]) && (strtotime($result["expirytime"]) < strtotime(date("y-m-d h:i:s")))) {
		echo "paste expired" ;
	} elseif ($result["username"] == $un || $result["pastetype"] == "public") {
    	if ($result["username"] == $un) {
    		echo "your " . $result["uservisibility"] . " " . $result["pastetype"] . " paste" . "<br>" ;
    	} elseif ($result["uservisibility"] == "anonymous") {
		    echo "anonymous user's paste" ;
	    } else {
		    echo $result["username"] . "'s paste"  . "<br>";
	    }    
	    
	    echo "<br><br><textarea rows='40' cols='150' readonly>" . $result['snippet'] . "</textarea>" ;
    }else {
	    echo "This is a private paste" ;
    }
}



?>

<!DOCTYPE html>
<html>
<head>
	<title><?php echo $title ?></title>
</head>
<body></body>
</html>