<br>
<br>
<br><p id = "hello" > 
    Hello, <strong><?=$username?></strong> ! Your current ballance is $<strong><?=number_format($cash, 2)?></strong> .
</p>
<br>
<br>
<br>
<table id = "portfolio">
        <tr >
            <th>Symbol</th>
            <th>Shares</th>
            <th>Check Price per share</th>
            <th>Current Price per share</th>
            <th>Calculate price</th>
            <th>Price for package</th>
            <th>Buy</th>
            
        </tr>
        
    <form action = "buy.php" method = "post" >
        <fieldset>
           <td> <div class="form-group">
                <input class="form-control" name="symbol" placeholder="Symbol" type="text">
            </div></td>
            <td><div class="form-group">
                <input class="form-control" name="shares" placeholder="Shares" type="number" step="10">
            </div></td>
            <td><div class="form-group">
                <button type="submit" name="buy" value="check pps" class= "btn btn-default">Check PPS</button>
            </div></td> 
            <td>$<?= number_format($pps, 2) ?> </td>
            <td><div class="form-group">
                <button type="submit" name="buy" value = "calculate"class= "btn btn-default">Calculate</button>
            </div></td> 
             <td>$<?= number_format($calculate, 2) ?> </td>
           <td> <div class="form-group">
                <button type="submit" name="buy" value= "buy" class= "btn btn-default"> Buy</button>
            </div></td>
            

        </fieldset>
    </form>
</table>
