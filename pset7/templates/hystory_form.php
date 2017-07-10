<table id = "portfolio">
        <tr >
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares Sold/Bought</th>
            <th>Price per share</th>
            <th>Date and time of 
            the transaction</th>
            <th>Action</th>
        </tr>
        
       
        <?php

        foreach ($rows as $row)
        {
            print("<tr>");
            print("<td>" . $row["symbol"] . "</td>");
            print("<td>" . $row["name"]. "</td>");
            print("<td>" . $row["shares"] . "</td>");
            print("<td>" . number_format($row["price"], 2) . "</td>");
            print("<td>" . $row["date"] . "</td>");
            print("<td>" . $position["action"] . "</td>");
            print("</tr>");
        }

        ?>
        
        
       
        
    </table>
