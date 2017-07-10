<?php

    // configuration
    require("../includes/config.php"); 
    
    
    
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
    $cash = query("SELECT cash from users WHERE id = ?", $_SESSION["id"]);
    $cash = $cash[0]["cash"];
    $username = query("SELECT username from users WHERE id = ?", $_SESSION["id"]);
    $username = $username[0]["username"];
   
    
    
    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "positions" => $positions, "cash" => $cash, "username" => $username]);

?>
