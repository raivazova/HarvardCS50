<div>
<br/>
<br/>
<br/>
<br/>
<p id = "choose" > 
    Please choose which shares you would like to sell !
</p>
<br>
    <table id = "portfolio">
        <tr >
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares Owned</th>
            <th>Current Price per share</th>
            <th>Price Bought</th>
            <th>Profit / Loss per share</th>
            <th>Check to sell shares</th>
            <th>Number of shares</th>
            <th>Submit</th>
        </tr>
        
       
        

        <?php foreach ($positions as $position): ?>
        
            <tr>
                <td><?= $position["symbol"] ?></td>
                <td><?= $position["name"] ?></td>
                <td><?= $position["shares"] ?></td>
                <?php $shares = $position["shares"] ?>
                <?php $symbol = $position["symbol"] ?>
                <td>$<?= number_format($position["cur_price"], 2) ?></td>
                <td>$<?= number_format($position["price_bought"], 2) ?></td>
                <td>$<?= number_format($position["profit"], 2) ?></td>
                <form action="sell.php" method="post">
                <td><input type="checkbox" name="check" value= "<?php echo $symbol; ?>"  >  </td>
                <td><input type="number" step="10" min= "10" max= "<?= $shares ?>" name= "sold"  >  </td>
                <td><input type="submit" value="SELL"></td> 
                </form>
                
            </tr>
            
           
        
       

        <?php endforeach ?>
        
        
       
        
    </table>
</div>
