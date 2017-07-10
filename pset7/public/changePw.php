<?php


     // configuration
    require("../includes/config.php"); 
    
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $query=query( "SELECT* FROM users WHERE id=?", $_SESSION["id"]);
        $query=$query[0];
        render("changePw-form.php",["title" => "Change Password", "username"=>$query["username"]]);
        
    }
    else if($_SERVER["REQUEST_METOD"] == "POST")
    {
        $query=query( "SELECT* FROM users WHERE id=?", $_SESSION["id"]);
        $query=$query[0];
        
        if(empty($_POST["username"]))
        {
            apologize("You must provide your username!");
        }
        
         if(empty($_POST["oldpassword"]))
        {
            apologize("You must provide your current password!");
        }
         if(empty($_POST["password"]))
        {
            apologize("You must provide your new password!");
        }
         if(empty($_POST["confirm"]))
        {
            apologize("You must confirm your new password!");
        }
        if($_POST["username"] != $query["username"])
        {
            apologize("Please enter your valid username !");
        }
        if(crypt($_POST["oldpassword"]) != $query["hash"] )
        {
            apologize("The password you provided did not match your current password!");
        }
        if($_POST[" password"] != $_POST[" oldpassword"]) 
        {
            apologize("Your passwords do not match");
        }
        
        $query=query("UPDATE users SET hash = ? WHERE id=?", crypt($_POST["password"], $_SESSION["id"]));
        
        echo("You changed your password successfuly");
        
        redirect("/");
    }
 ?>
        
        
        
        
            
        
          
    
