<!DOCTYPE html>

<html>

    <head>

        <link href="/css/bootstrap.min.css" rel="stylesheet"/>
        <link href="/css/bootstrap-theme.min.css" rel="stylesheet"/>
        <link href="/css/styles.css" rel="stylesheet"/>
        <link rel="icon" href="img/money.ico" type="image/x-icon">

        <?php if (isset($title)): ?>
            <title>C$50 Finance: <?= htmlspecialchars($title) ?></title>
        <?php else: ?>
            <title>C$50 Finance</title>
        <?php endif ?>

        <script src="/js/jquery-1.11.1.min.js"></script>
        <script src="/js/bootstrap.min.js"></script>
        <script src="/js/scripts.js"></script>

    </head>

    <body>

        <div class="container">
            <br>
            <br>
            
            <div id="top">
                <a href="/"><img alt="C$50 Finance" src="/img/newest.gif"/></a>
            </div>

            <div id="middle">
           
            <br>
            <br>
            <div id = "links">
                <a id = "quote" href="quote.php"><strong>QUOTE</strong></a>
                <a id = "buy"href="buy.php"><strong>BUY</strong></a>
                <a id = "sell"href="sell.php"><strong>SELL</strong></a>
                <a id = "hist"href="history.php"><strong>HISTORY</strong></a>
                <a id = "log"href="logout.php"><strong>LOG OUT</strong></a>
            </div>
