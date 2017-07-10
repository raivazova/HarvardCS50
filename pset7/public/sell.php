<?php

    // configuration
    require("../includes/config.php"); 
     // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $rows = query("SELECT symbol, shares, price FROM portfolio WHERE id = ?", $_SESSION["id"]);
        $positions = [];
        foreach ($rows as $row)
        {
            $stock = lookup($row["symbol"]);
            if ($stock !== false)
            {
                $positions[] = [
                    "name" => $stock["name"],
                    "cur_price" => $stock["price"],
                    "price_bought" => $row["price"],
                    "profit" => $stock["price"] - $row["price"],
                    "shares" => $row["shares"],
                    "symbol" => $row["symbol"]
                ];
            }
        }
        
        render("sell_form.php", ["title" => "Sell shares", "positions" => $positions]);
    }
    
    
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        if(empty($_POST["check"]))
        {
           apologize("You must select which shares you want to sell !");
            
        }
        $shares_owned= query("SELECT shares FROM portfolio WHERE id = ? and symbol = ?", 
        $_SESSION["id"], strtoupper($_POST["check"]));
        $shares_owned = $shares_owned[0]["shares"];
        
        // update shares
        $query= query("UPDATE portfolio SET shares = shares - ? WHERE id = ? AND symbol = ?", 
        $_POST["sold"], $_SESSION["id"], strtoupper($_POST["check"]));
        
        if($query === false)
        {
            apologize("There was a problem while selling your shares");
        }
        $share_sold=lookup($_POST["check"]);
        $income = $share_sold["price"] * $shares_owned;
        
        // update cash
        $query= query("UPDATE users SET cash = cash + $income WHERE id = ?", $_SESSION["id"]);
        if($query === false)
        {
            apologize("There was a problem while selling your shares");
        }  
        // history log  
        query("INSERT INTO history (id, symbol, share, price, date, action) VALUES(?, ?, ?, ?, now(), 'SELL' )",$_SESSION["id"],
        strtoupper($share_sold["symbol"]), $_POST["sold"], number_format($share_sold["price"], 2)); 
            
        
        
        $username = query("SELECT username from users WHERE id = ?", $_SESSION["id"]);
        $username = $username[0]["username"];
        $cash = query("SELECT cash from users WHERE id = ?", $_SESSION["id"]);
        $cash = $cash[0]["cash"];
        
        // render sold
        render("sold.php", ["title" => "Sold shares",  "amount" => $_POST["sold"], 
        "sold_name" => $share_sold["name"], "sold_price" => $share_sold["price"], 
        "income" => number_format($income, 2), "username" => $username, "cash" => number_format($cash, 2)]);
    }

    
    
?>
