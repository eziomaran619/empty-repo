    <?php

    require "connect_to_database.php" ;

    $success = "" ;

    $un = "" ;

    $unerror = "" ;
    $passerror = "" ;
    
    if ($_SERVER["REQUEST_METHOD"] == "POST") {

    	$un    = $_POST['username'] ;
        $pass  = $_POST['password'] ;

        if (empty($un) || empty($pass)) {
        	if (empty($un)) {
        		$unerror = "username required" ;
        	} 
            if (empty($pass)) {
            	$passerror = "password required" ;
            }

        } else {
            $un = correctData($un) ;

           $query = "SELECT password FROM userslist WHERE username =?" ;

           $stmt = mysqli_prepare($connection,$query) ;
           mysqli_stmt_bind_param($stmt,"s",$un) ;
           mysqli_stmt_execute($stmt) ;
           mysqli_stmt_bind_result($stmt,$result) ;
           mysqli_stmt_fetch($stmt) ;
           
           if (!empty($result)) {
	           if ($result == $pass) {
		           $_SESSION["user"] = $un ;
		           header("Location: userloggedin.php") ;
		           exit() ;
	           } else {
		           $passerror = "password incorrect" ;
	           }	
           }else {
	           $unerror = "username incorrect" ;
           }

        }

    }

    function correctData ($data) {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }

    ?>

<!DOCTYPE html>
<html>
<head>
	<title>Task3</title>
	<style type="text/css">
		.imp {
			color: red ;
		}
		button {
			cursor: pointer;
		}
		[type="submit"] {
			cursor: pointer;
		}
	</style>
</head>
<body>
	<h3 style="margin: 0px;">Log In :</h3>
	<form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']) ?>">
	    <input type="text" name="username" placeholder="username.." value="<?php echo $un ?>"> <span class="imp"><?php echo "$unerror" ?></span><br>
		<input type="password" name="password" placeholder="password.."> <span class="imp"><?php echo "$passerror" ?></span><br>
		<input type="submit" value="Log in" >
	</form><hr>
	<button onclick="gotosignuppage()">Create New Account</button><br>
	<hr>
	<script type="text/javascript">
		function gotosignuppage() {
			window.location.assign("signuppage.php") ;
		}
	</script>
	</body>
</html>

