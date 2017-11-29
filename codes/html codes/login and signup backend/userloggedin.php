<?php  
require "connect_to_database.php" ; 

$snippet = "";
$pasteerror = "" ;
$success = "" ;

$un      = $_SESSION["user"] ;

if ($_SERVER["REQUEST_METHOD"] == "POST") {

	$snippet = $_POST["code"] ;
	$snippet = htmlspecialchars($snippet) ;

	$et = $_POST["expiryTime"] ;
	$pt = $_POST["pastetype"] ;
	
	if ($pt == "private") {
		$uv = "" ;
	} else {
		$uv = $_POST["uservisibility"] ;
	}
	

    if (!empty($snippet)) {

    	if ($et != "never") {
    		$et = date("y-m-d h:i:s",strtotime($et)) ;
    	} else {$et = null ;}

	    $query = "INSERT INTO snippetlist (snippet,username,pastetype,uservisibility,expirytime) VALUES (?,?,?,?,?)" ;
	    $stmt = mysqli_prepare($connection,$query) ;

	    mysqli_stmt_bind_param($stmt,"sssss",$snippet,$un,$pt,$uv,$et) ;
        mysqli_stmt_execute($stmt) ;

        $id = mysqli_insert_id($connection) ;

        $success = "paste created successfully, <a href='displaycode.php?snippetno=$id'>click here</a> view the paste !" ;
    }else{
	    $pasteerror = "paste is empty !" ;
    }
}

?>

<!DOCTYPE html>
<html>
<head>
	<title><?php echo "user : " . $_SESSION["user"] ; ?></title>
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
	<button onclick="logout()">log out</button> <span class="imp"><?php echo "* required" ?></span>
	<br><hr>
	<form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']) ?>">
	    <span class="imp"><?php echo "* $pasteerror" ?></span><br>
		<textarea name="code" rows="30" cols="100" placeholder="paste goes here.."><?php echo $snippet ?></textarea><br>
		<input type="submit" value="create paste" style="margin-right: 50px ;">
		Paste Type : <select name="pastetype">
			<option value="public">Public</option>
			<option value="private" selected>Private</option>
		</select>
		User Visibility : <select name="uservisibility">
			<option value="visible">Visible</option>
			<option value="anonymous" selected>Anonymous</option>
		</select>
		Expiry Time : <select name="expiryTime">
			<option value="never">Never</option>
			<option value="+10 Minutes">10 minutes</option>
			<option value="+1 Hour">1 hour</option>
			<option value="+1 Day">1 Day</option>
			<option value="+1 Week">1 Week</option>
			<option value="+2 Weeks">2 Weeks</option>
			<option value="+1 Month">1 Month</option>
		</select>
	</form><hr>
    <?php echo $success ?>
	<script type="text/javascript">
		function logout() {			    	
			window.location.assign("logout.php") ;
		}
	</script>
</html>