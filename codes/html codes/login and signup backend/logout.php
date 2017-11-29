<?php  
require "connect_to_database.php" ; 
?>

<?php
session_destroy() ; // removes all session variables
header("Location: loginpage.php") ;
exit();
?>