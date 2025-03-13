<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>xpp</title>
</head>
<body>
    <?php
    $tu=scandir("./.");
    foreach($tu as $t){
        echo $t."<br>";
    }
    
    ?>
    <form action="" method="post">
        podaj nazwe folderu: <input type="text" name="nazwa_fol"><br>
        <input type="submit" value="twórz katalog">
    </form>
    <?php
        $fol=$_POST['nazwa_fol'];
        if(!is_dir($fol)){
            mkdir($fol);
        }
        else{
            echo $t." już istnieje <br>";
        }
    ?>
    <form action="" method="post">
        podaj nazwe folderu: <input type="text" name="nazwa_usu"><br>
        <input type="submit" value="usun katalog">
    </form>
    <?php
        $fol=$_POST['nazwa_usu'];
        if(!is_dir($fol)){
            rmdir($fol);
        }
        else{
            echo $t." taki folder nie istnieje <br>";
        }
    ?>
     <form action="" method="post">
        podaj nazwe pliku: <input type="text" name="nazwa_plik"><br>
        <input type="submit" value="Twórz plik">
    </form>
    <?php
        $fol=$_POST['nazwa_plik'];
        if(!is_file($fol)){
            $a=fopen($fol,"w");
            fclose($a);
        }
        else{
            echo " taki folder nie istnieje <br>";
        }
    ?>
</body>
</html>