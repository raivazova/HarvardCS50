<br>
<br>
<br>
<br>
<br>
<p id = "hello" > 
    Hello, <strong><?=$username?></strong> ! Please choose a simbol to check it's quote.
</p>
<br>
<form action = "quote.php" method = "post" >
    <fieldset>
        <div class="form-group">
            <input class="form-control" name="symbol" placeholder="Symbol" type="text">
        </div>
        <div class="form-group">
            <button type="submit" class= "btn btn-default">Check Quote</button>
        </div>
        

    </fieldset>
</form>

