<?php

$dane = file('dane1.txt', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);


$suma = 0;
$liczba = 0;
$maxPole = -INF;
$minPole = INF;
$czestotliwosc = [];

foreach ($dane as $wiersz) {
    
    $wymiary = explode(';', $wiersz);
    
    
    $pole = $wymiary[0] * $wymiary[1];
    
    $suma += $pole;
    $liczba++;
    $maxPole = max($maxPole, $pole);
    $minPole = min($minPole, $pole);
    
    if (!isset($czestotliwosc[$pole])) {
        $czestotliwosc[$pole] = 0;
    }
    $czestotliwosc[$pole]++;
}

$srednia = $suma / $liczba;

$maxCzestotliwosc = max($czestotliwosc);
$najczestszePola = array_keys($czestotliwosc, $maxCzestotliwosc);

echo "Suma pól: $suma\n"."<br>";
echo "Średnia pól: $srednia\n"."<br>";
echo "Największe pole: $maxPole\n"."<br>";
echo "Najmniejsze pole: $minPole\n"."<br>";
echo "Najczęstsze pola: " . implode(', ', $najczestszePola) . " (wystąpiło $maxCzestotliwosc razy)\n"."<br>";
?>
