<div id = change>
    Hello, <b><?= $username ?></b>!
    <br/>
    Please use the form below to change your password !
</div>
</br>
 <div data-role="popup" id="myPopup" class="ui-content" style="min-width:250px;">
    <form action = "changePw.php" method = "POST" >
        <div class="form-group">
                <input class="form-control" name="username" placeholder="Username" type="text">
        </div>
        <div class="form-group">
                <input class="form-control" name="oldpassword" placeholder="Your current password" type="text">
        </div>
        <div class="form-group">
                <input class="form-control" name="password" placeholder="New Password" type="text">
        </div>
        <div class="form-group">
                <input class="form-control" name="confirm" placeholder="Confirm password" type="text">
        </div>
        <div class="form-group">
                <button type="submit" name="change"  class= "btn btn-default"> Change</button>
            </div>
    </form>
  </div>

