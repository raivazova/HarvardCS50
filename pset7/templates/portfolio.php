 <div>


<br>
<br>
<p id = "hello" > 
    Hello, <strong><?=$username?></strong> ! Your current ballance is $<strong><?=number_format($cash, 2)?></strong> .
</p>
<br/>
<div id="cpw">
    For security reasons we recommend that you <a id="lpw"href="changePw.php">change your password</a> on regular basis !
</div>
<br>
    <table id = "portfolio">
        <tr >
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares Owned</th>
            <th>Current Price per share</th>
            <th>Last Price Bought</th>
            <th>Profit / Loss per share</th>
        </tr>
        
       
        <?php

        foreach ($positions as $position)
        {
            print("<tr>");
            print("<td>" . $position["symbol"] . "</td>");
            print("<td>" . $position["name"]. "</td>");
            print("<td>" . $position["shares"] . "</td>");
            print("<td>" . "$" .number_format($position["cur_price"], 2) . "</td>");
            print("<td>" . "$" .number_format($position["price_bought"], 2) . "</td>");
            print("<td>" . "$" .number_format($position["profit"], 2) . "</td>");
            print("</tr>");
        }

        ?>
        
        
       
        
    </table>
</div>
<br>
<div>
    <iframe frameborder="0" scrolling="no" height="381" width="559" allowtransparency="true" marginwidth="0" marginheight="0" 
    src="http://eqrates.investing.com/index.php?pairs_ids=277;347;6408;474;243;282;346;260;271;26490;8193;6369;280;251;8082;252;
    &header-text-color=%23FFFFFF&curr-name-color=%230059b0&inner-text-color=%23000000&green-text-color=%232A8215&green-background=%23B7F4C2&red-
    text-color=%23DC0001&red-background=%23FFE2E2&inner-border-color=%23CBCBCB&border-color=%23cbcbcb&bg1=%23F6F6F6&bg2=%23ffffff&last_update=hide">
    </iframe>
    <div style="width:559px;"><span><span style="font-size: 11px;color: #333333;text-decoration: none;">Leading Stock Quotes powered by 
    <a href="http://www.investing.com/" rel="nofollow" target="_blank" style="font-size: 11px;color: #06529D; font-weight: bold;" class="underline_link">
    Investing.com</a></span></span></div>
</div>

