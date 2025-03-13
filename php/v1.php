<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <?php
        $a=123;
        $b=345;
        $c=567.5;
        $d='1234567';
  
        echo $a.'<br>';
        echo $b + $c;
        echo "<br>";
        echo $b.';'.$c."<br>";
        echo "suma c i d = ".$c+$d."<br>";
        echo gettype($c);
        echo "<hr>";
        echo gettype($d);
        echo "<hr>";
        echo gettype($a);
        echo "Stałe w PHP <hr>";
        define ('pi',3.141592);
        echo "Pole koła o promieniu 12 = ".pi*144;
        echo "<hr>";
        echo gettype(pi)

    ?>
    
</body>
</html>