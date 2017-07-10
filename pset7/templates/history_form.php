
<p id = "hello" > 
    Hello, <strong><?=$username?></strong> ! Your current ballance is $<strong><?=number_format($cash, 2)?></strong> .
    
    
</p >
<br>
<br>
<p id="history">
    <strong>YOUR TRANSACTION LOG :</strong>
</p>
<br>

<table id = "portfolio">
        <tr >
            <th>Transaction</th>
            <th>Date and time of 
            the transaction</th>
            <th>Symbol</th>
            
            <th>Shares Sold/Bought</th>
            <th>Price per share</th>
            
            
        </tr>
        
       
        <?php

        foreach ($rows as $row)
        {
            print("<tr>");
            print("<td>" . $row["action"] . "</td>");
            print("<td>" . $row["date"] . "</td>");
            print("<td>" . $row["symbol"] . "</td>");
            
            print("<td>" . $row["share"] . "</td>");
            print("<td>" . "$". number_format($row["price"], 2) . "</td>");
            
            
            print("</tr>");
        }

        ?>
        
        
       
        
    </table>
