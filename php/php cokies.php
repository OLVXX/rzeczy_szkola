
<?php
setcookie('odwiedziny', time(), time() + 3600*24);
if(isset($_COOKIE['odwiedziny'])){
echo("Odwiedzono w ciągu ostatniej doby");
echo("date('d.m.Y, H:i:s',$_COOKIE['odwiedziny']));
}
else{
echo("Jesteś po raz pierwszy na stronie");
}
?>
setcookie('odwiedziny',’’, time() - 3600);

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<?php
$login = $_POST['login'];
$haslo = $_POST['haslo'];
if (($login=='admin' && $haslo=='1234') || $_COOKIE['zalogowano']==1)
{
setcookie('zalogowano', '1');
echo('<br><br><h1>Czesc admin!</h1>');
} else
{
setcookie('zalogowano', '0');
echo('<br><br><h1>Nie zalogowano!</h1>');
}
?>
<html>
<head>
</head>
<body>
<form action="" method="post">
Login: <input type="text" name="login">
Haslo: <input type="password" name="haslo">
<input type="submit">
</form>
</body>
<?php
if (isset($_COOKIE['ile'])) {
 $ile = $_COOKIE['ile'] + 1;
} else {
 $ile = 1;
}
setcookie('ile', $ile, time()+10);
if (isset($_COOKIE['ile'])) {
 echo $_COOKIE['ile'];
} else {
 echo "Brak ";
}
?>
<?php
$tab = ['ala' => 'pies', 'ula' => 'kot', 'ela' => 'rybki'];
setcookie('imiona', serialize($tab), time()+10);
if (isset($_COOKIE['imiona'])){
 $tab1 = unserialize($_COOKIE['imiona']);
}
else {
 $tab1 = [];
 }
foreach($tab1 as $i => $z){
echo $i. "====>".$z."<br>";
}
?>

</html>
