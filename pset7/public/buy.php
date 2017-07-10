<?php
    // configuration
    require("../includes/config.php");
    $s = 0;
    $calculate = 0;
    $cash = query("SELECT cash from users WHERE id = ?", $_SESSION["id"]);
    $cash = $cash[0]["cash"];
    $username = query("SELECT username from users WHERE id = ?", $_SESSION["id"]);
    $username = $username[0]["username"];
     // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", [ "title" => "Buy",  "cash" => $cash, 
        "username" => $username, "calculate" => $calculate, "pps" => $s["price"]]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $symbol = $_POST["symbol"];
        if(empty($symbol))
        {
            apologize("You must enter a valid stock symbol!");
        }
        $s = lookup($symbol);
        
        
        if($s === false)
        {
            apologize("Invalid symbol");
        }
        $shares = $_POST["shares"];
        if(empty($shares))
        {
            apologize("You must enter a valid number of shares!");
        }
        $valid = preg_match("/^\d+$/", $_POST["shares"]);
        if($valid === false)
        {
            apologize("You must enter a valid number of shares!");
        }
        
        if($_POST["buy"] == "calculate")
        {
            $calculate = $s["price"] * $shares;
            render("buy_form1.php", [ "title" => "Buy",  "cash" => $cash, 
            "username" => $username, "name" => $symbol, "number" => $shares, 
            "calculate" => $calculate, "pps" => $s["price"]]);
            
        }
        else if($_POST["buy"] == "check pps")
        {
             
            render("buy_form2.php", [ "title" => "Buy",  "cash" => $cash, 
            "username" => $username, "name" => $symbol, "number" => $shares, 
            "calculate" => $calculate, "pps" => $s["price"]]);
           
        }
        else 
        {
            $insert= query("INSERT INTO portfolio (id, symbol, shares) VALUES(?, ?, ?) 
            ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", 
            $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"]);
            
            if($insert === false)
            {
                apologize("There was a problem while buying your shares");
            }
            
            $update = query("UPDATE users SET cash = cash - ? WHERE id = ?", 
            $s["price"] * $shares, $_SESSION["id"]);
            
            if($update === false)
            {
                apologize("There was a problem while buying your shares");
            }
            
            $price = query("UPDATE portfolio SET price = ? WHERE id = ? and symbol = ?", 
            $s["price"], $_SESSION["id"], $_POST["symbol"]);
            
            // history log  
            query("INSERT INTO history (id, symbol, share, price, date, action) VALUES(?, ?, ?, ?, now(), 'BUY' )",$_SESSION["id"],
            strtoupper($_POST["symbol"]), $_POST["shares"], number_format($s["price"], 2)); 
            
            
            redirect("/");
        }
        
    }
?>
