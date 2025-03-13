<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <form name="wczyt1" action="" method="post">

        <label> Wartość 1: </label><input type="text" name="w1" value="0"></label><br>
        <label> Wartość 2: </label><input type="text" name="w2" value="0"></label><br>
        <input type="submit" value="Oblicz">


    </form>
    <?php
    
        $x=$_POST['w1'];
        $y=$_POST['w2'];
        echo "Suma wynosi " .$x+$y;
    ?>
    
</body>
</html>