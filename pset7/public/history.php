<?php
    // configuration
    require("../includes/config.php");
    
    // Query current users shares
    $rows = query("SELECT id, symbol, share, price, date, action FROM history
        WHERE id = ? order by date desc", $_SESSION["id"]);
    
    if (count($rows) == 0)
    {
        apologize("No recorded transactions for this user exist.");
    }
    
    
    $cash = query("SELECT cash from users WHERE id = ?", $_SESSION["id"]);
    $cash = $cash[0]["cash"];
    $username = query("SELECT username from users WHERE id = ?", $_SESSION["id"]);
    $username = $username[0]["username"];
    
    
    // render history
    render("history_form.php", ["title" => "History", "rows" => $rows, "cash" => $cash, "username" => $username]);
?>
