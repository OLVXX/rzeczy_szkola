<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>v4</title>
</head>
<body>
    

        <form action="" method="post">
            Liczba 1: <input type="text" name="w1"><br>
            Liczba 2: <input type="text" name="w2"><br>
            <input type="submit" value="Oblicz">

        </form>

        <?php
        if(!empty($_POST['w1']  && !empty($_POST['w2']) ))
        if(is_numeric($_POST['w1']) && is_numeric($_POST['w2'])){
            $w1=$_POST['w1'];
            $w2=$_POST['w2'];
            if($w1>0 && $w2>0){
                echo "suma wynosi : ".$w1+$w2."<br>";
            }
            else{
                echo "Jedna z liczb jest ujemna"."<br>";
            }
        }
        
        else{
            echo "To nie są liczby";
        }
        else{
            echo "Jedno z pól jest puste "."<br>";
        }

        
        
        ?>
        <br>
        <br>
        <br>
        <form action="" method="post">
            <input type="radio" name="r" value="Arial">Arial<br>
            <input type="radio" name="r" value="Times New Roman">Times New Roman<br>
            <input type="radio" name="r" value="Calibri" checked>Calibri<br>
            <input type="submit" value="Wybierz czcionke" name="p1">
        </form>
        
        <?php
        if(isset($_POST['p1'])){
            $cz=$_POST['r'];
            echo "Wybrano czcionke : ".$cz."<br>";
        }
            
        
        ?>
        
    </body>
</html>