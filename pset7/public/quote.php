<?php
    // configuration
    require("../includes/config.php");
    
     // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $username = query("SELECT username from users WHERE id = ?", $_SESSION["id"]);
        $username = $username[0]["username"];
        // else render form
        render("quote_form.php", ["title" => "Quote", "username" => $username]);
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
        
        
        render("stock_price.php", ["name" => $s["name"], "symbol" => $s["symbol"], "price" => $s["price"]]);
    }
?>
