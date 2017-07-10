<?php

    // configuration
    require("../includes/config.php");


    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must enter username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must enter password.");
        }
        else if ($_POST["password"] != $_POST["confirmation"])
        {
            apologize("The passwords do not match !");
           
        }
        $new_user = query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"]));
        if( $new_user === false)
        {
            apologize("The username already exists. Please try again !");
                
                
        }
           
        $rows = query("SELECT LAST_INSERT_ID() AS id");
        $id = $rows[0]["id"];
        $_SESSION["id"] = $id;
        
        
        redirect("index.php");
           
        
       
    }

?>
