    <?php

    require "connect_to_database.php" ;

    $success = "" ;

    $un = "" ;

    $unerror = "should begin with an alphabet and contain underscores and alphanumeric characters only" ;
    $passerror = "minimum 8 characters long and contain atleast 1 upper case, lower case aplhabet and number" ;
    
    if ($_SERVER["REQUEST_METHOD"] == "POST") {

    	$un    = $_POST['username'] ;
        $pass  = $_POST['password'] ;
        $cPass = $_POST['cPassword'] ;

        if (empty($un) || empty($pass) || strlen($pass) < 8 || !preg_match("/^[a-z](?:[a-z0-9_]|)*$/i", $un) || 
                                                                    (!preg_match("/[a-z]/", $pass) && !preg_match("/[A-Z]/", $pass) && !preg_match("/[0-9]/", $pass)) ) {
            if (!preg_match("/^[a-z](?:[a-z0-9_]|)*$/i", $un)) {
                $unerror = "invalid username" ;
            }
            if ((!preg_match("/[a-z]/", $pass) && !preg_match("/[A-Z]/", $pass) && !preg_match("/[0-9]/", $pass))) {
                $passerror = "invalid password" ;
            }
            if (strlen($pass) < 8) {
                 $passerror = "length insufficient" ;
            }
            if (empty($un)) {
                $unerror = "username required" ;
            }
            if (empty($pass)) {
            	$passerror = "passsword required" ;
            }

        } else {
            $un = correctData($un) ;

            if ($pass == $cPass) {

                $query = "INSERT INTO userslist VALUES (?,?)" ;// template
                $stmt = mysqli_prepare($connection,$query) ;// prepare and push it to the table

                mysqli_stmt_bind_param($stmt,"ss",$un,$pass) ;

                $result = mysqli_stmt_execute($stmt) ;

                if ($result) {
                    $unerror = "success" ;
                    $passerror = "success" ;
                    $success = "sign up successful, <a href='loginpage.php'>click here</a> to go back and log in !" ;
                } else {
                	$unerror = "username already taken" ;
                }
    
            } else {
                $passerror = "password and confirm password doesn't match" ;
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
	<h3 style="margin: 0px;">Sign Up :</h3>
	<form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']) ?>">
	    <input type="text" name="username" placeholder="username.." value="<?php echo $un ?>" onkeyup="getUsernames(this.value)"> <span class="imp"><?php echo "* $unerror" ?></span><br>
        <input type="password" name="password" placeholder="password.."> <span class="imp"><?php echo "* $passerror" ?></span><br>
		<input type="password" name="cPassword" placeholder="confirm password.."> <span class="imp"><?php echo "*" ?></span><br>
		<input type="submit" value="Sign up" > <span class="imp"><?php echo "* required" ?></span>
	</form>
    <hr>
    <button onclick="gotologinpage()">Go to Log in</button><br>
    <hr>
    <p>username availability : <span id="usernames"></span></p>
    <hr>
    <?php echo $success ?>
    <script type="text/javascript">
        function gotologinpage() {
            window.location.assign("loginpage.php") ;
        }
        function getUsernames(uName) {
            xhttp = new XMLHttpRequest() ;
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("usernames").innerHTML = this.responseText ;
                }
            }
            xhttp.open("GET" , "getusernameavailability.php?uName="+uName , true) ;
            xhttp.send() ;
        }
    </script>
	</body>
</html>

