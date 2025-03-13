<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        $t1='ala ma kota';
        echo "tekst to $t1:";
        echo "<hr>";
        $t2='ula ma chomika';
        $t3=$t1.$t2;
        echo $t3;
        echo "<hr>";
        echo 'tekst ma '.strlen($t3).'znaków<br>';
        echo 'Pierwszy znak to : '.$t3[0].'<br>';
        echo 'Ostatni znak to : '.$t3[strlen($t3)-1].'<br>';
        echo "<hr>";
        $t4=$t1;
        $t4.='php';
        echo "$t4"."<br>";
        echo "$t1";
        echo "<hr>";
        for($i=0;$i>256;$i++){
            echo chr($i).", ";
        }
        echo "<hr>";
        $tab=["a","A","¹","¥","ê","Ê","œ","Œ"];
        foreach($tab as $b){
            echo $b."----->".ord($b)."<br>";
        }
        echo "<hr>";
        echo is_string($t4);
        echo is_string($tab);
        $licz1=15;
        $licz2=18;
        $licz3=$licz1+$licz2;
        echo "<br>$licz3<br>";
        $t5=strval($licz2);
        echo is_string($t5)."<br>";
        echo "<hr>";
        echo str_replace(" ","_",$t1);
        print_r($tab1);
        echo "<hr>";
        $tab2=explode(' ',$t1);
        print_r($tab2);




    ?>
</body>
</html>