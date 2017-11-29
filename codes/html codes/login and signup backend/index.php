<?php  
require "connect_to_database.php" ; 
?>

<?php
if (isset($_SESSION["user"])) {
    header("Location: userloggedin.php") ;
    exit();
}else{
	header("Location: loginpage.php") ;
}

?>


