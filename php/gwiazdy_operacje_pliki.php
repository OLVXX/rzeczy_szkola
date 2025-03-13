<?php

$tekst = file_get_contents('artykul.txt');


preg_match_all('/<h1>(.*?)<\/h1>/', $tekst, $tytuly);
$ile_tytulow = count($tytuly[0]);

$puste_linie = preg_match_all("/(^[\r\n]*|[\r\n]+)[\s\t]*[\r\n]+/", $tekst);


$niepuste_linie = count(preg_split('/$\R?^/m', $tekst)) - $puste_linie;


preg_match_all('/\[\d+\]/', $tekst, $przypisy);
$ile_przypisow = count($przypisy[0]);

$ile_gwiazda1 = substr_count($tekst, 'gwiazda ');
$ile_gwiazda2 = substr_count($tekst, 'gwiazda.');
$ile_gwiazda3 = substr_count($tekst, 'gwiazda,');
$ile_gwiazda4 = substr_count($tekst, '"gwiazda"');
$ile_gwiazda_suma = $ile_gwiazda1+$ile_gwiazda2+$ile_gwiazda3+$ile_gwiazda4;

$ile_Gwiazda = substr_count($tekst, 'Gwiazda');

$ile_kropek = substr_count($tekst, '.');

$zagadnienia = preg_split('/<h1>.*?<\/h1>/', $tekst);
array_shift($zagadnienia); 
$linie_zagadnien = array_map(function($zagadnienie) {
    return count(preg_split('/$\R?^/m', $zagadnienie));
}, $zagadnienia);


$odpowiedzi = "Ilość tytułów zagadnień: $ile_tytulow\n".
              "Ilość pustych linii: $puste_linie\n".
              "Ilość niepustych linii: $niepuste_linie\n".
              "Ilość przypisów: $ile_przypisow\n".
              "Ilość słowa 'gwiazda': $ile_gwiazda_suma\n".
              "Ilość słowa 'Gwiazda': $ile_Gwiazda\n".
              "Ilość kropek: $ile_kropek\n".
              "Ilość linii każdego zagadnienia:\n";

foreach ($tytuly[1] as $i => $tytul) {
    $odpowiedzi .= "$tytul – {$linie_zagadnien[$i]}\n";
}
file_put_contents('odpowiedzi.txt', $odpowiedzi);
?>
